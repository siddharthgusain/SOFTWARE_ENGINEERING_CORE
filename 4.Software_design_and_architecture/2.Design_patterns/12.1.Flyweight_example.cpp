#include <iostream>
#include <unordered_map>
#include <memory>

// Flyweight Interface
class Character
{
public:
    virtual void display(int position, const std::string &color) const = 0;
};

// Concrete Flyweight Class
class ConcreteCharacter : public Character
{
private:
    char character;
    std::string font;
    std::string style;

public:
    ConcreteCharacter(char c, const std::string &f, const std::string &s)
        : character(c), font(f), style(s) {}

    void display(int position, const std::string &color) const override
    {
        std::cout << "Displaying character '" << character
                  << "' at position " << position
                  << " with font " << font
                  << ", style " << style
                  << ", and color " << color << ".\n";
    }
};

// Flyweight Factory
class CharacterFactory
{
private:
    std::unordered_map<std::string, std::shared_ptr<Character>> characterPool;

public:
    std::shared_ptr<Character> getCharacter(char c, const std::string &font, const std::string &style)
    {
        std::string key = std::string(1, c) + font + style;

        // If the character with the same font and style exists, return it, otherwise create and add it.
        if (characterPool.find(key) == characterPool.end())
        {
            characterPool[key] = std::make_shared<ConcreteCharacter>(c, font, style);
        }

        return characterPool[key];
    }
};

int main()
{
    // Flyweight Factory that creates and reuses characters
    CharacterFactory characterFactory;

    // Different instances of characters that share fonts and styles
    std::shared_ptr<Character> charA = characterFactory.getCharacter('A', "Arial", "Bold");
    std::shared_ptr<Character> charB = characterFactory.getCharacter('B', "Arial", "Italic");
    std::shared_ptr<Character> charC = characterFactory.getCharacter('A', "Arial", "Bold"); // Reuse 'A'

    // Displaying characters with their positions and colors (Extrinsic State)
    charA->display(1, "Red");
    charB->display(2, "Blue");
    charC->display(3, "Green");

    return 0;
}
