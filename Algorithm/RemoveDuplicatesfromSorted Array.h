#pragma once
/*
26. Remove Duplicates from Sorted Array
Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example:

Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length. */

#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) return 0;
	int anchor = nums[0], len = 1;
	for (int i = 1;i<nums.size();i++)
	{
		if (nums[i] != anchor)
		{
			nums[len] = anchor = nums[i];
			len++;
		}
	}
	return len;
}