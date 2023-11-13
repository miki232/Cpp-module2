#include "RPN.hpp"

RPN::RPN(std::string input)
{
    std::stack<int> numbers;
    std::istringstream expression(input);
    std::string token;

    while (expression >> token) {
        if (RPN::is_operator(token)) {
            if (!RPN::perform_operation(numbers, token)) {
                return;
            }
        } else {
            int num;
            std::istringstream(token) >> num;
            numbers.push(num);
        }
    }
    std::cout << numbers.top() << std::endl;
}

RPN::RPN(RPN const &copy)
{
    *this = copy;
}

RPN &RPN::operator=(RPN const &copy)
{
    if (this != &copy)
    {
        this->_numbers = copy._numbers;
    }
    return (*this);
}

RPN::~RPN()
{
    
}

bool RPN::is_operator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::perform_operation(std::stack<int>& numbers, const std::string& op)
{
    if (numbers.size() < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }

    int operand2 = numbers.top();
    numbers.pop();

    int operand1 = numbers.top();
    numbers.pop();

    int result;

    if (op == "+") {
        result = operand1 + operand2;
    } else if (op == "-") {
        result = operand1 - operand2;
    } else if (op == "*") {
        result = operand1 * operand2;
    } else if (op == "/") {
        if (operand2 == 0) {
            std::cerr << "Error: Division by zero" << std::endl;
            return false;
        }
        result = operand1 / operand2;
    }

    numbers.push(result);
    return true;
}

int RPN::get_result()
{
    return this->_numbers.top();
}

int RPN::get_result_size()
{
    return this->_numbers.size();
}