package com.orderManagement;

import java.util.*;

// IOrder interface
interface IOrder {
    String getName();
    int getPrice();
}

// Order class implementing IOrder
class Order implements IOrder {
    private final String name;
    private final int price;

    public Order(String name, int price) {
        this.name = name;
        this.price = price;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public int getPrice() {
        return price;
    }
}

// DiscountStrategy Interface
interface DiscountStrategy {
    int calculateDiscountedPrice(int price);
}

// Concrete Strategy for Cheap Category
class CheapDiscountStrategy implements DiscountStrategy {
    @Override
    public int calculateDiscountedPrice(int price) {
        return (int) (price - (price * 0.10));
    }
}

// Concrete Strategy for Moderate Category
class ModerateDiscountStrategy implements DiscountStrategy {
    @Override
    public int calculateDiscountedPrice(int price) {
        return (int) (price - (price * 0.20));
    }
}

// Concrete Strategy for Expensive Category
class ExpensiveDiscountStrategy implements DiscountStrategy {
    @Override
    public int calculateDiscountedPrice(int price) {
        return (int) (price - (price * 0.30));
    }
}

// IOrderSystem interface
interface IOrderSystem {
    void addToCart(IOrder order);
    void removeFromCart(IOrder order);
    int calculateTotalAmount();
    Map<String, Integer> categoryDiscounts();
    Map<String, Integer> cartItems();
}

// OrderSystem class implementing IOrderSystem
class OrderSystem implements IOrderSystem {
    private final List<IOrder> cart;

    public OrderSystem() {
        this.cart = new ArrayList<>();
    }

    @Override
    public void addToCart(IOrder order) {
        if (order == null) {
            throw new IllegalArgumentException("Order cannot be null.");
        }
        cart.add(order);
    }

    @Override
    public void removeFromCart(IOrder order) {
        if (order == null) {
            throw new IllegalArgumentException("Order cannot be null.");
        }
        cart.remove(order);
    }

    @Override
    public int calculateTotalAmount() {
        int total = 0;
        for (IOrder order : cart) {
            total += getDiscountedPrice(order);
        }
        return total;
    }

    @Override
    public Map<String, Integer> categoryDiscounts() {
        Map<String, Integer> discounts = new HashMap<>();
        Map<String, List<IOrder>> groupedOrders = groupByCategory();

        for (Map.Entry<String, List<IOrder>> entry : groupedOrders.entrySet()) {
            String category = entry.getKey();
            List<IOrder> orders = entry.getValue();
            int totalDiscount = 0;

            for (IOrder order : orders) {
                totalDiscount += order.getPrice() - getDiscountedPrice(order);
            }

            discounts.put(category, totalDiscount);
        }

        return discounts;
    }

    @Override
    public Map<String, Integer> cartItems() {
        Map<String, Integer> items = new HashMap<>();

        for (IOrder order : cart) {
            items.put(order.getName(), items.getOrDefault(order.getName(), 0) + 1);
        }

        return items;
    }

    private int getDiscountedPrice(IOrder order) {
        DiscountStrategy strategy = determineStrategy(order.getPrice());
        return strategy.calculateDiscountedPrice(order.getPrice());
    }

    private DiscountStrategy determineStrategy(int price) {
        if (price <= 10) {
            return new CheapDiscountStrategy();
        } else if (price <= 20) {
            return new ModerateDiscountStrategy();
        } else {
            return new ExpensiveDiscountStrategy();
        }
    }

    private Map<String, List<IOrder>> groupByCategory() {
        Map<String, List<IOrder>> categories = new HashMap<>();

        for (IOrder order : cart) {
            String category = determineCategory(order.getPrice());
            categories.putIfAbsent(category, new ArrayList<>());
            categories.get(category).add(order);
        }

        return categories;
    }

    private String determineCategory(int price) {
        if (price <= 10) {
            return "Cheap";
        } else if (price <= 20) {
            return "Moderate";
        } else {
            return "Expensive";
        }
    }

    // Main method for testing
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        IOrderSystem orderSystem = new OrderSystem();

        for (int i = 0; i < n; i++) {
            String[] input = scanner.nextLine().split(" ");
            String name = input[0];
            int price = Integer.parseInt(input[1]);
            orderSystem.addToCart(new Order(name, price));
        }

        // Calculate and display total amount
        System.out.println("Total Amount: " + orderSystem.calculateTotalAmount());

        // Calculate and display category discounts
        for (Map.Entry<String, Integer> entry : orderSystem.categoryDiscounts().entrySet()) {
            System.out.println(entry.getKey() + " Category Discount: " + entry.getValue());
        }

        // Display cart items
        for (Map.Entry<String, Integer> entry : orderSystem.cartItems().entrySet()) {
            System.out.println(entry.getKey() + " (" + entry.getValue() + " items)");
        }

        scanner.close();
    }
}
