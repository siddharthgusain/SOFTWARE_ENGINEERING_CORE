package com.payment;

import com.payment.enums.LineOfBusiness;
import com.payment.enums.PaymentInstrumentType;
import com.payment.models.Cart;
import com.payment.models.PaymentInstrument;
import com.payment.models.User;
import com.payment.models.UserContext;
import com.payment.service.PaymentRecommendationService;

import java.util.*;



public class Client {
    public static void main(String[] args) {
        UserContext userContext = new UserContext(true);
        List<PaymentInstrument> instruments = Arrays.asList(
                new PaymentInstrument("1", PaymentInstrumentType.UPI, "HDFC", 0.9),
                new PaymentInstrument("2", PaymentInstrumentType.DEBIT_CARD, "SBI", 0.8),
                new PaymentInstrument("3", PaymentInstrumentType.CREDIT_CARD, "ICICI", 0.7)
        );

        User user = new User("user123", userContext, instruments);
        Cart cart = new Cart(LineOfBusiness.COMMERCE, 1500);

        PaymentRecommendationService service = new PaymentRecommendationService();
        List<PaymentInstrument> recommendations = service.recommendPayments(user, cart);

        recommendations.forEach(System.out::println);
    }
}
