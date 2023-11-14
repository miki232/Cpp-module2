#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv)
{
    this->flag = false;
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
    else if (argc == 1)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    
    for (int i = 1; i < argc - 1; i+=2)
        this->check_input(argv[i], argv[i+1]);
    
    this->print_before(argv);
    struct timeval  start, end;

    gettimeofday(&start, NULL);
    this->_vecSort(argc - 1, argv);
    this->print_after(start, end, this->_v2);
    struct timeval  start1, end1;
    gettimeofday(&start1, NULL);
    this->_dequesort(argc - 1, argv);
    this->print_after(start1, end1, this->_d2);
}

template <typename T>
void    PmergeMe::print_after(struct timeval &start, struct timeval &end, T &container)
{
    gettimeofday(&end, NULL);
    
    std::cout << std::endl;
    long            seconds, useconds;
    seconds = end.tv_sec - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    long    mtime = (seconds * 1000000) + useconds;
    
    double time_in_us = mtime / 1000000.0;

    if (typeid(container) == typeid(std::vector<unsigned int>))
    {
        std::cout << "After: ";
        for (size_t i = 0; i < container.size(); i++)
            std::cout << container[i] << " ";
        std::cout << std::fixed << std::setprecision(5) << std::endl << "Time to process a range of " << container.size() << " elements with std::vector : " << time_in_us << " us " << std::endl;
    }
    else
        std::cout << std::fixed << std::setprecision(5) << std::endl << "Time to process a range of " << container.size() << " elements with std::deque : " << time_in_us << " us " << std::endl;
}

void PmergeMe::_vecSort(int len, char **sequence)
{
    if (flag == true)
    {
        len++;
    }
    for (int i = 0; i < len; i++)
		this->_v1.push_back(std::strtol(sequence[i+1], NULL, 10));
	bool isStraggler = false;
	long straggler = 0;
	if (len % 2) {
		isStraggler = true;
		straggler = this->_v1.back();
		this->_v1.pop_back();
	}

	std::vector<std::pair<unsigned, unsigned> > pairs;
	for (std::vector<unsigned>::iterator it = this->_v1.begin(); it != this->_v1.end(); it +=2)
		pairs.push_back(std::make_pair(*it, *(it+1)));
	for (std::vector<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			std::swap(it->first, it->second);
	for (std::vector<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		for (std::vector<std::pair<unsigned, unsigned> >::iterator jt = it; jt != pairs.end(); jt++)
			if (it->first > jt->first)
				std::swap(*it, *jt);
	for (std::vector<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::vector<unsigned>::iterator jt = std::lower_bound(this->_v2.begin(), this->_v2.end(), it->first);
		this->_v2.insert(jt, it->first);
		jt = std::lower_bound(this->_v2.begin(), this->_v2.end(), it->second);
		this->_v2.insert(jt, it->second);
	}
	if (isStraggler)
	{
		std::vector<unsigned>::iterator jt = std::lower_bound(this->_v2.begin(), this->_v2.end(), straggler);
		this->_v2.insert(jt, straggler);
	}
}

void PmergeMe::_dequesort(int len, char **sequence)
{
    if (flag == true)
    {
        len++;
    }
    for (int i = 0; i < len; i++)
		this->_d1.push_back(std::strtol(sequence[i+1], NULL, 10));
	bool isStraggler = false;
	long straggler = 0;
	if (len % 2) {
		isStraggler = true;
		straggler = this->_d1.back();
		this->_d1.pop_back();
	}

	std::deque<std::pair<unsigned, unsigned> > pairs;
	for (std::deque<unsigned>::iterator it = this->_d1.begin(); it != this->_d1.end(); it +=2)
		pairs.push_back(std::make_pair(*it, *(it+1)));
	for (std::deque<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		if (it->first > it->second)
			std::swap(it->first, it->second);
	for (std::deque<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++)
		for (std::deque<std::pair<unsigned, unsigned> >::iterator jt = it; jt != pairs.end(); jt++)
			if (it->first > jt->first)
				std::swap(*it, *jt);
	for (std::deque<std::pair<unsigned, unsigned> >::iterator it = pairs.begin(); it != pairs.end(); it++) {
		std::deque<unsigned>::iterator jt = std::lower_bound(this->_d2.begin(), this->_d2.end(), it->first);
		this->_d2.insert(jt, it->first);
		jt = std::lower_bound(this->_d2.begin(), this->_d2.end(), it->second);
		this->_d2.insert(jt, it->second);
	}
	if (isStraggler)
	{
		std::deque<unsigned>::iterator jt = std::lower_bound(this->_d2.begin(), this->_d2.end(), straggler);
		this->_d2.insert(jt, straggler);
	}
}

void    PmergeMe::check_input(char *argv, char *argv1)
{
    if (std::atoi(argv) < 0 || isalpha(*argv))
    {
        std::cout << "Error: " << argv << " is not a valid number" << std::endl;
        exit(1);
    }
    if (std::atoi(argv1) < 0 || isalpha(*argv1))
    {
        std::cout << "Error: " << argv1 << " is not a valid number" << std::endl;
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
        this->_v1 = rhs._v1;
        this->_v2 = rhs._v2;
        this->_d1 = rhs._d1;
        this->_d2 = rhs._d2;
        this->flag = rhs.flag;
        this->tmp = rhs.tmp;
    }
    return *this;
}
