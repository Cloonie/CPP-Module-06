#include "Serialize.hpp"

int	main(void)
{
	Data data("Ash", 18);
	std::cout << "Name: " << data.name << " | Age: " << data.age << std::endl;

	uintptr_t serializedPtr = Serialize::serialize(&data);
	Data *deserializedPtr = Serialize::deserialize(serializedPtr);

	std::cout << &data << std::endl;
	std::cout << &serializedPtr << std::endl;
	std::cout << deserializedPtr << std::endl;

	if (deserializedPtr == &data)
		std::cout << "Serialization and deserialization worked correctly!" << std::endl;
	else
		std::cout << "Serialization and deserialization failed!" << std::endl;
}