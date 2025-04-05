package com.couponManagement;

import java.util.*;

class Coupon {
    String categoryName;
    String couponName;
    Date dateModified;
    String discount;

    public Coupon(String categoryName, String couponName, String dateModified, String discount) {
        this.categoryName = categoryName;
        this.couponName = couponName;
        this.dateModified = parseDate(dateModified);
        this.discount = discount;
    }

    private Date parseDate(String date) {
        try {
            return new java.text.SimpleDateFormat("yyyy-MM-dd").parse(date);
        } catch (Exception e) {
            return new Date(0); // Fallback to epoch if parsing fails
        }
    }
}

class Category {
    String categoryName;
    String parentCategoryName;

    public Category(String categoryName, String parentCategoryName) {
        this.categoryName = categoryName;
        this.parentCategoryName = parentCategoryName;
    }
}

class Product {
    String productName;
    double price;
    String categoryName;

    public Product(String productName, String price, String categoryName) {
        this.productName = productName;
        this.price = Double.parseDouble(price);
        this.categoryName = categoryName;
    }
}

class CategoryCouponResolver {
    private final Map<String, List<Coupon>> categoryCoupons = new HashMap<>();
    private final Map<String, String> categoryHierarchy = new HashMap<>();
    private final Map<String, String> bestCouponForCategory = new HashMap<>();

    public CategoryCouponResolver(String[][] coupons, String[][] categories) {
        // Load categories
        for (String[] category : categories) {
            categoryHierarchy.put(category[0], category[1]);
        }

        // Load coupons
        for (String[] coupon : coupons) {
            String category = coupon[0];
            categoryCoupons
                    .computeIfAbsent(category, k -> new ArrayList<>())
                    .add(new Coupon(coupon[0], coupon[1], coupon[2], coupon[3]));
        }

        // Precompute the best coupon for each category
        for (String category : categoryCoupons.keySet()) {
            bestCouponForCategory.put(category, getBestCouponForCategory(category));
        }
    }

    private String getBestCouponForCategory(String categoryName) {
        // Traverse up the hierarchy to find the first category with a coupon
        while (categoryName != null) {
            List<Coupon> coupons = categoryCoupons.get(categoryName);
            if (coupons != null && !coupons.isEmpty()) {
                Coupon bestCoupon = null;
                for (Coupon coupon : coupons) {
                    if (coupon.dateModified.after(new Date())) continue; // Skip future dates
                    if (bestCoupon == null || coupon.dateModified.after(bestCoupon.dateModified)) {
                        bestCoupon = coupon;
                    }
                }
                if (bestCoupon != null) {
                    return bestCoupon.couponName;
                }
            }
            categoryName = categoryHierarchy.get(categoryName);
        }
        return null; // No coupon found in the hierarchy
    }

    public String findBestCoupon(String categoryName) {
        return bestCouponForCategory.getOrDefault(categoryName, null);
    }

    public String calculateDiscountedPrice(String productName, String[][] products) {
        // Create a map of products for quick lookups
        Map<String, Product> productMap = new HashMap<>();
        for (String[] product : products) {
            productMap.put(product[0], new Product(product[0], product[1], product[2]));
        }

        Product product = productMap.get(productName);
        if (product == null) return null;

        String bestCoupon = findBestCoupon(product.categoryName);
        if (bestCoupon == null) return String.format("%.2f", product.price);

        // Find the coupon for the product's category and apply the discount
        List<Coupon> coupons = categoryCoupons.get(product.categoryName);
        if (coupons == null) return String.format("%.2f", product.price);

        for (Coupon coupon : coupons) {
            if (coupon.couponName.equals(bestCoupon)) {
                return applyDiscount(product.price, coupon.discount);
            }
        }
        return String.format("%.2f", product.price);
    }

    private String applyDiscount(double price, String discount) {
        if (discount.endsWith("%")) {
            double percentage = Double.parseDouble(discount.replace("%", ""));
            return String.format("%.2f", price - (price * (percentage / 100)));
        } else if (discount.startsWith("$")) {
            double amount = Double.parseDouble(discount.replace("$", ""));
            return String.format("%.2f", Math.max(0, price - amount));
        }
        return String.format("%.2f", price);
    }
}

public class CouponManagement {
    public static void main(String[] args) {
        String[][] coupons = {
                {"Comforter Sets", "Comforters Sale", "2020-01-01", "10%"},
                {"Comforter Sets", "Cozy Comforter Coupon", "2021-01-01", "$15"},
                {"Bedding", "Best Bedding Bargains", "2019-01-01", "35%"},
                {"Bedding", "Savings on Bedding", "2019-01-01", "25%"},
                {"Bed & Bath", "Low price for Bed & Bath", "2018-01-01", "50%"},
                {"Bed & Bath", "Bed & Bath extravaganza", "2019-01-01", "75%"}
        };

        String[][] categories = {
                {"Comforter Sets", "Bedding"},
                {"Bedding", "Bed & Bath"},
                {"Bed & Bath", null},
                {"Soap Dispensers", "Bathroom Accessories"},
                {"Bathroom Accessories", "Bed & Bath"},
                {"Toy Organizers", "Baby And Kids"},
                {"Baby And Kids", null}
        };

        String[][] products = {
                {"Cozy Comforter Sets", ".10000", "Comforter Sets"},
                {"All-in-one Bedding Set", "50.00", "Bedding"},
                {"Infinite Soap Dispenser", "500.00", "Bathroom Accessories"},
                {"Rainbow Toy Box", "257.00", "Baby And Kids"}
        };

        CategoryCouponResolver resolver = new CategoryCouponResolver(coupons, categories);

        // Tests
        System.out.println(resolver.findBestCoupon("Comforter Sets")); // "Cozy Comforter Coupon"
        System.out.println(resolver.findBestCoupon("Bedding")); // "Savings on Bedding"
        System.out.println(resolver.calculateDiscountedPrice("Cozy Comforter Sets", products)); // "85.00"
        System.out.println(resolver.calculateDiscountedPrice("Rainbow Toy Box", products)); // "257.00"
    }
}
