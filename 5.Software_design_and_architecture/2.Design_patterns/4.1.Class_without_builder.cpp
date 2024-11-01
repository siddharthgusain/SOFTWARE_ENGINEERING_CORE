#include <iostream>
#include <string>

class URL
{
public:
    // Constructor for base URL only
    URL(const std::string &baseURL)
        : baseURL(baseURL) {}

    // Constructor for base URL and path
    URL(const std::string &baseURL, const std::string &path)
        : baseURL(baseURL), path(path) {}

    // Constructor for base URL, path, and query
    URL(const std::string &baseURL, const std::string &path, const std::string &query)
        : baseURL(baseURL), path(path), query(query) {}

    // Constructor for base URL, path, query, and fragment
    URL(const std::string &baseURL, const std::string &path, const std::string &query, const std::string &fragment)
        : baseURL(baseURL), path(path), query(query), fragment(fragment) {}

    std::string getFullURL() const
    {
        std::string fullURL = baseURL;
        if (!path.empty())
            fullURL += "/" + path;
        if (!query.empty())
            fullURL += "?" + query;
        if (!fragment.empty())
            fullURL += "#" + fragment;
        return fullURL;
    }

private:
    std::string baseURL;
    std::string path;
    std::string query;
    std::string fragment;
};

int main()
{
    // Using different constructors to create URL objects
    URL url1("https://example.com");
    URL url2("https://example.com", "search");
    URL url3("https://example.com", "search", "q=design+patterns");
    URL url4("https://example.com", "search", "q=design+patterns", "section=1");

    // Print out each URL
    std::cout << "URL 1: " << url1.getFullURL() << std::endl;
    std::cout << "URL 2: " << url2.getFullURL() << std::endl;
    std::cout << "URL 3: " << url3.getFullURL() << std::endl;
    std::cout << "URL 4: " << url4.getFullURL() << std::endl;

    return 0;
}

// Mutiple Parameterized Constructor is Required
// Code is Hard to Maintain and Extend