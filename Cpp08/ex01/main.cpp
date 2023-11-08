#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Create a Span object with capacity for 10,000 numbers
    Span sp = Span(10000);
    Span sps = Span(5);
    sps.addNumber(6);
    sps.addNumber(3);
    sps.addNumber(17);
    sps.addNumber(9);
    sps.addNumber(11);
    std::cout << "----------Subject Test--------" << std::endl;
    std::cout << sps.shortestSpan() << std::endl;
    std::cout << sps.longestSpan() << std::endl << std::endl;

    std::cout << "----------10000 Test--------" << std::endl;
    // Add 10,000 random numbers to the Span
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; i++) {
        sp.addNumber(std::rand());
    }

    // Test the shortest and longest spans
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
   
    std::cout << std::endl << "----------Exception Test--------" << std::endl;
    try
    {
        sp.addNumber(1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Span sp2(1);
        std::cout << sp2.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << std::endl << "----------one call to addNumber Test--------" << std::endl;

    Span span(10);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    span.addNumber(vec.begin(), vec.end()); // Add a range of numbers

    std::cout << "Shortest Span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << span.longestSpan() << std::endl;
    

    return 0;
}