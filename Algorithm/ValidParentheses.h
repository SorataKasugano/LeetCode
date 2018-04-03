#pragma once
/*
20. Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid 
but "(]" and "([)]" are not. */

#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
	stack<char> match_stack;
	for (auto iter : s)
	{// you can also return false when iter is a right paren and .top() doesn't match
		if ((!match_stack.empty())&&(
			(iter == ')'&&match_stack.top() == '(') ||
			(iter == ']'&&match_stack.top() == '[') ||
			(iter == '}'&&match_stack.top() == '{')))
			match_stack.pop();
		else
			match_stack.push(iter);
	}
	return match_stack.empty();
	// using ASCII is also valid but meaningless I think
}