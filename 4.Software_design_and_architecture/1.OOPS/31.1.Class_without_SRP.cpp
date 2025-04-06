#include <iostream>
#include <string>
#include <fstream>

class Report
{
private:
    std::string content;

public:
    Report(const std::string &text) : content(text) {}

    // Generate the report content
    void generate()
    {
        std::cout << "Generating report content: " << content << std::endl;
    }

    // Save the report to a file
    void saveToFile(const std::string &filename)
    {
        std::ofstream file(filename);
        if (file.is_open())
        {
            file << content;
            file.close();
            std::cout << "Report saved to file: " << filename << std::endl;
        }
        else
        {
            std::cerr << "Error opening file" << std::endl;
        }
    }

    // Send the report by email
    void sendByEmail(const std::string &email)
    {
        std::cout << "Sending report to email: " << email << std::endl;
        // Logic to send email (omitted for simplicity)
    }
};

int main()
{
    Report report("Monthly Sales Report");
    report.generate();
    report.saveToFile("report.txt");
    report.sendByEmail("manager@example.com");

    return 0;
}

/*
Problems with this Design
The Report class has multiple responsibilities:

Generating report content.
Saving the report to a file.
Sending the report by email.
If we need to change the way we save or send reports, we’ll modify the Report class, violating the SRP and potentially introducing bugs.

*/