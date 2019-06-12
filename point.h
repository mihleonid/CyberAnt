#pragma once
#include <vector>

class Point{
	private:
		int x, y;
	public:
		int getX() const;
		int getY() const;

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

typedef std::vector<Point> Path;

