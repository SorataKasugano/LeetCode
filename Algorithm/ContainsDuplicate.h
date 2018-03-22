#pragma once
/*
217. Contains Duplicate
Given an array of integers, find if the array contains any duplicates. Your function should 
return true if any value appears at least twice in the array, and it should return false if 
every element is distinct. */

#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
	unordered_map<int, int> hash;
	for (auto iter : nums)
	{
		if (++hash[iter]>1)
			return true;
	}
	return false;
}