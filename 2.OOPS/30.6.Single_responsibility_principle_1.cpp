#include <iostream>
#include <string>

class Marker
{
public:
    std::string name;
    std::string color;
    int year;
    int price;
    Marker(std::string name, std::string color, int year, int price)
    {
        this->name = name;
        this->color = color;
        this->price = price;
        this->year = year;
    }
};

class Invoice
{
private:
    Marker marker; // Invoice "HAS-A" Marker
    int quantity;

public:
    Invoice(Marker marker, int quantity)
    {
        this->marker = marker;
        this->quantity = quantity;
    }

    int calculate_total()
    {
        int price = ((marker.price) * this->quantity);
        return price;
    }

    void print_invoice()
    {
        // print logic
    }

    void save_to_db()
    {
        // save to db logic
    }
};

/*
here invoice class has more than one responsibility which can lead to
less flexibility
*/