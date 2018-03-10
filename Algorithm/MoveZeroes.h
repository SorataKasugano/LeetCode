#pragma once
/*
283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining 
the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, 
nums should be [1, 3, 12, 0, 0].

Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.*/

#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
	int index = 0;
	for (int i = 0;i<nums.size();i++)
	{
		if (nums[i])
		{
			if (i != index)// for spiecial cases like [1, 3, 5, 6, 0, 7]
			{
				nums[index] = nums[i];
				nums[i] = 0;
			}
			index++;
		}
	}
}
