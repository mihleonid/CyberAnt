#include <iostream>
#include "ldrawer.h"

Rect LDrawer::draw(int x, int y, LImage& img){
	std::cerr<<"Calling to LDrawer::draw..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawText(int x, int y, int text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawText(int x, int y, const char* text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}

Rect LDrawer::drawTextRight(int x, int y, int text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawTextRight(int x, int y, const char* text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}

Rect LDrawer::drawTextCenter(int x, int y, int text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
}
Rect LDrawer::drawTextCenter(int x, int y, const char* text){
	std::cerr<<"Calling to LDrawer::drawText..."<<std::endl;
	return Rect();
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

