#include <iostream>
#include "ldrawer.h"

Rect LDrawer::draw(Point p, LImage* img, const LColor& c){
	return draw(p.getX(), p.getY(), img, c);
}
Rect LDrawer::draw(Point p, LImage* img){
	return draw(p.getX(), p.getY(), img);
}

Rect LDrawer::drawText(Point p, int text){
	return drawText(p.getX(), p.getY(), text);
}
Rect LDrawer::drawText(Point p, const char* text){
	return drawText(p.getX(), p.getY(), text);
}

Rect LDrawer::drawTextRight(Point p, int text){
	return drawTextRight(p.getX(), p.getY(), text);
}
Rect LDrawer::drawTextRight(Point p, const char* text){
	return drawTextRight(p.getX(), p.getY(), text);
}

Rect LDrawer::drawTextCenter(Point p, int text){
	return drawTextCenter(p.getX(), p.getY(), text);
}
Rect LDrawer::drawTextCenter(Point p, const char* text){
	return drawTextCenter(p.getX(), p.getY(), text);
}

LDrawer::~LDrawer(){
}

