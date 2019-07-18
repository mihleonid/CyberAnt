#include "terminal.h"
#include "ltdrawer.h"

LTDrawer::LTDrawer(){
	clear();
}
LTDrawer::~LTDrawer(){
}
Rect LTDrawer::draw(int x, int y, LImage* img){
	//TODO draw
	return Rect(0);
}
Rect LTDrawer::drawText(int x, int y, const char* c, int len){
	T_GOTO(x, y);
	T_OPT(foreground);
	T_OPT(background);
	std::cout<<c;
	return Rect(Point(x, y), Point(x+len, y));
}
Rect LTDrawer::drawText(int x, int y, const char* c){
	int len=0;
	while(c[len]){
		++len;
	}
	return drawText(x, y, c, len);
}
Rect LTDrawer::drawText(int x, int y, int text){
	return drawText(x, y, std::to_string(text).c_str());
}

Rect LTDrawer::drawTextRight(int x, int y, const char* c, int len){
	return drawText(x-len, y, c, len);
}
Rect LTDrawer::drawTextRight(int x, int y, const char* c){
	int len=0;
	while(c[len]){
		++len;
	}
	return drawTextRight(x, y, c, len);
}
Rect LTDrawer::drawTextRight(int x, int y, int text){
	return drawTextRight(x, y, std::to_string(text).c_str());
}

Rect LTDrawer::drawTextCenter(int x, int y, const char* c, int len){
	return drawText(x-(len/2), y, c, len);
}
Rect LTDrawer::drawTextCenter(int x, int y, const char* c){
	int len=0;
	while(c[len]){
		++len;
	}
	return drawTextCenter(x, y, c, len);
}
Rect LTDrawer::drawTextCenter(int x, int y, int text){
	return drawTextCenter(x, y, std::to_string(text).c_str());
}
void LTDrawer::clear(){
	T_CLEAR();
	color();
}
void LTDrawer::present(){
	T_HOME();
	//TODO buffers;
}

void LTDrawer::color(){
	LColor c;
	color(c);
}
void LTDrawer::color(LColor c){
	foreground=c.fg().t(false);
	background=c.bg().t(true);
}

