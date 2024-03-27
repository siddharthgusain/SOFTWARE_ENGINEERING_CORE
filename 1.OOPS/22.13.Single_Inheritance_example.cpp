#include <iostream>

class Car
{
private: // this is not inherited
    float speed;

public: // this section will be inherited
    char color;
    void set_speed(float speed)
    {
        this->speed = speed;
    }
    float show_speed()
    {
        return this->speed;
    }
};

class Tata : public Car // all the inherited members goes to public section , so can be access using  object
{
private:
    char mode;

public:
    void set_mode(char mode)
    {
        this->mode = mode;
    }
};

int main()
{
    Tata car1;           // note in memory car1 has memory size = size of variables "speed + mode + color"
    car1.color = 'R';    // color data member is inherited and is present in public section of class Tata
    car1.set_mode('E');  // set_mode is public member_function of Class Tata
    car1.set_speed(100); // set_speed is inherited in public section of Class Tata
    // car1.speed; speed data member is not inherited so can't be accessed
    std::cout << car1.show_speed();
    return 0;
}

// Very imp:- size of car1 object is equivalent to all the data members in parent classes + its own data members
//  But some of these data members are not accessible by this object as they are not inherited
// So Compiler Gives errors if developer unknowingly try to access private variables.
// So OOPS gives compiler time safety