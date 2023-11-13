#include <iostream>
#include <stack>
#include <sstream>
#include "RPN.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Error: Please provide an inverted Polish mathematical expression as an argument." << std::endl;
        return EXIT_FAILURE;
    }
    RPN rpn(argv[1]);

    // if (rpn.get_result_size()  == 1) {
    //     std::cout << "Result: " << rpn.get_result() << std::endl;
    //     return EXIT_SUCCESS;
    // } else {
    //     std::cerr << "Error: Invalid expressssion" << std::endl;
    //     return EXIT_FAILURE;
    // }
}
