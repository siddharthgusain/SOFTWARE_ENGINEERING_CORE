package com.payment.models;

import com.payment.enums.PaymentInstrumentType;

// Class to represent a Payment Instrument
public class PaymentInstrument {
    private String id;
    private PaymentInstrumentType type;
    private String issuer;
    private double relevanceScore;

    public PaymentInstrument(String id, PaymentInstrumentType type, String issuer, double relevanceScore) {
        this.id = id;
        this.type = type;
        this.issuer = issuer;
        this.relevanceScore = relevanceScore;
    }

    public PaymentInstrumentType getType() {
        return type;
    }

    public double getRelevanceScore() {
        return relevanceScore;
    }

    @Override
    public String toString() {
        return "PaymentInstrument{" +
                "id='" + id + '\'' +
                ", type=" + type +
                ", issuer='" + issuer + '\'' +
                ", relevanceScore=" + relevanceScore +
                '}';
    }
}