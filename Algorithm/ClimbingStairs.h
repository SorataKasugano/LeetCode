#pragma once
/*
70. Climbing Stairs
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output:  2
Explanation:  There are two ways to climb to the top.

1. 1 step + 1 step
2. 2 steps

Example 2:

Input: 3
Output:  3
Explanation:  There are three ways to climb to the top.

1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step */

int climbStairs(int n) {
	// 1.dynamic programming
	if (n<3) return n;
	int *dp = new int[n + 1]{ 0,1,2 };
	for (int index = 3;index<n + 1;index++)
		dp[index] = dp[index - 1] + dp[index - 2];
	int ret = dp[n]; 
	delete[] dp; dp = nullptr;
	return ret;

	// 2.Fibonacci
	//if (n < 3) return n;
	//int first = 1, second = 2, ret = 0;
	//for (int index = 3;index <= n;index++)
	//{
	//	ret = first + second;
	//	first = second;
	//	second = ret;
	//}
	//return ret;

	// 3.oops! TLE
	//if(n<4) return n;
	//return climbStairs(n-1)+climbStairs(n-2);
}