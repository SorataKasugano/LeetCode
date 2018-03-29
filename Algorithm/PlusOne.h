#pragma once
/*
66. Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list. */

#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
	for (auto riter = digits.rbegin();;riter++)
	{
		if (++(*riter)>9)
		{
			*riter = 0;
			if (riter == digits.rend() - 1)
			{
				digits.insert(digits.begin(), 1);
				break;
			}
		}
		else break;
	}
	return digits;
}