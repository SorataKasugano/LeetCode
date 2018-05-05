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

// 1.recursive backtrack
//// auxiliary recursive backtrack function
//vector<vector<int>> aux_permute(vector<int> &nums, vector<bool> &lock, int anchor)
//{
//	if (anchor == nums.size() - 1) return vector<vector<int>>{ {nums[anchor]}};
//	vector<vector<int>> rets;
//	for (int i = 0, offset = 0;i<nums.size();i++)
//	{
//		if (lock[i]) continue;
//		lock[i] = true;
//		for (auto seq : aux_permute(nums, lock, anchor + 1))
//		{
//			seq.insert(seq.begin() + offset, nums[anchor]);
//			rets.push_back(seq);
//		}
//		lock[i] = false;
//		offset++;
//	}
//	return rets;
//}
//
//vector<vector<int>> permute(vector<int>& nums) {
//	vector<bool> lock(nums.size());
//	return aux_permute(nums, lock, 0);
//}

// 2.iterative dp
/* state transition equation:
*  dp[i][j]=dp[i-1][j/(i+1)].insert(dp[i-1][j/(i+1)].begin()+j%(i+1),nums[count-i-1]); */
vector<vector<int>> permute(vector<int>& nums) {
	int count = nums.size();
	if (!count) return vector<vector<int>>();
	vector<vector<int>> dp_next, dp_prev{ {nums[count - 1]} };// dp_next->dp[i],dp_prev->dp[i-1]
	vector<int> temp;// temp duplicate to insert
	for (int i = 1;i < count;i++)
	{
		dp_next.resize((i + 1)*dp_prev.size());
		for (int j = 0, offset;j < dp_next.size();j++)
		{
			temp = dp_prev[j / (i + 1)];
			offset = j % (i + 1);
			temp.insert(temp.begin() + offset, nums[count - i - 1]);
			dp_next[j] = temp;
		}
		dp_prev = dp_next;
	}
	return dp_next;
}