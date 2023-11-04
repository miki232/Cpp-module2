#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    Base *base = generate();
    identify(base);
    delete base;
    Base &ref = *generate();
    identify(ref);
    return 0;
}
