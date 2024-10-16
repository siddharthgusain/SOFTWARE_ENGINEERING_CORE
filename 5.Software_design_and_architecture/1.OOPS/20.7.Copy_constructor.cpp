#include <iostream>

class Student
{
    int marks;

public:
    Student();                 // default constructor declaration
    Student(const Student &s); // copy constructor declaration
    int get_marks();
    void set_marks(int marks);
};

Student::Student() // default constructor definition
{
    std::cout << "default constructor is called" << std::endl;
    this->marks = 0;
}

Student::Student(const Student &s) // copy constructor definition
{
    std::cout << "Copy constructor is called" << std::endl;
    this->marks = s.marks;
}

void Student::set_marks(int marks)
{
    this->marks = marks;
}

int Student::get_marks()
{
    return this->marks;
}

int main()
{
    Student s1; // default constructor is called
    s1.set_marks(40);
    Student s2(s1); // copy constructor is called
    std ::cout << s2.get_marks();
    return 0;
}