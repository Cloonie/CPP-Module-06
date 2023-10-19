#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
	std::string	name;
	int			age;

	Data(std::string name, int age) : name(name), age(age) {}
};

class Serialize // static class
{
	// From Module 02 to Module 09, your classes must be designed in the Orthodox
	// Canonical Form, except when explicitely stated otherwise

	// The reason is because i do not need to create a object of this class for testing.
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};