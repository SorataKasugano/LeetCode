#pragma once
/*
350. Intersection of Two Arrays II
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.

Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you 
cannot load all elements into the memory at once? */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	// 1.hash
	vector<int> intersection;
	unordered_map<int, int> hash;
	for (auto iter1 : nums1) hash[iter1]++;
	for (auto iter2 : nums2) if (0<hash[iter2]--) intersection.push_back(iter2);
	return intersection;
	// 2.iterative
	//vector<int> intersection;
	//for (auto iter1 = nums2.begin();iter1!= nums2.end();iter1++)
	//{
	//	for (auto iter2 = nums1.begin();iter2!= nums1.end();iter2++)
	//	{
	//		if (*iter1 == *iter2)
	//		{
	//			intersection.push_back(*iter1);
	//			nums2.erase(iter1);
	//			iter1--;
	//			nums1.erase(iter2);
	//			iter2--;
	//			break;
	//		}
	//	}
	//}
	//return intersection;
	// 3.sort NOTE:isnot steady
	//vector<int> intersection;
	//sort(nums1.begin(), nums1.end());
	//sort(nums2.begin(), nums2.end());
	//for (int i = 0, j = 0;i < nums1.size(), j < nums2.size();)
	//{
	//	if (nums1[i] == nums2[j])
	//	{
	//		intersection.push_back(nums1[i]);
	//		i++;j++;
	//	}
	//	else if (nums1[i] > nums2[j]) j++;
	//	else i++;
	//}
	//return intersection;
}
