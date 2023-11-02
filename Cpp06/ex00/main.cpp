#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    int i;
    if (argc != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return (1);
    }

    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return (0);
}