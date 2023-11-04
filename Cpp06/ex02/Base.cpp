#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"

Base::~Base(){
    std::cout << "Base destructor called" << std::endl;
}

Base* generate(void){
    int random = rand() % 3;
    if (random == 0){
        std::cout << "Base_A Pointer genereted" << std::endl;
        return new BaseA;
    } else if (random == 1){
        std::cout << "Base_B Pointer genereted" << std::endl;
        return new BaseB;
    } else {
        std::cout << "Base_C Pointer generated" << std::endl;
        return new BaseC;
    }
}

void identify(Base* p){
    if (dynamic_cast<BaseA*>(p)){
        std::cout << "Base_A" << std::endl;
    } else if (dynamic_cast<BaseB*>(p)){
        std::cout << "Base_B" << std::endl;
    } else if (dynamic_cast<BaseC*>(p)){
        std::cout << "Base_C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p)
{
    try {
        BaseA& a = dynamic_cast<BaseA&>(p);
        std::cout << "Base_A" << std::endl;
        (void)a;
    } catch (std::bad_cast& e) {
        try {
            BaseB& b = dynamic_cast<BaseB&>(p);
            std::cout << "Base_B" << std::endl;
            (void)b;
        } catch (std::bad_cast& e) {
            try {
                BaseC& c = dynamic_cast<BaseC&>(p);
                std::cout << "Base_C" << std::endl;
                (void)c;
            } catch (std::bad_cast& e) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}