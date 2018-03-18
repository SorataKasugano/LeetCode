#include <iostream>
#include "MaxPointsonaLine.h"
int main()
{
	Point point;
	vector<Point> points = { {0,0},{0,0} };
	cout << maxPoints(points) << endl;
	return 0;
}