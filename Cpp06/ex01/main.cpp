//
// Created by mtoia on 11/2/23.
//

#include "Serial.hpp"

int	main(int argc, char** argv)
{
    Data origin;
    Data *destination;
    uintptr_t result;

    origin.number = 42;

    try
    {
        result = Serial::serialize(&origin);
        destination = Serial::deserialize(result);
        std::cout << "Origin serialized: " << origin.number << std::endl;
        std::cout << "Destination deserialize: " << destination->number << std::endl;
        std::cout << "reinterpret_cast success. " << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Fail." << std::endl;

    }
}
