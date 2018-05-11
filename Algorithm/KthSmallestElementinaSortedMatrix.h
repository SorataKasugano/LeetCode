#pragma once
/*
378. Kth Smallest Element in a Sorted Matrix
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
[ 1,  5,  9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,

return 13.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü n2. */

#include <vector>
#include <queue>
#include <functional>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
	// 1.heap-sort(max heap)
	//priority_queue<int> max_heap;
	//for (int i = 0;i < matrix.size();i++)
	//{
	//	for (int j = 0;j < matrix.size();j++)
	//	{
	//		max_heap.push(matrix[i][j]);
	//		if (max_heap.size() > k) max_heap.pop();
	//	}
	//}
	//return max_heap.top();
	// 2.quick-sort
	vector<int> arr;
	for (int i = 0;i < matrix.size();i++)
		arr.insert(arr.end(), matrix[i].begin(), matrix[i].end());
	function<void(vector<int>&, int, int)> quick_sort =
		[&quick_sort](vector<int> &arr, int start, int end) {
		if (start == end) return;
		int i = start, j = end, anchor = arr[start];
		while (true)
		{
			while (arr[i] < anchor) i++;
			while (arr[j] > anchor) j--;
			if (i >= j) break;
			swap(arr[i], arr[j--]);
		}
		quick_sort(arr, start, i);
		quick_sort(arr, j + 1, end);
	};
	quick_sort(arr, 0, arr.size() - 1);
	return arr[k - 1];
}