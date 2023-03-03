#include <iostream>
#include <string>

class Marker
{
public:
    std::string name;
    std::string color;
    int year;
    int price;

    Marker(){};

    Marker(std::string name, std::string color, int year, int price)
    {
        this->name = name;
        this->color = color;
        this->price = price;
        this->year = year;
    }
};

class Invoice_Calculator
{
private:
    Marker marker; // Invoice "HAS-A" Marker
    int quantity;

public:
    Invoice_Calculator(){};

    Invoice_Calculator(Marker marker, int quantity)
    {
        this->marker = marker;
        this->quantity = quantity;
    }

    int calculate_total()
    {
        int price = ((marker.price) * this->quantity);
        return price;
    }
};

class Invoice_DAO
{
    Invoice_Calculator invoice;

public:
    Invoice_DAO(Invoice_Calculator invoice)
    {
        this->invoice = invoice;
    }

    void save_to_db()
    {
        // save to db
    }
};

class Invoice_printer
{
private:
    Invoice_Calculator invoice;

public:
    Invoice_printer(Invoice_Calculator invoice)
    {
        this->invoice = invoice;
    }

    void print_invoice()
    {
        // print invoice
    }
};

/*
We divided the classes to multiple SRP classes for better
maintainability
*/