#pragma once
/*
69. Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x.

x is guaranteed to be a non-negative integer.

Example 1:

Input: 4
Output: 2

Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we want to return an integer, 
the decimal part will be truncated. */

// Newton's method
// x[n+1]=x[n]-f(x[n])/f'(x[n]);

int mySqrt(int x) {
	// Newton's method
	// x[n+1]=x[n]-f(x[n])/f'(x[n]);
	if (x<2) return x;
	for (long long ret = x / 2, x1;;)
	{
		ret = ret / 2 + x / (2 * ret);
		if (ret*ret <= x) return ret;
	}
}