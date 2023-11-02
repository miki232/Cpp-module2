//
// Created by mtoia on 11/2/23.
//

#include "Serial.hpp"

uintptr_t Serial::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serial::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

