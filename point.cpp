#include <math>
#include "point.h"

Point::Point():x(0), y(0){
}
Point::Point(int x, int y):x(x), y(y){
}
int Point::dist(Point& p) {
	return(std::max(std::abs(p.y-y)+std::abs(p.x-x)));
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
int Point::getY(){
	return y;
}
int Point::getX(){
	return x;
}
bool operator==(Point& a, Point& b){
	return ((a.x==b.x)&&(a.y==b.y));
}
bool operator!=(Point& a, Point& b){
	return ((a.x!=b.x)||(a.y!=b.y));
}

