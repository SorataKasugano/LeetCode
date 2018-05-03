#pragma once
/*
22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
] */

#include <string>
#include <vector>
#include <list>
using namespace std;

// vertical matrix traversal
vector<string> generateParenthesis(int n) {
	if (!n) return vector<string>();
	list<pair<string, pair<int, int>>> hash;//<<string,<unmatched close parenthesis,matched close parenthesis>>>
	hash.push_back(make_pair("(", make_pair(1, 0)));
	auto unmatched_left = [](decltype(hash.begin()) &iter)->int& {return iter->second.first;};
	auto matched_left = [](decltype(hash.begin()) &iter)->int& {return iter->second.second;};
	auto added_left = [&](decltype(hash.begin()) &iter) {return unmatched_left(iter) + matched_left(iter);};
	for (int i = 0;i < 2 * n;i++)
	{
		for (auto iter = hash.begin();iter != hash.end();iter++)
		{
			if (matched_left(iter) == n) continue;
			if (added_left(iter) == n)
			{
				iter->first.push_back(')');
				unmatched_left(iter)--;
				matched_left(iter)++;
			}
			else
			{
				if (unmatched_left(iter))
				{
					hash.push_back(make_pair(iter->first + ')',
						make_pair(unmatched_left(iter) - 1, matched_left(iter) + 1)));
				}
				iter->first.push_back('(');
				unmatched_left(iter)++;
			}
		}
	}
	vector<string> ret;
	for (auto iter : hash) ret.push_back(iter.first);
	return ret;
}

// recursive backtrack(horizontal)
//vector<string> generateParenthesis(int n) {
//	vector<string> ret;
//	recursive(ret, "", n, n);
//	return ret;
//}
//void recursive(vector<string> &ret, string str, int rest_left, int rest_right)
//{
//	if (rest_right == 0)
//	{
//		ret.push_back(str);
//		return;
//	}
//	if (rest_left>0) recursive(ret, str + '(', rest_left - 1, rest_right);
//	if (rest_left<rest_right) recursive(ret, str + ')', rest_left, rest_right - 1);
//}

// divide-and-conquer
//vector<string> generateParenthesis(int n) {
//	vector<string> ret;
//	if (n == 0)
//		ret.push_back("");
//	else
//	{
//		for (int c = 0;c < n;c++) {
//			for (string left : generateParenthesis(c)) {
//				for (string right : generateParenthesis(n - 1 - c)) {
//					ret.push_back(left + '(' + right + ')');
//				}
//			}
//		}
//	}
//	return ret;
//}