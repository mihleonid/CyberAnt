#include <iostream>
#include "ldrawer.h"

Rect LDrawer::draw(int x, int y, LImage* img, const LColor& c){
	std::cerr<<"Calling to LDrawer::draw..."<<std::endl;
	return Rect();
}
Rect LDrawer::draw(int x, int y, LImage* img){
	std::cerr<<"Calling to LDrawer::draw..."<<std::endl;
	return Rect();
}
Rect LDrawer::draw(Point p, LImage* img, const LColor& c){
	return draw(p.getX(), p.getY(), img, c);
}
Rect LDrawer::draw(Point p, LImage* img){
	return draw(p.getX(), p.getY(), img);
}

Rect LDrawer::drawText(int x, int y, int text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawText(int x, int y, const char* text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawText(Point p, int text){
	return drawText(p.getX(), p.getY(), text);
}
Rect LDrawer::drawText(Point p, const char* text){
	return drawText(p.getX(), p.getY(), text);
}

Rect LDrawer::drawTextRight(int x, int y, int text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawTextRight(int x, int y, const char* text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawTextRight(Point p, int text){
	return drawTextRight(p.getX(), p.getY(), text);
}
Rect LDrawer::drawTextRight(Point p, const char* text){
	return drawTextRight(p.getX(), p.getY(), text);
}

Rect LDrawer::drawTextCenter(int x, int y, int text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawTextCenter(int x, int y, const char* text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawTextCenter(Point p, int text){
	return drawTextCenter(p.getX(), p.getY(), text);
}
Rect LDrawer::drawTextCenter(Point p, const char* text){
	return drawTextCenter(p.getX(), p.getY(), text);
}

void LDrawer::clear(){
	std::cerr<<"Calling to LDrawer::clear()"<<std::endl;
}
void LDrawer::present(){
	std::cerr<<"Calling to LDrawer::present()"<<std::endl;
}
void LDrawer::color(){
	std::cerr<<"Calling to LDrawer::color()"<<std::endl;
}
void LDrawer::color(LColor c){
	std::cerr<<"Calling to LDrawer::color(LColor)"<<std::endl;
}

LDrawer::~LDrawer(){
}

