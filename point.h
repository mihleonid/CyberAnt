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
		friend bool operator==(const Point& a, const Point& b);
		friend bool operator!=(const Point& a, const Point& b);
};
bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);

typedef std::vector<Point> Path;

