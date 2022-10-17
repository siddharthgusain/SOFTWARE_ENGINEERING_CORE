#include <iostream>

class Test
{
    int a;
    int b;

public:
    Test(int data1, int data2) : a(data2), b(data1){}; // another syntax known as member initializeer list
    void display_data()
    {
        std::cout << this->a << " " << this->b;
    }
};

int main()
{
    Test t(2, 3);
    t.display_data();
    return 0;
}
