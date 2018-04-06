#pragma once
/*
28. Implement strStr()
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1 */

#include <string>
#include <unordered_map>
using namespace std;

int strStr(string haystack, string needle) {
	// 1.hash
	int len = needle.length(), last_idx = haystack.length() - len;
	unordered_map<string, int> hash;
	for (int i = 0;i <= last_idx;i++)
	{
		string substr = haystack.substr(i, len);
		if (hash.find(substr) == hash.end())
			hash[substr] = i;
	}
	return hash.find(needle) == hash.end() ? -1 : hash[needle];
}