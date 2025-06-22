// Inheritance is mainly for avoiding code duplication
// it helps make code modular and maintainable
#include <iostream>

class Game
{
    int score;

public:
    Game()
    {
        this->score = 0;
    }
    void increment_score()
    {
        this->score += 1;
    }
    void print_score()
    {
        std::cout << this->score << std::endl;
    }
};

class Cricket : public Game
{
    int total_overs;

public:
    void set_total_overs(int a)
    {
        this->total_overs = a;
    }
};

class Football : public Game
{
    int total_time;

public:
    void set_total_time(int a)
    {
        this->total_time = a;
    }
};

int main()
{
    Cricket c; // size of c variable/object is 4(score) + 4 (total_overs)
    c.set_total_overs(20);
    c.increment_score();
    c.print_score();
    Football f;
    f.set_total_time(90);
    f.increment_score();
    f.print_score();
    return 0;
}