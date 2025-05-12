package com.cargoManagement;

import java.util.*;

// Enum for PackageType
enum PackageType {
    STANDARD,
    HAZARDOUS,
    FRAGILE
}

// Interface for Cost Strategy
interface ICostStrategy {
    double calculateTransportCost(double volume);
    double calculateServiceCost(double weight, double distance);
}

// Standard Cost Strategy
class StandardCostStrategy implements ICostStrategy {
    @Override
    public double calculateTransportCost(double volume) {
        return 0.5 * volume;
    }

    @Override
    public double calculateServiceCost(double weight, double distance) {
        return 0.5 * weight + 0.5 * distance;
    }
}

// Hazardous Cost Strategy
class HazardousCostStrategy implements ICostStrategy {
    @Override
    public double calculateTransportCost(double volume) {
        return 0.75 * volume;
    }

    @Override
    public double calculateServiceCost(double weight, double distance) {
        return 0.75 * weight + 0.75 * distance;
    }
}

// Fragile Cost Strategy
class FragileCostStrategy implements ICostStrategy {
    @Override
    public double calculateTransportCost(double volume) {
        return 0.625 * volume;
    }

    @Override
    public double calculateServiceCost(double weight, double distance) {
        return 0.625 * weight + 0.625 * distance;
    }
}

// Interface for Package
interface Ipackage {
    int getId();
    double getWeight();
    double getHeight();
    double getWidth();
    double getLength();
    PackageType getType();
    double calculateVolume();
    ICostStrategy getCostStrategy();
}

// Implementation of Package
class Package implements Ipackage {
    private final int id;
    private final double weight;
    private final double height;
    private final double width;
    private final double length;
    private final PackageType type;
    private final ICostStrategy costStrategy;

    public Package(int id, double weight, double height, double width, double length, PackageType type, ICostStrategy costStrategy) {
        this.id = id;
        this.weight = weight;
        this.height = height;
        this.width = width;
        this.length = length;
        this.type = type;
        this.costStrategy = costStrategy;
    }

    @Override
    public int getId() {
        return id;
    }

    @Override
    public double getWeight() {
        return weight;
    }

    @Override
    public double getHeight() {
        return height;
    }

    @Override
    public double getWidth() {
        return width;
    }

    @Override
    public double getLength() {
        return length;
    }

    @Override
    public PackageType getType() {
        return type;
    }

    @Override
    public double calculateVolume() {
        return height * width * length;
    }

    @Override
    public ICostStrategy getCostStrategy() {
        return costStrategy;
    }
}

// Factory for creating packages
class PackageFactory {
    public static Ipackage createPackage(int id, double weight, double height, double width, double length, PackageType type) {
        ICostStrategy costStrategy;
        switch (type) {
            case STANDARD:
                costStrategy = new StandardCostStrategy();
                break;
            case HAZARDOUS:
                costStrategy = new HazardousCostStrategy();
                break;
            case FRAGILE:
                costStrategy = new FragileCostStrategy();
                break;
            default:
                throw new IllegalArgumentException("Invalid package type");
        }
        return new Package(id, weight, height, width, length, type, costStrategy);
    }
}

// Cargo class
class Cargo {
    private final List<Ipackage> packages = new ArrayList<>();

    public void insert(Ipackage pkg) {
        for (Ipackage existingPkg : packages) {
            if (existingPkg.getId() == pkg.getId()) {
                throw new IllegalArgumentException("Package with ID " + pkg.getId() + " already exists.");
            }
        }
        packages.add(pkg);
    }

    public void remove(int id) {
        packages.removeIf(pkg -> pkg.getId() == id);
    }

    public Map<String, Integer> getTotalCosts(double distance) {
        double totalTransportCost = 0;
        double totalServiceCost = 0;

        for (Ipackage pkg : packages) {
            double volume = pkg.calculateVolume();
            ICostStrategy costStrategy = pkg.getCostStrategy();

            totalTransportCost += costStrategy.calculateTransportCost(volume);
            totalServiceCost += costStrategy.calculateServiceCost(pkg.getWeight(), distance);
        }

        Map<String, Integer> totalCosts = new HashMap<>();
        totalCosts.put("TransportCost", (int) Math.round(totalTransportCost));
        totalCosts.put("ServiceCost", (int) Math.round(totalServiceCost));

        return totalCosts;
    }

    public List<Ipackage> getPackages() {
        return packages;
    }
}

// Demonstration class
public class CargoManagement {
    public static void main(String[] args) {
        Cargo cargo = new Cargo();

        // Adding packages using Factory
        cargo.insert(PackageFactory.createPackage(1, 10, 2, 3, 4, PackageType.STANDARD));
        cargo.insert(PackageFactory.createPackage(2, 15, 1.5, 2.5, 3.5, PackageType.HAZARDOUS));
        cargo.insert(PackageFactory.createPackage(3, 8, 1, 2, 2, PackageType.FRAGILE));

        // Attempt to add duplicate ID
        try {
            cargo.insert(PackageFactory.createPackage(1, 5, 1, 1, 1, PackageType.FRAGILE));
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }

        // Calculating costs for a distance of 100 units
        Map<String, Integer> totalCosts = cargo.getTotalCosts(100);

        System.out.println("Total Transport Cost: " + totalCosts.get("TransportCost"));
        System.out.println("Total Service Cost: " + totalCosts.get("ServiceCost"));
    }
}
