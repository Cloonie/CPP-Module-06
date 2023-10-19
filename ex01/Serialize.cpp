#include "Serialize.hpp"

Serialize::Serialize() {}
Serialize::~Serialize() {}
Serialize::Serialize(const Serialize& ref) {
	*this = ref;
}
Serialize& Serialize::operator=(const Serialize& ref) {
	(void)ref;
	return (*this);
}

// It takes a pointer and converts it to the unsigned integer type uintptr_t.
uintptr_t Serialize::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

// It takes an unsigned integer parameter and converts it to a pointer to Data.
Data* Serialize::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}