#include <iostream>
#include <string> // template library

int main()
{
    char c[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    std::cout << c << std::endl; // prints hello because of null character , it know the end
    const char *ptr = "hello";
    std::cout << ptr << std::endl;
    std::string str = "hello"; // string class in cpp
    std::cout << str << std::endl;
    std::cout << str.size() << std::endl; // size excluding null character(5)
    str += "world";
    std::cout << str; // helloworld
    return 0;
}

/*
-> String is character array having one extra character '\0' character
which denotes end of a string.
-> "Null" character is useful for "Operating System" to know end of string
*/