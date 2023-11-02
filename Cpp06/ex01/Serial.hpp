//
// Created by mtoia on 11/2/23.
//

#ifndef SERIAL_HPP
# define SERIAL_HPP

#include <iostream>
#include <stdlib.h>

typedef struct Data
{
    int	number;
}	Data;

class Serial {
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};


#endif
