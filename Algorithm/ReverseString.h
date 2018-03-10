#pragma once

/*
344.Reverse String
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".*/

#include <string>
using namespace std;

string reverseString(string s) {
	//1.
	int end = s.length() - 1, cycles = s.length() / 2;
	char tmp;
	for (int i = 0;i<cycles;i++)
	{
		tmp = s[i];s[i] = s[end - i];s[end - i] = tmp;
	}
	return s;
	//2.
	//string ret;
	//for (auto riter = s.rbegin();riter != s.rend();riter++)
	//	ret.push_back(*riter);
	//return ret;
	//3.
	//reverse(s.begin(), s.end());
	//return s;
}