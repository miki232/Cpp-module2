#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <iostream>
#include <ctime>

class BaseFail : public Base
{
};

int main()
{
    std::srand(std::time(0));
    Base *base = generate();
    identify(base);
    delete base;
    Base &ref = *generate();
    identify(ref);

    std::cout << std::endl;
    std::cout << "------- Testing to fail -------" << std::endl;
    Base *nullBase = new BaseFail;
    identify(nullBase);
    delete nullBase;
    Base &nullRef = *new BaseFail;
    identify(nullRef);
    return 0;
}
