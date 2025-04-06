package com.payment.factory;

import com.payment.enums.LineOfBusiness;
import com.payment.strategy.*;

public class PaymentValidationStrategyFactory {
    public static PaymentValidationStrategy getValidationStrategy(LineOfBusiness lineOfBusiness) {
        switch (lineOfBusiness) {
            case CREDIT_CARD_BILL_PAYMENT:
                return new CreditCardBillPaymentValidation();
            case COMMERCE:
                return new CommerceValidation();
            case INVESTMENT:
                return new InvestmentValidation();
            default:
                throw new IllegalArgumentException("Unknown line of business: " + lineOfBusiness);
        }
    }
}
