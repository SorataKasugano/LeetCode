#pragma once
/*
242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?*/

#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
	//1.hash
	int len = s.length();
	if (len != t.length())
		return false;
	int hash[26] = { 0 };
	for (int i = 0;i < len;i++)
	{
		hash[s[i] - 'a']++;
		hash[t[i] - 'a']--;
	}
	for (auto iter : hash)
	{
		if (iter != 0)
			return false;
	}
	return true;
	//2.sort
	//sort(s.begin(), s.end());
	//sort(t.begin(), t.end());
	//return s == t;
}