// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

package com.gulden.jniunifiedbackend;

public final class AddressRecord implements android.os.Parcelable {


    /*package*/ final String mAddress;

    /*package*/ final String mName;

    /*package*/ final String mDescription;

    /*package*/ final String mPurpose;

    public AddressRecord(
            String address,
            String name,
            String description,
            String purpose) {
        this.mAddress = address;
        this.mName = name;
        this.mDescription = description;
        this.mPurpose = purpose;
    }

    public String getAddress() {
        return mAddress;
    }

    public String getName() {
        return mName;
    }

    public String getDescription() {
        return mDescription;
    }

    public String getPurpose() {
        return mPurpose;
    }

    @Override
    public String toString() {
        return "AddressRecord{" +
                "mAddress=" + mAddress +
                "," + "mName=" + mName +
                "," + "mDescription=" + mDescription +
                "," + "mPurpose=" + mPurpose +
        "}";
    }


    public static final android.os.Parcelable.Creator<AddressRecord> CREATOR
        = new android.os.Parcelable.Creator<AddressRecord>() {
        @Override
        public AddressRecord createFromParcel(android.os.Parcel in) {
            return new AddressRecord(in);
        }

        @Override
        public AddressRecord[] newArray(int size) {
            return new AddressRecord[size];
        }
    };

    public AddressRecord(android.os.Parcel in) {
        this.mAddress = in.readString();
        this.mName = in.readString();
        this.mDescription = in.readString();
        this.mPurpose = in.readString();
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(android.os.Parcel out, int flags) {
        out.writeString(this.mAddress);
        out.writeString(this.mName);
        out.writeString(this.mDescription);
        out.writeString(this.mPurpose);
    }

}
