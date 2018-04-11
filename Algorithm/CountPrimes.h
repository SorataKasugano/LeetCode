#pragma once
/*
204. Count Primes
Description:

Count the number of prime numbers less than a non-negative number, n. */

#include <vector>
using namespace std;

int countPrimes(int n) {
	if (n<3) return 0;
	vector<bool> b(n - 1, true);
	b[0] = false;
	for (int i = 1;i < n - 1;i++)
	{
		if (b[i] == true)
		{
			for (int j = 2 * i + 1;j < n;j += i + 1)
			{
				b[j] = false;
			}
		}
	}
	int ret = 0;
	for (int i = 0;i < n - 1;i++) if (b[i]) ret++;
	return ret;
}