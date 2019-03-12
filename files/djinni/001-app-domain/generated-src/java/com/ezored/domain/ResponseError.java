// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from proj.djinni

package com.ezored.domain;

public final class ResponseError implements android.os.Parcelable {


    /*package*/ final String mField;

    /*package*/ final String mMessage;

    public ResponseError(
            String field,
            String message) {
        this.mField = field;
        this.mMessage = message;
    }

    public String getField() {
        return mField;
    }

    public String getMessage() {
        return mMessage;
    }

    @Override
    public String toString() {
        return "ResponseError{" +
                "mField=" + mField +
                "," + "mMessage=" + mMessage +
        "}";
    }


    public static final android.os.Parcelable.Creator<ResponseError> CREATOR
        = new android.os.Parcelable.Creator<ResponseError>() {
        @Override
        public ResponseError createFromParcel(android.os.Parcel in) {
            return new ResponseError(in);
        }

        @Override
        public ResponseError[] newArray(int size) {
            return new ResponseError[size];
        }
    };

    public ResponseError(android.os.Parcel in) {
        this.mField = in.readString();
        this.mMessage = in.readString();
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(android.os.Parcel out, int flags) {
        out.writeString(this.mField);
        out.writeString(this.mMessage);
    }

}
