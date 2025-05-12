package com.payment.enums;

public enum LineOfBusiness {
    CREDIT_CARD_BILL_PAYMENT("Credit Card Bill Payment"),
    COMMERCE("Commerce"),
    INVESTMENT("Investment");

    private final String displayName;

    // Constructor for the enum
    LineOfBusiness(String displayName) {
        this.displayName = displayName;
    }

    // Getter for the display name
    public String getDisplayName() {
        return displayName;
    }

    @Override
    public String toString() {
        return displayName;
    }
}