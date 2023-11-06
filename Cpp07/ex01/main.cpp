#include "iter.hpp"

template <typename T>
void print(T &x)
{
    std::cout << x;
}

void intcrementing(int &x)
{
    std::cout << x + 5;
}

int main()
{
    std::string c = "Hello World!";
    int arr[] = {1, 2, 3, 4, 5};

    std::cout << "Array of INT:" << std::endl;
    iter(arr, 5, print<int>);
    std::cout << std::endl;
    
    iter(arr, 5, intcrementing);
    std::cout << std::endl;

    std::cout << "Array of CHAR:" << std::endl;
    iter(c.c_str(), c.length(), print);
    std::cout << std::endl;
}