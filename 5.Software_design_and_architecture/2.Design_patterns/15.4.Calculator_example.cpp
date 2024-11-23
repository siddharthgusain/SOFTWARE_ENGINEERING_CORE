#include <iostream>
#include <string>
#include <map>
#include <memory>

using namespace std;

// AbstractExpression: Base class for all expressions
class Expression
{
public:
    virtual int interpret() const = 0;
    virtual ~Expression() = default;
};

// TerminalExpression: Represents numbers
class NumberExpression : public Expression
{
private:
    int number;

public:
    explicit NumberExpression(int value) : number(value) {}

    int interpret() const override
    {
        return number;
    }
};

// NonTerminalExpression: Represents addition
class AddExpression : public Expression
{
private:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;

public:
    AddExpression(unique_ptr<Expression> left, unique_ptr<Expression> right)
        : left(move(left)), right(move(right)) {}

    int interpret() const override
    {
        return left->interpret() + right->interpret();
    }
};

// NonTerminalExpression: Represents subtraction
class SubtractExpression : public Expression
{
private:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;

public:
    SubtractExpression(unique_ptr<Expression> left, unique_ptr<Expression> right)
        : left(move(left)), right(move(right)) {}

    int interpret() const override
    {
        return left->interpret() - right->interpret();
    }
};

// Main function demonstrating the pattern
int main()
{
    // Expression: 5 + (3 - 2)
    unique_ptr<Expression> five = make_unique<NumberExpression>(5);
    unique_ptr<Expression> three = make_unique<NumberExpression>(3);
    unique_ptr<Expression> two = make_unique<NumberExpression>(2);

    // Sub-expression: (3 - 2)
    unique_ptr<Expression> subtract = make_unique<SubtractExpression>(move(three), move(two));

    // Full expression: 5 + (3 - 2)
    unique_ptr<Expression> expression = make_unique<AddExpression>(move(five), move(subtract));

    // Evaluate the expression
    cout << "Result: " << expression->interpret() << endl; // Output: 6

    return 0;
}
