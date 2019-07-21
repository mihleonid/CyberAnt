#include "lcolor.h"

LColor::LColor():f(255), b(0){
}
LColor::LColor(const LMonoColor& a, const LMonoColor& c):f(a), b(c){
}
LColor::LColor(const LMonoColor& a):f(a), b(a){
}
LColor::LColor(int r, int g, int v):f(r, g, v), b(0){
}
LColor::LColor(const LColor& c):f(c.fg()), b(c.bg()){
}
LColor::LColor(int r):f(r), b(0){
}
LColor::LColor(int r, bool g):f(r, g), b(0){
}

LMonoColor LColor::fg() const{
	return f;
}
LMonoColor LColor::bg() const{
	return b;
}
void LColor::setFg(const LMonoColor& c){
	f=c;
}
void LColor::setBg(const LMonoColor& c){
	b=c;
}
void LColor::setFg(char c){
	f=LMonoColor(c);
}
void LColor::setBg(char c){
	b=LMonoColor(c);
}
void LColor::def(){
	f=LMonoColor(255);
	b=LMonoColor(0);
}
bool operator==(const LColor& a, const LColor& b){
	return((a.fg()==b.fg())&&(a.bg()==b.bg()));
}
bool operator<(const LColor& a, const LColor& b){
	if(a.fg()<b.fg()){
		return true;
	}
	if(a.fg()==b.fg()){
		if(a.bg()<b.bg()){
			return true;
		}
	}
	return false;
}
bool operator>(const LColor& a, const LColor& b){
	if(a.fg()>b.fg()){
		return true;
	}
	if(a.fg()==b.fg()){
		if(a.bg()>b.bg()){
			return true;
		}
	}
	return false;
}
bool operator<=(const LColor& a, const LColor& b){
	return(!(a>b));
}
bool operator>=(const LColor& a, const LColor& b){
	return(!(a<b));
}
bool operator!=(const LColor& a, const LColor& b){
	return((a.fg()!=b.fg())||(a.bg()!=b.bg()));
}

