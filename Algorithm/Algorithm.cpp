#include <iostream>
#include "FirstUniqueCharacterinaString.h"

int main()
{
	int n = 10;
	int* dp = new int[n + 1]{ 0,1,2 };
	cout << dp[1] << dp[2] << endl;
	string s("loveleetcode");
	cout << firstUniqChar(s) << endl;
	return 0;
}