package com.payment.strategy;

import com.payment.models.PaymentInstrument;
import com.payment.models.UserContext;
import com.payment.models.Cart;

public interface PaymentValidationStrategy {
    boolean isValid(PaymentInstrument instrument, UserContext userContext, Cart cart);
}
