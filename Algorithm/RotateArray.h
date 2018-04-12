#pragma once
/*
189. Rotate Array
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint:
Could you do it in-place with O(1) extra space? */

#include <vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
	if (nums.empty()) return;
	int offset = k%nums.size();
	nums.insert(nums.begin(), nums.end() - offset, nums.end());
	nums.erase(nums.end() - offset, nums.end());
}