#include <iostream>

void print(int a) // user defined functions
{
    std::cout << a; // cout is a class ostream object which in turn has system call inside it
    std::cout.operator<<(a);
    /*
     * std -> Namespace
     * cout -> Object of Ostream class
     * << -> overloaded operator
     * .operator<<() is overloaded operator function call syntax that we learnt in OOPS
     * So we are basically calling overloaded function << by passing "a"
     * Inside this function there is OS system call write() to write to Console/monitor
     */
}

int main()
{
    int a = 10;
    print(a); // user defined function call
    return 0;
}

// Functions are just block of instruction
// Used for reusability
// used for modularity and maintainability

/*
-> Functions have two things :-
1. declaration / function signature --> for compiler to know that this function exists and its the syntax
2. definition :- the actual body of function with data and instruction inside it.
*/

/*
- > Declaration of function should be always present inside CPP file , it is required for compiler to generate object code

-> However actual body of function may or may not be present in the same file , it could be in some other file or it
could be present in dynamic linked libraries and is taken care by linker and loader and operating system software

-> But point to be noted , function body is always present somewhere may be in your source code or may be in operating
system code or present in some pre-defined location in hard-disk.
*/