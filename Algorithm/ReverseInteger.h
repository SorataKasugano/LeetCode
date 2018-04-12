#pragma once
/*
7. Reverse Integer
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit
signed integer range. For the purpose of this problem, assume that your function returns 0
when the reversed integer overflows. */

int reverse(int x) {
	int ret = 0, aux_ret = 0;
	do {
		aux_ret = ret * 10 + x % 10;
		if ((aux_ret - x % 10) / 10 != ret) return 0;
		else ret = aux_ret;
	} while (x /= 10);
	return ret;
}