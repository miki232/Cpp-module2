#include "Span.hpp"

Span::Span(): _n(0)
{
}

Span::Span(unsigned int n): _n(n)
{
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span::~Span()
{
}

Span & Span::operator=(const Span &copy)
{
    _n = copy._n;
    _v = copy._v;
    return (*this);
}

void Span::addNumber(int n)
{
    if (_v.size() == _n)
        throw Span::FullException();
    _v.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
    if (_v.size() + std::distance(first, last) > _n)
        throw FullException();
    while (first != last && _v.size() < _n)
    {
        addNumber(*first);
        first++;
    }
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw NoSpanException();
    std::vector<int> sorted_v = _v;
    std::sort(sorted_v.begin(), sorted_v.end());
    int min = sorted_v[1] - sorted_v[0];
    for (size_t i = 2; i < sorted_v.size(); i++)
    {
        if (sorted_v[i] - sorted_v[i - 1] < min)
            min = sorted_v[i] - sorted_v[i - 1];
    }
    return (min);
}

int Span::longestSpan()
{
    if (_v.size() < 2)
        throw NoSpanException();
    std::vector<int> sorted_v = _v;
    std::sort(sorted_v.begin(), sorted_v.end());
    return (sorted_v[sorted_v.size() - 1] - sorted_v[0]);
}

const char *Span::FullException::what() const throw()
{
    return ("Span limit reached!");
}

const char *Span::NoSpanException::what() const throw()
{
    return ("Span has no span");
}