#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <climits>

class ScalarConverter
{
    public:
        static void	convert(std::string input);

        class ErrorParameter : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif