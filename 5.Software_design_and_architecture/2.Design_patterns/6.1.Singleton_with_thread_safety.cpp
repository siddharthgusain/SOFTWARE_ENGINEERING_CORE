#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

class Logger
{
public:
    // Public method to provide access to the instance
    static Logger *getInstance()
    {
        // First check (no locking)
        if (!instance)
        {
            mutex.lock(); // Lock the mutex
            // Second check (with locking)
            if (!instance)
            {
                instance = new Logger(); // Create instance if it doesn't exist
                std::cout << "Logger instance created." << std::endl;
            }
            mutex.unlock(); // Unlock the mutex
        }
        return instance;
    }

    // Log a message to the console and a file
    void log(const std::string &message)
    {
        std::ofstream logFile("log.txt", std::ios::app); // Open file in append mode
        if (logFile.is_open())
        {
            logFile << message << std::endl;   // Write message to file
            std::cout << message << std::endl; // Output message to console
        }
        else
        {
            std::cerr << "Unable to open log file!" << std::endl;
        }
    }

    // Delete copy constructor and assignment operator to prevent copying
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;

private:
    // Private constructor to prevent direct instantiation
    Logger()
    {
        std::cout << "Logger initialized." << std::endl;
    }

    // Pointer to hold the single instance
    static Logger *instance; // Pointer to the single instance
    static std::mutex mutex; // Mutex for thread-safe access
};

// Initialize static members
Logger *Logger::instance = nullptr; // Initially, no instance exists
std::mutex Logger::mutex;           // Initialize the mutex

int main()
{
    // Get the Logger instance
    Logger *logger = Logger::getInstance();

    // Log some messages
    logger->log("Application started.");
    logger->log("Logging some important information.");
    logger->log("Application finished.");

    return 0;
}
