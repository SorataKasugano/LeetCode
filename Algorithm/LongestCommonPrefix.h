#pragma once
/*
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings. */

#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	// 1.horizental
	if (strs.empty()) return "";
	string ret = strs[0];
	for (auto str : strs)
	{
		int len = ret.length()<str.length() ? ret.length() : str.length();
		ret.erase(ret.begin() + len, ret.end());
		for (int i = 0;i<len;i++)
		{
			if (ret[i] != str[i])
			{
				ret.erase(ret.begin() + i, ret.end());
				break;
			}
		}
	}
	return ret;
	// 2.vertical
	if (strs.empty()) return "";
	if (strs.size() == 1) return strs[0];
	string ret = "";
	for (int y = 0;;y++)
	{
		for (int x = 1;x<strs.size();x++)
		{
			if (strs[x].empty() || strs[x].length() <= y || strs[x][y] != strs[x - 1][y])
				return ret;
		}
		ret += strs[0][y];
	}
}