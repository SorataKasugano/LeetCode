#pragma once
/*
118. Pascal's Triangle
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
    [1],
   [1,1],
  [1,2,1],
 [1,3,3,1],
[1,4,6,4,1]
] */

#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> ret(numRows);
	for (int i = 0;i<numRows;i++)
	{
		ret[i].resize(i + 1);
		ret[i][0] = ret[i][i] = 1;
		for (int j = 1;j<i;j++)
		{
			ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
		}
	}
	return ret;
}