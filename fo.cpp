#include <iostream>
#include "fo.h"
#include "field.h"

FO::FO(Point p, Field* currF){
	pos=p;
	currField=currF;
}
FO::~FO(){
}
LImage* FO::getImage(Assets* ass) const{
	std::cerr<<"Calling to FO::getImage()"<<std::endl;
	return nullptr;
}
void FO::update(){
	std::cerr<<"Calling to FO::update()"<<std::endl;
}

FOType FO::getType() const{
	return type;
}
FOWhat FO::getWhat() const{
	return what;
}
Field* FO::getField(){
	return currField;
}
Point FO::getPos() const{
	return pos;
}
void FO::setPos(Point p){
	Point ppos=pos;
	pos=p;
	currField->set(this, ppos);
}

