#pragma once
/*
171. Excel Sheet Column Number
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28*/

#include <string>
using namespace std;

int titleToNumber(string s) {
	int factor = 1, ret = 0;
	for (auto iter = s.rbegin();iter != s.rend();iter++)
	{
		ret += factor*(*iter - 'A' + 1);
		factor *= 26;// in fact it as same as bin oct dec hex...
	}
	return ret;
}