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
	public:
		Serialize();
		~Serialize();
		Serialize(const Serialize& ref);
		Serialize& operator=(const Serialize& ref);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};