#include <iostream>

class Student
{
    int marks;

public:
    Student(){};                                            // empty constructor
    Student(int marks);                                     // parameterized constructor
    friend Student operator+(Student &obj1, Student &obj2); // friend function
    int get_marks();
};

Student::Student(int marks)
{
    this->marks = marks;
}

// Note:- Friend function require explict two argument pointing to two operands of binary operator
Student operator+(Student &obj1, Student &obj2)
{
    Student s;
    std::cout << obj1.marks << " " << obj2.marks << std::endl;
    s.marks = obj1.marks + obj2.marks;
    return s;
}

int Student::get_marks()
{
    return this->marks;
}

int main()
{
    Student s1(100);
    Student s2(70);
    Student s3;
    s3 = s1 + s2;
    // s3 = operator+(s1,s2); alternate version
    std::cout << s3.get_marks();
    return 0;
}