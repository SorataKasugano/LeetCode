#pragma once
/*
169. Majority Element
Given an array of size n, find the majority element.
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.*/

#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
	int major, count = 0;
	for (auto iter : nums)
	{
		if (count == 0) major = iter;
		iter == major ? count++ : count--;// works steady in only one case when the number of majority >= n/2
	}
	return major;
}