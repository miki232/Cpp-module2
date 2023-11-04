#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *arg1, int arr_len, void (*f)(T &))
{
    for (int i = 0; i < arr_len; i++)
        f(arg1[i]);
}

#endif