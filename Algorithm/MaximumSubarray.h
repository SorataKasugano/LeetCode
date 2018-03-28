#pragma once
/*
53. Maximum Subarray
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.
More practice:

If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, 
which is more subtle. */

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int maxSubArray(vector<int>& nums) {
	if (nums.empty()) return 0;
	int sum = nums[0], ret = nums[0];
	for (int index = 1;index<nums.size();index++)
	{
		if (sum<0) sum = nums[index];
		else sum += nums[index];
		if (sum>ret) ret = sum;
	}
	return ret;
}