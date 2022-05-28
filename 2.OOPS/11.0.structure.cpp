#include <iostream>

struct student
{
    char name[100];
    int roll_number;
};

int main()
{
    student s1{"sid", 10};
    std::cout << s1.name;
    return 0;
}