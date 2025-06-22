#include <iostream>

int main()
{
    enum e
    {
        A = 1,
        B,
        C
    };

    std::cout << A << " " << B << " " << C;
}