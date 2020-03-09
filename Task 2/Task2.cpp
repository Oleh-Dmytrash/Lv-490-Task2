#include"AnyType.h"

int main()
{
	AnyType a = 1LL;
	a.ToDouble();
	std::cout << a.ToDouble();
	return 0;
}

