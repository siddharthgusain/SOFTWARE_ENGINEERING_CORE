#include <iostream>
#include <string>
using namespace std;

// Abstract Class: FileParser
class FileParser
{
public:
    // Template Method
    void parseFile(const string &fileName)
    {
        openFile(fileName);
        readFile();
        parseData();
        closeFile();
    }

    // Common steps with default implementation
    void openFile(const string &fileName)
    {
        cout << "Opening file: " << fileName << endl;
    }

    void closeFile()
    {
        cout << "Closing file" << endl;
    }

    // Abstract steps to be implemented by subclasses
    virtual void readFile() = 0;
    virtual void parseData() = 0;

    virtual ~FileParser() = default;
};

// Concrete Class: CSVParser
class CSVParser : public FileParser
{
public:
    void readFile() override
    {
        cout << "Reading CSV file contents" << endl;
    }

    void parseData() override
    {
        cout << "Parsing CSV data" << endl;
    }
};

// Concrete Class: JSONParser
class JSONParser : public FileParser
{
public:
    void readFile() override
    {
        cout << "Reading JSON file contents" << endl;
    }

    void parseData() override
    {
        cout << "Parsing JSON data" << endl;
    }
};

// Main function demonstrating the Template Method Pattern
int main()
{
    // Create CSV parser
    cout << "Parsing a CSV file:" << endl;
    CSVParser csvParser;
    csvParser.parseFile("data.csv");

    cout << "\nParsing a JSON file:" << endl;
    // Create JSON parser
    JSONParser jsonParser;
    jsonParser.parseFile("data.json");

    return 0;
}
