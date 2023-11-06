#include <iostream>
#include "Array.hpp"
#include "Array.tpp"
#include <ctime>
#include <cstdlib> 

#define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

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
