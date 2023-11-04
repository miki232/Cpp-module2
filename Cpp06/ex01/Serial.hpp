//
// Created by mtoia on 11/2/23.
//

#ifndef SERIAL_HPP
# define SERIAL_HPP

#include <iostream>
#include <stdlib.h>
#include "Data.hpp"

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer& src);
    public:
        Serializer& operator=(const Serializer& rhs);
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif
