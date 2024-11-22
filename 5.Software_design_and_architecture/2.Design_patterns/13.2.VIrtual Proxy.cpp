#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Subject Interface
class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// Real Subject: High-Resolution Image
class HighResolutionImage : public Image
{
private:
    string fileName;

    void loadImageFromDisk()
    {
        cout << "Loading high-resolution image from disk: " << fileName << "\n";
    }

public:
    HighResolutionImage(const string &fileName) : fileName(fileName)
    {
        loadImageFromDisk(); // Simulate an expensive operation
    }

    void display() override
    {
        cout << "Displaying high-resolution image: " << fileName << "\n";
    }
};

// Proxy: Virtual Proxy for High-Resolution Image
class ImageProxy : public Image
{
private:
    string fileName;
    unique_ptr<HighResolutionImage> realImage;

public:
    ImageProxy(const string &fileName) : fileName(fileName), realImage(nullptr) {}

    void display() override
    {
        if (!realImage)
        {
            cout << "Initializing proxy and loading high-resolution image on demand...\n";
            realImage = make_unique<HighResolutionImage>(fileName);
        }
        realImage->display();
    }
};

// Main function demonstrating usage
int main()
{
    // Create a proxy for the high-resolution image
    ImageProxy imageProxy("beautiful_landscape.jpg");

    // Display the image (loads the high-resolution image only when required)
    cout << "Proxy created. No image loading yet.\n";

    cout << "\nRequesting to display the image...\n";
    imageProxy.display();

    cout << "\nRequesting to display the image again...\n";
    imageProxy.display();

    return 0;
}

/*

A Virtual Proxy is often used in scenarios where creating an actual object is expensive in terms of resources or time, 
and the object’s creation can be deferred until it is truly needed. 

A real-world example is the lazy loading of images in a web application or large file previews in software.

*/