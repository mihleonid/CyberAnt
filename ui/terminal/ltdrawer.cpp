#include "terminal.h"
#include "ltdrawer.h"

Rect LTDrawer::drawText(int x, int y, const char* c, int len){
	T_GOTO(x, y);
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
	T_GOTO(x-len, y);
	std::cout<<c;
	return Rect(Point(x-len, y), Point(x, y));
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
	T_GOTO(x-(len/2), y);
	std::cout<<c;
	return Rect(Point(x-(len/2), y), Point(x+len-(len/2), y));
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
