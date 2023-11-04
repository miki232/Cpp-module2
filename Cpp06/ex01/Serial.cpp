//
// Created by mtoia on 11/2/23.
//

#include "Serial.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& src)
{
    *this = src;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

