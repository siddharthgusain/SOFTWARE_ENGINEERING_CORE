package com.payment.models;

// Class to represent User Context
public class UserContext {
    private boolean isUPIEnabled;

    public UserContext(boolean isUPIEnabled) {
        this.isUPIEnabled = isUPIEnabled;
    }

    public boolean isUPIEnabled() {
        return isUPIEnabled;
    }
}
