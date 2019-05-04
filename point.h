#pragma once
#include <vector>

typedef std::vector<Point> Path;
class Point{
	private:
		int x, y;
	public:
		int getX();
		int getY();

		Point();
		Point(int x, int y);
		int dist(Point& p);
		Point& operator+=(Point& p);
		Point operator+(Point& p);
		Point& operator-=(Point& p);
		Point operator-(Point& p);
};
bool operator==(Point& a, Point& b);
bool operator!=(Point& a, Point& b);

