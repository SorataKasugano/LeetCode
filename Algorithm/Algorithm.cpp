#include <iostream>
#include "ReverseInteger.h"

int main()
{
	std::cout << reverse(int(0x7fffffff/*80000000*/));
	//7463847412 2147483647
	return 0;
}