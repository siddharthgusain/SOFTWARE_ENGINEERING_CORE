package com.payment.service;

import com.payment.models.*;
import com.payment.strategy.PaymentValidationStrategy;
import com.payment.factory.PaymentValidationStrategyFactory;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class PaymentRecommendationService {
    public List<PaymentInstrument> recommendPayments(User user, Cart cart) {
        PaymentValidationStrategy validationStrategy = PaymentValidationStrategyFactory.getValidationStrategy(cart.getLineOfBusiness());

        List<PaymentInstrument> filteredInstruments = new ArrayList<>();
        for (PaymentInstrument pi : user.getPaymentInstruments()) {
            if (validationStrategy.isValid(pi, user.getUserContext(), cart)) {
                filteredInstruments.add(pi);
            }
        }

        filteredInstruments.sort((pi1, pi2) -> Double.compare(pi2.getRelevanceScore(), pi1.getRelevanceScore()));
        return filteredInstruments;
    }
}
