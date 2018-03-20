#pragma once
/*
387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters. */

#include <string>
#include <unordered_map>
using namespace std;

int firstUniqChar(string s) {
	// 1.
	int ret = s.length();
	unordered_map<char, pair<int, int>> hash;
	for (int index=0;index<s.length();index++)
	{
		hash[s[index]].first++;
		hash[s[index]].second = index;
	}
	for (auto iter : hash)
	{
		if (iter.second.first == 1 && iter.second.second < ret) ret = iter.second.second;
	}
	return ret == s.length() ? -1 : ret;

	// 2.O(n^2)
	//for (int i = 0;i<s.length();i++)
	//{
	//	bool uniq = true;
	//	for (int j = 0;j<s.length();j++)
	//	{
	//		if (i != j && s[i] == s[j])
	//		{
	//			uniq = false;
	//			break;
	//		}
	//	}
	//	if (uniq) return i;
	//}
	//return -1;
}