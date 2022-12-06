#include <iostream>

class Dog
{
private:
    int bark_frequency;
    int pant_rate;

public:
    void bark();
    void pant();
};

class Golden_Retreiver : public Dog
{
public:
    int retrieval_speed();
    void retrieves();
};

class LhasaApso : public Dog
{
public:
    int guard_efficiency();
    void guards();
};

int main()
{
    Golden_Retreiver tommy;
    tommy.bark();
    tommy.retrieval_speed();
    return 0;
}