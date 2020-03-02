#include "AnyType.h"
#include <iostream>


int main()
{
	AnyType t1 = 23.0;
	std::cout << t1.Type();
	
	std::cin.get();
}