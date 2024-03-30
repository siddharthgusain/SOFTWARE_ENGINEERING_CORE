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

class Invoice_DAO // interface
{
public:
    virtual void save(Invoice_Calculator invoice) = 0;
};

class Database_invoice_DAO : public Invoice_DAO
{
    void save(Invoice_Calculator invoice) // overriding base class function
    {
        // save to db
    }
};

class File_invoice_DAO : public Invoice_DAO
{
    void save(Invoice_Calculator invoice) // overriding base class function
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

// class should be able to extention but not for modification
// it is very useful if a code is already live and tested then new classes can be extended
// from already tested classes