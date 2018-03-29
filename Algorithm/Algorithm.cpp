#include <iostream>
#include "PlusOne.h"

int main()
{
	vector<int> vec{ 0 };
	vec = plusOne(vec);
	for (auto i : vec)
	{
		cout << i << endl;
	}
	return 0;
}