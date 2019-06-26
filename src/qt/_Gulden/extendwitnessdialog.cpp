// Copyright (c) 2016-2019 The Gulden developers
// Authored by: Willem de Jonge (willem@isnapp.nl)
// Distributed under the GULDEN software license, see the accompanying
// file COPYING

#include "extendwitnessdialog.h"
#include <qt/_Gulden/forms/ui_extendwitnessdialog.h>

#include <stdexcept>
#include "wallet/wallet.h"
#include "gui.h"
#include "wallet/witness_operations.h"
#include "units.h"
#include "Gulden/util.h"
#include "walletmodel.h"
#include "optionsmodel.h"

#define LOG_QT_METHOD LogPrint(BCLog::QT, "%s\n", __PRETTY_FUNCTION__)

ExtendWitnessDialog::ExtendWitnessDialog(CAmount lockedAmount_, int durationRemaining, int64_t minimumWeight, WalletModel* walletModel_, const QStyle *_platformStyle, QWidget *parent)
: QFrame( parent )
, ui( new Ui::ExtendWitnessDialog )
, platformStyle( _platformStyle )
, walletModel(walletModel_)
, lockedAmount(lockedAmount_)
{
    ui->setupUi(this);

    // minumium required is tx fee, 1 should do it
    ui->fundingSelection->setWalletModel(walletModel, 1 * COIN);

    connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(cancelClicked()));
    connect(ui->extendButton, SIGNAL(clicked()), this, SLOT(extendClicked()));

    ui->lockDuration->configure(lockedAmount, durationRemaining, minimumWeight);
}

ExtendWitnessDialog::~ExtendWitnessDialog()
{
    delete ui;
}

void ExtendWitnessDialog::cancelClicked()
{
    LOG_QT_METHOD;

    Q_EMIT dismiss(this);
}

void ExtendWitnessDialog::extendClicked()
{
    LOG_QT_METHOD;

    // Format confirmation message
    QString questionString = tr("Are you sure you want to extend the witness?");
    questionString.append("<br /><br />");
    int days = ui->lockDuration->duration() / DailyBlocksTarget();
    questionString.append(tr("%1 will be locked for %2 days (%3).")
                          .arg(GuldenUnits::formatHtmlWithUnit(walletModel->getOptionsModel()->getDisplayUnit(), lockedAmount))
                          .arg(days)
                          .arg(daysToHuman(days)));
    questionString.append("<br /><br />");
    questionString.append(tr("It will not be possible under any circumstances to spend or move these funds for the duration of the lock period."));

    if(QDialog::Accepted == GUI::createDialog(this, questionString, tr("Extend witness"), tr("Cancel"), 600, 360, "ExtendWitnessConfirmationDialog")->exec())
    {
        // selected fundingAccount
        CAccount* fundingAccount = ui->fundingSelection->selectedAccount();
        if (!fundingAccount)
            GUI::createDialog(this, tr("No funding account selected"), tr("Okay"), QString(""), 400, 180)->exec();

        pactiveWallet->BeginUnlocked(_("Wallet unlock required to extend witness"), [=](){

            try {
                LOCK2(cs_main, pactiveWallet->cs_wallet);
                CAccount* witnessAccount = pactiveWallet->activeAccount;
                // TODO: fill actual parameters
                extendwitnessaccount(pactiveWallet,
                                     fundingAccount,
                                     witnessAccount,
                                     lockedAmount, // TODO: add in additional locking amount
                                     ui->lockDuration->duration(),
                                     nullptr, nullptr); // ignore result params

                // request dismissal only when succesful
                Q_EMIT dismiss(this);

            } catch (std::runtime_error& e) {
                GUI::createDialog(this, e.what(), tr("Okay"), QString(""), 400, 180)->exec();
            }

            pactiveWallet->EndUnlocked();
        });
    }
}