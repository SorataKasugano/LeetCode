#include <iostream>
#include "FizzBuzz.h"
int main()
{
	vector<string> vec=fizzBuzz(20);
	for (auto iter : vec)
		cout << iter << endl;
	return 0;
}