#include <iostream>
#include <string>

class URL
{
public:
    URL(const std::string &baseURL) : baseURL(baseURL) {}

    void setPath(const std::string &path) { this->path = path; }
    void setQuery(const std::string &query) { this->query = query; }
    void setFragment(const std::string &fragment) { this->fragment = fragment; }

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

// Builder class
class URLBuilder
{
public:
    URLBuilder(const std::string &baseURL) : url(baseURL) {}

    URLBuilder &addPath(const std::string &path)
    {
        url.setPath(path);
        return *this;
    }

    URLBuilder &addQuery(const std::string &query)
    {
        url.setQuery(query);
        return *this;
    }

    URLBuilder &addFragment(const std::string &fragment)
    {
        url.setFragment(fragment);
        return *this;
    }

    URL build() const
    {
        return url;
    }

private:
    URL url; // Composed Object of URL class
};

int main()
{
    // Construct URL using the Builder pattern
    URLBuilder builder("https://example.com");
    URL url = builder.addPath("search")
                  .addQuery("q=builder+pattern")
                  .addFragment("section=1")
                  .build();

    std::cout << "URL with Builder: " << url.getFullURL() << std::endl;

    return 0;
}
