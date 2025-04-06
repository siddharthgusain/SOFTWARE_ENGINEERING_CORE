#include <iostream>
#include <string>

class Computer
{
public:
    // Private constructor to restrict instantiation outside the builder
    Computer(const std::string &cpu, const std::string &gpu, int ram, int storage)
        : cpu(cpu), gpu(gpu), ram(ram), storage(storage) {}

    void displayConfiguration() const
    {
        std::cout << "CPU: " << cpu << "\n"
                  << "GPU: " << gpu << "\n"
                  << "RAM: " << ram << " GB\n"
                  << "Storage: " << storage << " GB" << std::endl;
    }

    // Friend declaration for the builder class
    friend class ComputerBuilder;

private:
    std::string cpu;
    std::string gpu;
    int ram;
    int storage;
};

class ComputerBuilder
{
public:
    ComputerBuilder &setCPU(const std::string &cpu)
    {
        this->cpu = cpu;
        return *this;
    }

    ComputerBuilder &setGPU(const std::string &gpu)
    {
        this->gpu = gpu;
        return *this;
    }

    ComputerBuilder &setRAM(int ram)
    {
        this->ram = ram;
        return *this;
    }

    ComputerBuilder &setStorage(int storage)
    {
        this->storage = storage;
        return *this;
    }

    Computer build()
    {
        return Computer(cpu, gpu, ram, storage);
    }

private:
    std::string cpu = "Intel i5"; // Default values
    std::string gpu = "Integrated";
    int ram = 8;       // 8 GB default
    int storage = 256; // 256 GB default
};

int main()
{
    // Create a custom computer configuration using the builder
    Computer myComputer = ComputerBuilder()
                              .setCPU("Intel i9")
                              .setGPU("NVIDIA RTX 3080")
                              .setRAM(32)
                              .setStorage(1000)
                              .build();

    myComputer.displayConfiguration();

    return 0;
}
