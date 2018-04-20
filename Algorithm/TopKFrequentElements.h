#pragma once
/*
347. Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:

You may assume k is always valid, 1 ¡Ü k ¡Ü number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size. */

#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
	// 1.bucket sort
	unordered_map<int, int> map;
	vector<vector<int>> bucket(nums.size() + 1);
	vector<int> ret(k);
	for (auto it : nums) map[it]++;
	for (auto it : map) bucket[it.second].push_back(it.first);
	for (auto rit= bucket.rbegin();rit!=bucket.rend();rit++)
	{
		if (!rit->empty())
		{
			for (int i : *rit)
			{
				if (k) ret[--k] = i;
				else return ret;
			}
		}
	}
	return ret;

	// 2.1.heap sort(min-heap)
	//vector<int> ret;
	//unordered_map<int, int> map;
	//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
	//for (auto it : nums) map[it]++;
	//for (auto it : map)
	//{
	//	min_heap.push(make_pair(it.second, it.first));
	//	if (min_heap.size() > k) min_heap.pop();
	//}
	//while (!min_heap.empty())
	//{
	//	ret.push_back(min_heap.top().second);
	//	min_heap.pop();
	//}
	//return ret;

	// 2.2.heap sort(max-heap)
	//vector<int> ret;
	//unordered_map<int, int> map;
	//priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> max_heap;
	//for (auto it : nums) map[it]++;
	//for (auto it : map)
	//{
	//	max_heap.push(make_pair(it.second, it.first));
	//	if (max_heap.size() > map.size() - k)
	//	{
	//		ret.push_back(max_heap.top().second);
	//		max_heap.pop();
	//	}
	//}
	//return ret;

	// 3.quick sort
	//vector<int> ret;
	//unordered_map<int, int> map;
	//vector<pair<int, int>> vec;
	//for (auto it : nums) map[it]++;
	//for (auto it : map) vec.push_back(make_pair(it.second, it.first));
	//nth_element(vec.begin(), vec.end() - k, vec.end());
	//for (int ridx = vec.size() - 1, i = 0;i < k;ridx--, i++)
	//	ret.push_back(vec[ridx].second);
	//return ret;
}