#include <iostream>
#include <vector>
#include <memory>
#include <string>

// Component
class FileSystemComponent
{
public:
    virtual void showDetails() const = 0; // Common operation
    virtual ~FileSystemComponent() = default;
};

// Leaf: File
class File : public FileSystemComponent
{
private:
    std::string name;
    double size; // File size in MB

public:
    File(const std::string &name, double size) : name(name), size(size) {}

    void showDetails() const override
    {
        std::cout << "File: " << name << " (" << size << " MB)" << std::endl;
    }
};

// Composite: Folder
class Folder : public FileSystemComponent
{
private:
    std::string name;
    std::vector<std::shared_ptr<FileSystemComponent>> children;

public:
    explicit Folder(const std::string &name) : name(name) {}

    void add(const std::shared_ptr<FileSystemComponent> &component)
    {
        children.push_back(component);
    }

    void showDetails() const override
    {
        std::cout << "Folder: " << name << std::endl;
        for (const auto &child : children)
        {
            child->showDetails();
        }
    }
};

int main()
{
    // Create files
    auto file1 = std::make_shared<File>("file1.txt", 1.2);
    auto file2 = std::make_shared<File>("file2.jpg", 3.5);
    auto file3 = std::make_shared<File>("file3.pdf", 2.0);

    // Create folders
    auto folder1 = std::make_shared<Folder>("Documents");
    auto folder2 = std::make_shared<Folder>("Pictures");

    // Add files to folders
    folder1->add(file1);
    folder1->add(file3);
    folder2->add(file2);

    // Create a root folder and add subfolders
    auto rootFolder = std::make_shared<Folder>("Root");
    rootFolder->add(folder1);
    rootFolder->add(folder2);

    // Display the file system structure
    rootFolder->showDetails();

    return 0;
}
