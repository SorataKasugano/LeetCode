#pragma once
/*
326. Power of Three
Given an integer, write a function to determine if it is a power of three.

Follow up:
Could you do it without using any loop / recursion? */

#include <algorithm>
using namespace std;

bool isPowerOfThree(int n) {
	// 1. iterative
	while (n && !(n % 3))
	{
		n /= 3;
	}
	return n == 1;

	// Follow up
	//return fmod(log10(n) / log10(3), 1) == 0;
}