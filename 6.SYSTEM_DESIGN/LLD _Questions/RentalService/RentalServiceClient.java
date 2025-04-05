package com.RentalService;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.UUID;

abstract class Product {
    private String  id;
    private String  name;
    private double rentalPrice;
    private boolean isAvailable;

    Product(String id, String name, double rentalPrice) {
        this.id = id;
        this.name = name;
        this.rentalPrice = rentalPrice;
        this.isAvailable = true;
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public double getRentalPrice() {
        return this.rentalPrice;
    }

    public void setRentalPrice(double rentalPrice) {
        this.rentalPrice = rentalPrice;
    }

    public boolean isAvailable() {
        return this.isAvailable;
    }

    public void setAvailable(boolean available) {
        this.isAvailable = available;
    }

    abstract public String getDetails();
}

enum BikeSize {
    SMALL, MEDIUM, LARGE
}

class Bike extends Product {
    private BikeSize bikeSize;

    Bike(String id, String name, double rentalPrice, BikeSize bikeSize) {
        super(id, name, rentalPrice);
        this.bikeSize = bikeSize;
    }

    @Override
    public String getDetails() {
        return "Bike:" + this.getName();
    }
}

enum ScooterType {
    ELECTRIC,GASOLINE
}

class Scooter extends Product {
    private ScooterType scooterType;

    Scooter(String id, String name, double rentalPrice, ScooterType scooterType) {
        super(id, name, rentalPrice);
        this.scooterType = scooterType;
    }

    @Override
    public String getDetails() {
        return "SCooter:" + this.getName();
    }
}

class Customer{
    private String id;
    private String name;
    private double amountOwed;

    Customer(String id, String name, double balance) {
        this.id = id;
        this.name = name;
        this.amountOwed = 0.0;
    }

    public String getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public double getBalance() {
        return this.amountOwed;
    }

    public void addBalance(double amount) {
        this.amountOwed -= amount;
    }

    public void chargeForRental(double amount) {
        this.amountOwed += amount;
    }

}

enum RentalStatus{
    ACTIVE,COMPLETED
}

class Rental {
    private String customerId;
    private String productId;
    private Date rentedOn;
    private Date dueDate;
    private Date returnOn;
    private RentalStatus status;
    private double RentalCharge;

    Rental(String customerId, String productId, Date dueDate,double rentalPrice) {
        this.customerId = customerId;
        this.productId = productId;
        this.rentedOn = new Date();
        this.dueDate = dueDate;
        this.returnOn = null;
        this.status = RentalStatus.ACTIVE;
        this.RentalCharge = rentalPrice;
    }

    public String getCustomerId() {
        return this.customerId;
    }

    public String getProductId() {
        return this.productId;
    }

    public Date getRentedOn() {
        return this.rentedOn;
    }

    public Date getDueDate() {
        return this.dueDate;
    }

    public RentalStatus getStatus() {
        return this.status;
    }

    public void setReturnOn(Date returnOn) {
        this.returnOn = returnOn;
    }

    public void setStatus(RentalStatus status) {
        this.status = status;
    }

}

// PricingStrategy interface
interface PricingStrategy {
    double calculateRentalCharge(Product product, int rentalDays);
}

// BikePricingStrategy implementation
class BikePricingStrategy implements PricingStrategy {
    @Override
    public double calculateRentalCharge(Product product, int rentalDays) {
        return rentalDays * product.getRentalPrice();
    }
}

// ScooterPricingStrategy implementation
class ScooterPricingStrategy implements PricingStrategy {
    @Override
    public double calculateRentalCharge(Product product, int rentalDays) {
        return rentalDays * product.getRentalPrice() * 1.2; // 20% surcharge for scooters
    }
}

// ProductFactory class
class ProductFactory {
    public Product createProduct(String productType, String name, double price, Enum<?> type) {
        switch (productType.toLowerCase()) {
            case "bike":
                return new Bike(UUID.randomUUID().toString(), name, price, (BikeSize) type);
            case "scooter":
                return new Scooter(UUID.randomUUID().toString(), name, price, (ScooterType) type);
            default:
                throw new IllegalArgumentException("Invalid product type");
        }
    }
}

class RentalManagementService {
    private List<Product> products = new ArrayList<>();
    private List<Rental> rentals = new ArrayList<>();
    private List<Customer> customers = new ArrayList<>();

    private static RentalManagementService instance;

    private RentalManagementService() {}

    public static RentalManagementService getInstance() {
        if (instance == null) {
            instance = new RentalManagementService();
        }
        return instance;
    }

    public void addProduct(Product product) {
        products.add(product);
    }

    public void removeProduct(String productId) {
        products.removeIf(product -> product.getId().equals(productId));
    }

    public List<Product> findAvailableProducts() {
        List<Product> availableProducts = new ArrayList<>();
        for (Product product : products) {
            if (product.isAvailable()) {
                availableProducts.add(product);
            }
        }
        return availableProducts;
    }

    public List<Rental> findOverdueRentals(Date currentDate) {
        List<Rental> overdueRentals = new ArrayList<>();
        for (Rental rental : rentals) {
            if (rental.getDueDate().before(currentDate) && rental.getStatus() == RentalStatus.ACTIVE) {
                overdueRentals.add(rental);
            }
        }
        return overdueRentals;
    }

    public List<Rental> findCustomerRentals(String customerId) {
        List<Rental> customerRentals = new ArrayList<>();
        for (Rental rental : rentals) {
            if (rental.getCustomerId().equals(customerId)) {
                customerRentals.add(rental);
            }
        }
        return customerRentals;
    }

    public void addRental(Rental rental) {
        rentals.add(rental);
    }

    public void addCustomer(Customer customer) {
        customers.add(customer);
    }

    // Method to charge the customer when creating a rental
    public void chargeCustomerForRental(Customer customer, Product product, int rentalDays) {
        PricingStrategy pricingStrategy = null;

        if (product instanceof Bike) {
            pricingStrategy = new BikePricingStrategy();
        } else if (product instanceof Scooter) {
            pricingStrategy = new ScooterPricingStrategy();
        }

        if (pricingStrategy != null) {
            double rentalCharge = pricingStrategy.calculateRentalCharge(product, rentalDays);
            customer.chargeForRental(rentalCharge);
        }
    }
}


public class RentalServiceClient {
    public static void main(String[] args) {

    }
}
