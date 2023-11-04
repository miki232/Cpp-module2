//
// Created by mtoia on 11/2/23.
//

#include <iostream>
#include "Serial.hpp"
#include "Data.hpp"

int main() {
    Data data;
    data.value = 42;

    uintptr_t serializedPtr = Serializer::serialize(&data);
    Data* deserializedPtr = reinterpret_cast<Data*>(Serializer::deserialize(serializedPtr));

    std::cout << "data.value: " << data.value << std::endl;
    std::cout << "deserializedPtr->value: " << deserializedPtr->value << std::endl;

    if (deserializedPtr == &data) {
        std::cout << "Serialization and deserialization successful. Pointers match." << std::endl;
    } else {
        std::cout << "Serialization or deserialization failed. Pointers do not match." << std::endl;
    }

    return 0;
}
