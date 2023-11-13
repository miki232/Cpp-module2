#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

class RPN
{
    private:
        std::stack<int> _numbers;
    public:
        RPN(std::string input);
        RPN(RPN const &copy);
        RPN &operator=(RPN const &copy);
        ~RPN();
        bool is_operator(const std::string& token);
        bool perform_operation(std::stack<int>& numbers, const std::string& op);
        int get_result();
        int get_result_size();
};

#endif