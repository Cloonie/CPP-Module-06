#include <iostream>
#include <ctime>
#include <cstdlib>

class Base
{
	public:
	virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return ((new A));
	else if (random == 1)
		return ((new B));
	else
		return ((new C));
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

// void identify(Base& p)
// {
// 	try
// 	{
// 		A& a = dynamic_cast<A&>(p);
// 	}
// 	catch
// 	void identify(Base& p) {
//     try {
//         A& a = dynamic_cast<A&>(p);
//         std::cout << "A" << std::endl;
//     } catch (std::bad_cast&) {
//         // If it's not an instance of A, try B.
//         try {
//             B& b = dynamic_cast<B&>(p);
//             std::cout << "B" << std::endl;
//         } catch (std::bad_cast&) {
//             // If it's not an instance of B, it must be C.
//             std::cout << "C" << std::endl;
//         }
//     }
// }

int main(void)
{
	Base *base;
	base = generate();
	identify(base);
}