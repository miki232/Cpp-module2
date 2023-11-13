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

class PmergeMe
{
    private:
        std::vector<std::pair<unsigned int, unsigned int> > _v;
        std::vector<unsigned int> _v1;
        std::vector<unsigned int> _v2;

        std::deque<std::pair<unsigned int, unsigned int> > _d;
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
        void    print_after(struct timeval &end, struct timeval &start, T &container, int argc);
        
        void    F_all(int argc, char **argv);
        void    check_input(char *argv, char *argv1);
        
        template <typename T, typename T1, typename T2>
        void    sort(T &container, T1 &container1, T2 &container2, struct timeval &start);
        
};




#endif
