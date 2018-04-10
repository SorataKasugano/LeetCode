#pragma once
/*
125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. */

#include <string>
using namespace std;

bool isPalindrome(string s) {
	int aA = 'A' - 'a', i = 0, ri = s.length() - 1;
	while (i <= ri)
	{
		if (!((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z') || (s[i] >= '0'&&s[i] <= '9'))) { i++;continue; }
		if (!((s[ri] >= 'a'&&s[ri] <= 'z') || (s[ri] >= 'A'&&s[ri] <= 'Z') || (s[ri] >= '0'&&s[ri] <= '9'))) { ri--;continue; }
		if (s[i] >= 'a'&&s[i] <= 'z') s[i] += aA;
		if (s[ri] >= 'a'&&s[ri] <= 'z') s[ri] += aA;
		if (s[i] != s[ri]) return false;
		i++; ri--;
	}
	return true;
}