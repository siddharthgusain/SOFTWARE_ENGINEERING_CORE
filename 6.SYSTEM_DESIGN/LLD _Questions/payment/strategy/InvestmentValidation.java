package com.payment.strategy;

import com.payment.enums.PaymentInstrumentType;
import com.payment.models.Cart;
import com.payment.models.PaymentInstrument;
import com.payment.models.UserContext;

public class InvestmentValidation implements PaymentValidationStrategy {
    @Override
    public boolean isValid(PaymentInstrument instrument, UserContext userContext, Cart cart) {
        return instrument.getType() != PaymentInstrumentType.CREDIT_CARD && validateTransactionLimits(instrument, userContext, cart);
    }

    private boolean validateTransactionLimits(PaymentInstrument instrument, UserContext userContext, Cart cart) {
        if (instrument.getType() == PaymentInstrumentType.UPI && !userContext.isUPIEnabled()) {
            return false;
        }
        // Additional transaction limit logic can go here
        return true;
    }
}
