#include <iostream>

int main()
{
    // INBUILT DATA TYPES
    int a = 10; // a is variable of type int(size of int depend on OS and CPU architecture)
    float b = 1.222;
    char c = 'a';
    bool is_bool = true;
    long d = 11121313;
    // void  -> Only used for Functions Return Type

    // DATA TYPE MODIFIERS
    short int e = 2222;
    long long f = 201230103;
    unsigned int g = 10201993;
    signed int h = -122112;
    return 0;
}

/*
-> variables are just space(bytes) in memory to store data.
-> We can store any Data type in any variable as it is just bytes in Memory , because of implicit Type Conversion -> Compilers
won't give error.
-> Data types are just way to tell compiler how much size of memory is required which further is allocated according
to operating system and computer architecture.
-> Inbuilt Data type like int , float are reserved keyword in compiler , so when source file is parsed ,the size is
known by compiler
-> User defined data type like structure and class defines block which describes the total size required by the object
according to that compiler generates assembly code.
-> AS CPP is statically typed , means if we try to put wrong data type into a variable declared , then it will give
error thats how it is written. So we get error/bugs in compile time , rather than runtime.
*/

/*
CONCLUSION
-> When we say statically typed Language -> Developer must have to write Data type for every variable declaration(C++, Java)
-> When we say dynamically type Language -> Developer doesn't need to write Data Type for every variable declaration(JS,Python)

-> Assigning One type variable to another is possible in both types though as variable is just Space(bytes) in Memory
*/