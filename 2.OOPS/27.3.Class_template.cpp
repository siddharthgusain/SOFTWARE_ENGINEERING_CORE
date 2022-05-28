#include <iostream>

template <class T1,class T2>
class Sum
{
    T1 a;
    T2 b;

public:
    Sum(T1 a, T2 b) : a(a), b(b){};
    T2 add()
    {
        return this->a + this->b;
    }
};

int main()
{
    Sum<int,float> obj1(5, 6);
    std::cout << obj1.add() << std::endl;
    Sum<float,float> obj2(5.44, 6.44);
    std::cout << obj2.add() << std::endl;
}