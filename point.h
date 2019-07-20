#pragma once
#include <vector>

class Point{
	private:
		int x, y;
	public:
		int getX() const;
		int getY() const;

		Point();
		Point(int a); // (a, a)
		Point(const Point& p);
		Point(int x, int y);
		int dist(Point& p) const;
		Point& operator+=(Point& p);
		Point operator+(Point& p);
		Point& operator-=(Point& p);
		Point operator-(Point& p);
};
class Rect{
	private:
		Point a;
		Point b;
	public:
		Point getA() const;
		Point getB() const;

		Rect();
		Rect(const Point& p); // (p, p)
		Rect(const Rect& r); // Copy
		Rect(Point a, Point b);

		bool contain(const Point& p);
};
bool operator==(const Point& a, const Point& b);
bool operator!=(const Point& a, const Point& b);
bool operator==(const Rect& a, const Rect& b);
bool operator!=(const Rect& a, const Rect& b);

typedef std::vector<Point> Path;

