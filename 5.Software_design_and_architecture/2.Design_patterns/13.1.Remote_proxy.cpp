#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Subject Interface
class File
{
public:
    virtual void read() = 0;
    virtual void write(const string &data) = 0;
    virtual ~File() = default;
};

// Real Subject: Represents the file stored on a remote server
class RemoteFile : public File
{
private:
    string fileName;

public:
    RemoteFile(const string &fileName) : fileName(fileName)
    {
        cout << "Loading file '" << fileName << "' from remote server...\n";
    }

    void read() override
    {
        cout << "Reading file '" << fileName << "' from remote server...\n";
    }

    void write(const string &data) override
    {
        cout << "Writing data to file '" << fileName << "' on remote server...\n";
        cout << "Data written: " << data << "\n";
    }
};

// Proxy: Acts as a placeholder for the Remote File
class RemoteFileProxy : public File
{
private:
    string fileName;
    unique_ptr<RemoteFile> remoteFile;

    void connectToServer()
    {
        if (!remoteFile)
        {
            cout << "Establishing connection to the remote server...\n";
            remoteFile = make_unique<RemoteFile>(fileName);
        }
    }

public:
    RemoteFileProxy(const string &fileName) : fileName(fileName), remoteFile(nullptr) {}

    void read() override
    {
        connectToServer();
        remoteFile->read();
    }

    void write(const string &data) override
    {
        connectToServer();
        remoteFile->write(data);
    }
};

// Main function demonstrating usage
int main()
{
    RemoteFileProxy fileProxy("example.txt");

    // Read Operation
    cout << "Performing read operation...\n";
    fileProxy.read();

    // Write Operation
    cout << "\nPerforming write operation...\n";
    fileProxy.write("New content for the file.");

    return 0;
}
