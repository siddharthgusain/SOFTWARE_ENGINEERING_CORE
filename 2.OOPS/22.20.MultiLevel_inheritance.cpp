#include <iostream>

class Student
{
    int roll_number;

public:
    void set_roll_number(int number)
    {
        this->roll_number = number;
    }

    void show_roll_number()
    {
        std::cout << "Roll number:" << this->roll_number << std::endl;
    }
};

class Test : public Student
{
protected:
    int marks1, marks2;

public:
    void set_marks(int m1, int m2)
    {
        this->marks1 = m1;
        this->marks2 = m2;
    }

    void show_marks()
    {
        std::cout << "Marks1:" << this->marks1 << std::endl;
        std::cout << "Marks2:" << this->marks2 << std::endl;
    }
};

class Result : public Test
{
    int total_marks;

public:
    void calculate_total_marks()
    {
        this->total_marks = this->marks1 + this->marks2;
    }

    void display_data()
    {
        this->calculate_total_marks();
        this->show_roll_number();
        this->show_marks();
        std::cout << "Total Marks:" << this->total_marks;
    }
};

int main()
{
    // size of main function is reduced because of OOP , so this follows modularity
    Result student1;
    student1.set_roll_number(1);
    student1.set_marks(80, 100);
    student1.display_data();
    return 0;
}

/*
NOTE:- student1 object memory space has all four variables (roll_number,marks1,marks2,total_marks)
Where these variables are accessible (whether directly by "object" or by "member function") is specified
by access specifier i.e (private, protected , public)
*/