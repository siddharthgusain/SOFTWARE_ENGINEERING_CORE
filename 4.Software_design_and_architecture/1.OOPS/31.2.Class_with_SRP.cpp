#include <iostream>
#include <string>
#include <fstream>

// Report class (responsible for generating the report content)
class Report
{
private:
    std::string content;

public:
    Report(const std::string &text) : content(text) {}

    void generate()
    {
        std::cout << "Generating report content: " << content << std::endl;
    }

    std::string getContent() const
    {
        return content;
    }
};

// FileManager class (responsible for saving the report to a file)
class FileManager
{
public:
    void saveToFile(const Report &report, const std::string &filename)
    {
        std::ofstream file(filename);
        if (file.is_open())
        {
            file << report.getContent();
            file.close();
            std::cout << "Report saved to file: " << filename << std::endl;
        }
        else
        {
            std::cerr << "Error opening file" << std::endl;
        }
    }
};

// EmailService class (responsible for sending the report by email)
class EmailService
{
public:
    void sendByEmail(const Report &report, const std::string &email)
    {
        std::cout << "Sending report to email: " << email << std::endl;
        // Logic to send email (omitted for simplicity)
    }
};

int main()
{
    Report report("Monthly Sales Report");

    // Generate report content
    report.generate();

    // Save to file
    FileManager fileManager;
    fileManager.saveToFile(report, "report.txt");

    // Send by email
    EmailService emailService;
    emailService.sendByEmail(report, "manager@example.com");

    return 0;
}
