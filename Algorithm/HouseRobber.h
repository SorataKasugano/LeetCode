#pragma once
/*
198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a 
certain amount of money stashed, the only constraint stopping you from robbing each of 
them is that adjacent houses have security system connected and it will automatically 
contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police. */

#include <vector>
#include <algorithm>
using namespace std;

// 1. iterative
int rob(vector<int>& nums) {
	if (nums.empty()) return 0;
	vector<int> dp{ 0,nums[0] };
	for (int i = 2;i<nums.size() + 1;i++)
	{
		dp.push_back(max(dp[i - 1], nums[i - 1] + dp[i - 2]));
	}
	return dp[nums.size()];
}

// 2. recursive
//int rob(vector<int>& nums) {
//	return rob(nums, nums.size());
//}
//
//int rob(vector<int>& nums, int n)
//{
//	if (n == 0) return 0;
//	if (n == 1) return nums[0];
//	return max(rob(nums, n - 1), nums[n - 1] + rob(nums, n - 2));
//}