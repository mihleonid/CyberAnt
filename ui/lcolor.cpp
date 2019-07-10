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
void LColor::def(){
	f=LMonoColor(255);
	b=LMonoColor(0);
}

