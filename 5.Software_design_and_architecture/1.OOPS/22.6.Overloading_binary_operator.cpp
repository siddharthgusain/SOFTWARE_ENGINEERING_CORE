#include <iostream>

class Student
{
    int marks;

public:
    Student(){};
    Student(int marks);
    Student operator+(Student &obj);
    int get_marks();
};

Student::Student(int marks)
{
    this->marks = marks; // note:- this-> marks <====> *(this).marks
}

Student Student::operator+(Student &obj)
{
    Student s;
    std::cout << this->marks << " " << obj.marks << std::endl;
    s.marks = this->marks + obj.marks; // "this" is a pointer to "first" operand, obj points to "second" operand
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
    // s3 = s1.operator+(s2); alternate version
    std::cout << s3.get_marks();
    return 0;
}