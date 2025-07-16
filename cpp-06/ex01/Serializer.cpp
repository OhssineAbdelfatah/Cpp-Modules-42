#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::~Serializer() {
}

Serializer::Serializer(const Serializer& other) {
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other) {
    // Copy assignment operator implementation
    (void)other;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t value = reinterpret_cast <uintptr_t>(ptr);
    return value;
}

Data* Serializer::deserialize(uintptr_t value)
{
    Data* ptr = reinterpret_cast <Data*>(value);
    return ptr;
}
