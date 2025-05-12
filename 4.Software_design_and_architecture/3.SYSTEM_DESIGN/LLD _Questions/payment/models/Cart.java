package com.payment.models;

import com.payment.enums.LineOfBusiness;

// Class to represent Cart
public class Cart {
    private LineOfBusiness lineOfBusiness;
    private double totalAmount;

    public Cart(LineOfBusiness lineOfBusiness, double totalAmount) {
        this.lineOfBusiness = lineOfBusiness;
        this.totalAmount = totalAmount;
    }

    public LineOfBusiness getLineOfBusiness() {
        return lineOfBusiness;
    }

    public double getTotalAmount() {
        return totalAmount;
    }
}