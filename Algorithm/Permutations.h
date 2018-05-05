#pragma once
/*
46. Permutations
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
[1,2,3],
[1,3,2],
[2,1,3],
[2,3,1],
[3,1,2],
[3,2,1]
] */

#include <vector>
using namespace std;

// auxiliary recursive backtrack function
vector<vector<int>> aux_permute(vector<int> &nums, vector<bool> &lock, int lock_count, int anchor)
{
	if (anchor == nums.size() - 1) return vector<vector<int>>{ {nums[anchor]}};
	vector<vector<int>> rets;
	for (int i = 0, offset = 0;i<nums.size();i++)
	{
		if (lock[i]) continue;
		lock[i] = true;
		for (auto seq : aux_permute(nums, lock, lock_count + 1, anchor + 1))
		{
			seq.insert(seq.begin() + offset, nums[anchor]);
			rets.push_back(seq);
		}
		lock[i] = false;
		offset++;
	}
	return rets;
}

vector<vector<int>> permute(vector<int>& nums) {
	vector<bool> lock(nums.size());
	return aux_permute(nums, lock, 0, 0);
}
