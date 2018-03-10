#pragma once
/*
136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/

#include <vector>
#include <string>
using namespace std;

int singleNumber(vector<int>& nums) {
	int ret = 0;
	for (auto iter : nums)
	{
		ret ^= iter;// XOR(^):return 1(0) on which bit the two operand are different(same)
	}
	return ret;
}