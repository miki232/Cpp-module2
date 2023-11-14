#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>
#include <climits>
#include <list>
#include <typeinfo>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<unsigned int> _v1;
        std::vector<unsigned int> _v2;

        std::deque<unsigned int> _d1;
        std::deque<unsigned int> _d2;

    public:
        bool flag;
        unsigned int tmp;
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(PmergeMe const & src);
        PmergeMe & operator=(PmergeMe const & rhs);
        void    print_before(char **argv);

        template <typename T>
        void    print_after(struct timeval &end, struct timeval &start, T &container);
        
        void    check_input(char *argv, char *argv1);
        
        void _vecSort(int len, char **sequence);
        void _dequesort(int len, char **sequence);

};




#endif
