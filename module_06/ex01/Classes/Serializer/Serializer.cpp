#include "Serializer.h"
#include "Classes/Serializer/Serializer.hpp"

Serializer::Serializer(void) {
    std::cout << "Serializer class default constructor called." << std::endl;
};

Serializer::Serializer(const Serializer& Serializer) {
    std::cout << "Serializer class copy constructor called." << std::endl;
    *this = Serializer;
};

Serializer& Serializer::operator=(const Serializer& rhs) {
    std::cout << "Serializer class copy assign operator called." << std::endl;
    if (this != &rhs){
        *this = rhs;
    }
    return *this;
};

Serializer::~Serializer(void) {
    std::cout << "Serializer class destructor called." << std::endl;
};

uintptr_t Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
};

Data* Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
};