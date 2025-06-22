#include <iostream>

int main()
{
    int *ptr = new int[5]; // 5*sizeof(int) bytes of memory
    // ptr is variable present in "stack" containing base address of memory allocated in heap
    std::cout << ptr << std::endl;  // base address of memory allocated
    std::cout << *ptr << std::endl; // Value at base address
    for (int i = 0; i < 5; i++)
    {
        ptr[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << ptr[i] << std::endl;
    }
    delete[] ptr; // deallocation
    return 0;
}

/*
-> new is syntactical sugar over malloc() in "c", which further calls operating system
sys calls to get memory IN RAM(also known as heap region)
-> So allocation in heap is slow as sys call is involved, so context switch is done
-> Operating system manages a free list from which it gives memory pointer using some algorithm like best fit
worst fit , first fit etc.
*/