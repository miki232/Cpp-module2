#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    if ((argc - 1) % 2 != 0)
    {
        this->flag = true;
        this->tmp = std::atoi(argv[argc - 1]);
        if (std::atoi(argv[argc - 1]) < 0 || isalpha(*argv[argc - 1]))
        {
            std::cout << "Error: " << argv[argc - 1] << " is not a valid number" << std::endl;
            exit(1);
        }
        argc -= 1;
    }

    this->print_before(argv);
    this->F_all(argc, argv);
    struct timeval  start, end;

    this->sort(argc, argv, this->_v, this->_v1, this->_v2, start);
    this->print_after(start, end, this->_v2);
    
    this->sort(argc, argv, this->_d, this->_d1, this->_d2, start);
    this->print_after(start, end, this->_d2);
}

template <typename T>
void    PmergeMe::print_after(struct timeval &start, struct timeval &end, T &container)
{
    std::cout << "After: ";

    for (size_t i = 0; i < container.size(); i++)
        std::cout << container[i] << " ";
    
    std::cout << std::endl;
    long            seconds, useconds;
    gettimeofday(&end, NULL);
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    long    mtime = (seconds / 1000000) + useconds;
    
    if (typeid(container) == typeid(std::vector<unsigned int>)) // if deque
        std::cout << std::endl << "Time to process a range of " << container.size() << " elements with std::vector : " << mtime << " us " << std::endl;
    else
        std::cout << std::endl << "Time to process a range of " << container.size() << " elements with std::deque : " << mtime << " us " << std::endl;


}

template <typename T, typename T1, typename T2>
void    PmergeMe::sort(int argc, char **argv, T &container, T1 &container1, T2 &container2, struct timeval &start)
{

    gettimeofday(&start, NULL);
    for (size_t i = 0; i < container.size(); i++)
    {
        if (container[i].first > container[i].second)
            std::swap(container[i].first, container[i].second);
    }
    for (size_t i = 0; i < container.size(); i++)
        container2.push_back(container[i].first);
    for (size_t i = 0; i < container.size(); i++)
        container1.push_back(container[i].second);
    
    std::sort(container2.begin(), container2.end());

    for (size_t i = 0; i < container1.size(); i++)
        container2.insert(std::lower_bound(container2.begin(), container2.end(), container1[i]), container1[i]);
    if (this->flag)
        container2.insert(std::lower_bound(container2.begin(), container2.end(), this->tmp), this->tmp);
}

void    PmergeMe::F_all(int argc, char **argv)
{
    for (int i = 1; i < argc; i+=2)
    {
        if (isdigit(*argv[i]))
        {
            this->check_input(argv[i], argv[i + 1]);
            this->_v.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
        }
    }
    for (size_t i = 1; i < argc; i+=2)
    {
        if (isdigit(*argv[i]))
        {
            this->check_input(argv[i], argv[i + 1]);
            this->_d.push_back(std::make_pair(std::atoi(argv[i]), std::atoi(argv[i + 1])));
        }
    }
    
}

void    PmergeMe::check_input(char *argv, char *argv1)
{
    if (std::atoi(argv) < 0 || std::atoi(argv1) < 0 || isalpha(*argv) || isalpha(*argv1))
    {
        std::cout << "Error: " << argv << " or " << argv1 << " is not a valid number" << std::endl;
        exit(1);
    }
}

void    PmergeMe::print_before(char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; argv[i]; i++)
    {
        if (i > 20)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    if (this != &rhs)
    {
        this->_v = rhs._v;
        this->_v1 = rhs._v1;
        this->_v2 = rhs._v2;
        this->_d = rhs._d;
        this->_d1 = rhs._d1;
        this->_d2 = rhs._d2;
        this->flag = rhs.flag;
        this->tmp = rhs.tmp;
    }
    return *this;
}
