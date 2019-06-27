#include <math.h>
#include "point.h"
#include "common.hpp"

Point::Point():x(0), y(0){
}
Point::Point(int a):x(a), y(a){
}
Point::Point(const Point& p):x(p.getX()), y(p.getY()){
}
Point::Point(int x, int y):x(x), y(y){
}
int Point::dist(Point& p) {
	return(mmax(std::abs(p.y-y), std::abs(p.x-x)));
}
Point& Point::operator+=(Point& p){
	x+=p.x;
	y+=p.y;
	return *this;
}
Point Point::operator+(Point& p){
	return Point(p.x+x, p.y+y);
}
Point& Point::operator-=(Point& p){
	x-=p.x;
	y-=p.y;
	return *this;
}
Point Point::operator-(Point& p){
	return Point(p.x-x, p.y-y);
}
int Point::getY() const{
	return y;
}
int Point::getX() const{
	return x;
}
bool operator==(const Point& a, const Point& b){
	return ((a.x==b.x)&&(a.y==b.y));
}
bool operator!=(const Point& a, const Point& b){
	return ((a.x!=b.x)||(a.y!=b.y));
}

Rect::Rect():a(0), b(0){
}
Rect::Rect(const Point& p):a(p), b(p){
}
Rect::Rect(const Rect& r):a(r.getA()), b(r.getB()){
}
Rect::Rect(Point aa, Point bb):a(aa), b(bb){
}
Point Rect::getA() const{
	return a;
}
Point Rect::getB() const{
	return b;
}

