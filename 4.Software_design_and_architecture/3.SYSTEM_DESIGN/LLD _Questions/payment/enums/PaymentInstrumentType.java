package com.payment.enums;

public enum PaymentInstrumentType {
    CREDIT_CARD("Credit Card"),
    DEBIT_CARD("Debit Card"),
    UPI("UPI"),
    NET_BANKING("Net Banking");

    private final String displayName;

    // Constructor for the enum
    PaymentInstrumentType(String displayName) {
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
