#pragma once
/*
122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like (ie, buy one and sell one share of the 
stock multiple times). However, you may not engage in multiple transactions at the same 
time (ie, you must sell the stock before you buy again).*/

#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
	int ret = 0;
	if (prices.size()>1)
	{
		for (auto iter = prices.begin() + 1;iter != prices.end();iter++)
		{
			if (*iter>*(iter - 1))
				ret += *iter - *(iter - 1);
		}
	}
	return ret;
}