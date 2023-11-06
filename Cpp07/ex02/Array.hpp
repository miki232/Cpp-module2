#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template <typename T>
class Array
{
    private:
        T* _array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& copy);
        Array& operator=(const Array& copy);
        ~Array();
        T& operator[](unsigned int i);
        unsigned int size() const;
    class OutOfBoundsException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Out of bounds Exception Thrown!");
            }
    };
};

# include "Array.tpp"

#endif