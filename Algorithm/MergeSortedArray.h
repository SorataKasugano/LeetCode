#pragma once
/*
88. Merge Sorted Array
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold
additional elements from nums2. The number of elements initialized in nums1 and nums2 are m
and n respectively. */

#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// 1.insert and sort
	nums1.insert(nums1.begin() + m, nums2.begin(), nums2.begin() + n);
	nums1.erase(nums1.begin() + m + n, nums1.end());
	sort(nums1.begin(), nums1.end());
	// 2.traverse and insert
	//int i1, i2;
	//for (i1 = i2 = 0;i1 < m + i2 && i2 < n;i1++)
	//	if (nums2[i2] < nums1[i1]) nums1.insert(nums1.begin() + i1, nums2[i2++]);
	//if (i2 < n) nums1.insert(nums1.begin() + i1, nums2.begin() + i2, nums2.begin() + n);
	//nums1.erase(nums1.begin() + m + n, nums1.end());
	// 3.reverse traverse and replace
	//nums1.erase(nums1.begin() + m + n, nums1.end());
	//int i = m + n - 1, i1 = m - 1, i2 = n - 1;
	//while (i2 > -1) nums1[i--] = i1 > -1 && nums1[i1] > nums2[i2] ? nums1[i1--] : nums2[i2--];
}