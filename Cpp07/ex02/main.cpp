#include <iostream>
#include "Array.hpp"
#include "Array.tpp"
#include <ctime>
#include <cstdlib> 


int main()
{

    Array <char>test(4);
    Array <char>second;

    for (unsigned int i = 0; i < test.size(); i++)
        test[i] = 'a' + i;

    for (unsigned int i = 0; i < test.size(); i++)
        std::cout << test[i] << std::endl;

    second = test;

    for (unsigned int i = 0; i < second.size(); i++)
        std::cout << second[i] << std::endl;

    second[0] = 'z';

    for (unsigned int i = 0; i < second.size(); i++)
        std::cout << second[i] << std::endl;


    for (unsigned int i = 0; i < test.size(); i++)
        std::cout << test[i] << std::endl;

    try
    {
        test[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        test[300] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
