#include "ScalarConverter.hpp"

int	psliterals(std::string input)
{
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
		return (1);
	return (0);
}


int isChar(std::string input)
{
	if (input.length() == 1)
	{
		if (isprint(input[0]) && !isdigit(input[0]))
			return (1);
	}
	return (0);
}

int isInt(std::string input)
{
	int i = 0;
	while (input[i] == '+' || input[i] == '-')
		i++;
	if (i > 1)
		return (0);
	while (input[i])
	{
		if (!isdigit(input[i++]))
			return (0);
	}
	return (1);
}

bool isFloat(std::string input)
{
    int i = 0;

    if (*(input.end() - 1) == 'f')
    {
        int dot = input.find(".");
        if (input[i] == '+' || input[i] == '-')
            i++;

        int dotCount = 0;
        int start = i;

        for (int j = 0; j < input.length(); ++j)
        {
            if (input[j] == '.')
            {
                dotCount++;
                if (dotCount > 1)
                {
                    return false;
                }
                dot = j;
            }
        }

        if (dot != std::string::npos && dotCount == 1)
        {
            for (int j = start; j < dot; ++j)
            {
                if (!isdigit(input[j]))
                {
                    return false;
                }
            }

            for (int j = dot + 1; j < input.length() - 1; ++j)
            {
                if (!isdigit(input[j]))
                {
                    return false;
                }
            }

            return true;
        }
    }

    return false;
}


bool isDouble(std::string input) {
    int dotCount = 0;
    int i = 0;
    int dotIndex = input.find(".");

    if (input[i] == '+' || input[i] == '-') {
        i++;
    }

    for (int j = i; j < dotIndex; ++j) {
        if (!isdigit(input[j])) {
            return false;
        }
    }

    for (int j = dotIndex + 1; j < input.length(); ++j) {
        if (!isdigit(input[j])) {
            return false;
        }
    }

    for (int j = 0; j < input.length(); ++j) {
        if (input[j] == '.') {
            dotCount++;
            if (dotCount > 1) {
                return false;
            }
        }
    }

    return dotCount == 1;
}

void ScalarConverter::convert(std::string input)
{
	if (psliterals(input))
	{
		if (input == "nan" || input == "nanf")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (input == "+inf" || input == "+inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (input == "-inf" || input == "-inff")
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}
	else if (isChar(input))
	{
		char c = static_cast<char>(input[0]);
		std::cout << "char : " << input[0] << std::endl;
		std::cout << "int : " << static_cast<int>(c) << std::endl;
		std::cout << "float : " << static_cast<float> (c) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(c) << ".0" << std::endl;
	}
	else if (isInt(input))
	{
		int value = atoi(input.c_str());
		try
		{
			if (isprint(value))
				std::cout << "char : " << static_cast<char> (value) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			std::cout << "int : " << value << std::endl;
			std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
			std::cout << std::fixed << "double : " << std::setprecision(1) << static_cast<double>(value) << std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << "Caught an Exception : " << e.what() << std::endl;

		}
	}
	else if (isFloat(input))
	{
		float value;
		try
		{
			value = atof(input.c_str());
			if (isprint(value) && value != 0)
				std::cout << "char : " << static_cast<char>(value) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			if (value <= INT_MAX && value >= INT_MIN)
				std::cout << "int : " << static_cast<int>(value) << std::endl;
			else
				std::cout << "int : impossible" << std::endl;
			if (value - static_cast<int>(value) == 0)
			{
				std::cout << "float: " << value << ".0f" << std::endl;
				std::cout << "double : " << static_cast<double> (value) << ".0" << std::endl;
			}
			else
			{
				std::cout << "float : " << value << "f" << std::endl;
				std::cout << "double : " << static_cast<double> (value) << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << "Caught an Exception : " << e.what() << std::endl;
		}
	}
	else if (isDouble(input))
	{
		double value;
		try
		{
			value = atof(input.c_str());
			if (isprint(value) && value != 0)
				std::cout << "char : " << static_cast<char> (value) << std::endl;
			else
				std::cout << "char : impossible" << std::endl;
			if (value <= INT_MAX && value >= INT_MIN)
				std::cout << "int : " << static_cast<int>(value) << std::endl;
			else
				std::cout << "int : impossible" << std::endl;
			if (value - static_cast<int>(value) == 0)
			{
				std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
				std::cout << "double : " << value << ".0" << std::endl;
			}
			else
			{
				std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
				std::cout << "double : " << value << std::endl;
			}
		}
		catch(std::exception &e)
		{
			std::cout << "Caught an Exception : " << e.what() << std::endl;
		}
	}
	else
		throw ScalarConverter::ErrorParameter();
}

const char* ScalarConverter::ErrorParameter::what() const throw()
{
	return ("Error Parameter : Invalid input");
}
