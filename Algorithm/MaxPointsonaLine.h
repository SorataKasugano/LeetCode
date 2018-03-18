#pragma once
/*
149. Max Points on a Line
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.*/

#include <map>
#include <vector>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
int GCD(int a, int b)
{
	return a % b == 0 ? b : GCD(b, a%b);
}
int maxPoints(vector<Point>& points) {
	int size = points.size();
	if (size < 2) { return size; }
	int ret = 0;
	for (int i = 0;i < size;i++)
	{
		int dup = 1, max = 0;// the anchor duplicate one time first
		pair<int, int> slope;// <0,0> when doesn't exist
		map<pair<int, int>, int> map;
		for (int j = 0;j < size;j++)
		{
			if (j == i) continue;
			if (points[j].x == points[i].x)
			{
				if (points[j].y == points[i].y)
				{
					dup++;
					continue;
				}
				slope.first = slope.second = 0;
				map[slope]++;
			}
			else
			{
				int y = points[j].y - points[i].y, x = points[j].x - points[i].x;
				int gcd = GCD(y, x);
				slope.first = y / gcd;
				slope.second = x / gcd;
				map[slope]++;
			}
		}
		for (auto iter : map)
		{
			if (iter.second > max)
				max = iter.second;
		}
		max += dup;
		if (max > ret) { ret = max; }
	}
	return ret;
}