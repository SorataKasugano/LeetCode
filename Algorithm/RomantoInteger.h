#pragma once
/*
13. Roman to Integer
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.*/

#include <string>
#include <map>
using namespace std;

int romanToInt(string s) {
	map<char, int> mapHash = { { 'I',1 },{ 'V',5 },{ 'X',10 },{ 'L',50 },{ 'C',100 },{ 'D',500 },{ 'M',1000 } };
	int curr, prev, ret = mapHash[*s.rbegin()];
	// right add has no condition but left minus has
	for (auto riter = s.rbegin() + 1;riter != s.rend();riter++)
	{
		curr = mapHash[*riter]; prev = mapHash[*(riter - 1)];
		(curr<prev) ? (ret -= curr) : (ret += curr);
	}
	return ret;
}