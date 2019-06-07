#include <iostream>
#include "fo.h"

FO::FO(Point p, Field* currF){
	pos=p;
	currField=currF;
}
SDL_Texture* FO::getTexture(Assets ass*, SDL_Renderer* ren){
	std::cerr<<"Calling to FO"<<std::endl;
	return nullptr;
}
void FO::update(){
	std::cerr<<"Calling to FO"<<std::endl;
}

FOType FO::getType(){
	return type;
}
FOWhat FO::getWhat(){
	return what;
}
Field* FO::getField(){
	return currField;
}
Point FO::getPos(){
	return pos;
}
void FO::setPos(Point p){
	pos=p;
	currField->set(this);
}

