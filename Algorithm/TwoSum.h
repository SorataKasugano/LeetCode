#pragma once
/*
1. Two Sum
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. */

#include <vector>
#include <map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	// 1.iterative
	for (int first = 0;first<nums.size();first++)
	{
		for (int second = first + 1;second<nums.size();second++)
		{
			if (nums[first] + nums[second] == target)
				return vector<int>{first, second};
		}
	}
	// 2.hash
	//map<int, int> hash;
	//for (int index = 0;index<nums.size();index++)
	//{
	//	int complement = target - nums[index];
	//	if (hash[complement]) return vector<int>{hash[complement] - 1, index};
	//	else hash[nums[index]] = index + 1;
	//}
}