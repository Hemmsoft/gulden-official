package com.gulden.unity_wallet.util

import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.gulden.unity_wallet.*
import kotlinx.coroutines.*
import kotlin.coroutines.CoroutineContext

abstract class AppBaseActivity : AppCompatActivity(), CoroutineScope {

    /**
     * Called when walletReady is completed, but always after onResume
     * This can be used instead of using the walletReady deferred to simplify code.
     * Do NOT call the super method.
     */
    open fun onWalletReady() {}

    /**
     * Called when a wallet needs to be created. This is linked to the core notifyInitWithoutExistingWallet event.
     * This is always called after onResume.
     * The default behaviour will either continue to the welcome or upgrade activity,
     * when overriding this you should normally NOT CALL the super method.
     */
    open fun onWalletCreate() {
        welcomeOrUpgrade()
    }

    override val coroutineContext: CoroutineContext = Dispatchers.Main + SupervisorJob()

    override fun onResume() {
        super.onResume()

        // schedule onWalletReady
        launch(Dispatchers.Main) {
            UnityCore.instance.walletReady.invokeOnCompletion { handler ->
                if (handler == null)
                    onWalletReady()
            }
        }

        // schedule onWalletCreate
        launch(Dispatchers.Main) {
            UnityCore.instance.walletCreate.invokeOnCompletion { handler ->
                if (handler == null)
                    onWalletCreate()
            }
        }
    }

    private fun welcomeOrUpgrade() {
        // upgrade old wallet when a protobuf wallet file is present and is not marked as upgraded
        val upgradedMarkerFile = getFileStreamPath(Constants.OLD_WALLET_PROTOBUF_FILENAME+".upgraded")
        if (!upgradedMarkerFile.exists() && getFileStreamPath(Constants.OLD_WALLET_PROTOBUF_FILENAME).exists())
            gotoActivity(UpgradeActivity::class.java)
        else
            gotoActivity(WelcomeActivity::class.java)
    }

    private fun gotoActivity(cls: Class<*> )
    {
        val intent = Intent(this, cls)
        intent.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK or Intent.FLAG_ACTIVITY_CLEAR_TASK)
        startActivity(intent)

        finish()
    }
}
