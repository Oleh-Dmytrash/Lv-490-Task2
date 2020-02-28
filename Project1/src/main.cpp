#include "AnyType.h"
#include <iostream>


int main()
{
	bool d = false;
	double k = d;
	if (k) std::cout << "hi";
	AnyType a(2);
	a = true;
	a = 2.7;
	AnyType b = 22;
	AnyType c = std::move(b);
	std::cout << c.ToInt() << " ";
	std::cout << b.ToInt() << "\n";
	c = 23;
	std::cout << c.ToInt() << " ";
	std::cout << b.ToInt() << "\n";
	a.Swap(b);
	try
	{
		std::cout << a.ToBool() << "\n";
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what();
	}
	std::cout << b.ToDouble();
	
	
	std::cin.get();
}