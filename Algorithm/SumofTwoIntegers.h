#pragma once
/*
371. Sum of Two Integers
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.*/

int getSum(int a, int b) {
	return b ? getSum(a^b, (a&b) << 1) : a;// no carry sum first,then add carry
}