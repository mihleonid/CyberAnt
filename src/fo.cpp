#include <iostream>
#include "fo.h"
#include "configurator.h"
#include "field.h"

std::map<FOWhat, std::string> FO::whatNamesCache;
FO::FO(Point p, Field* currF){
	pos=p;
	currField=currF;
}
FO::~FO(){
}
std::pair<LImage*, LColor> FO::getImage(Assets* ass) const{
	std::cerr<<"Calling to FO::getImage()"<<std::endl;
	return std::pair<LImage*, LColor>(nullptr, LColor(0));
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
std::string FO::whatToString(FOWhat w){
	switch(w){
		case BBase:
			return "bbase";
		case BIMine:
			return "bimine";
		case BOMine:
			return "bomine";
			//TODO more;
		default:
			return "error";
	}
}
std::string FO::whatToLocalizedString(FOWhat w){
	if(!(whatNamesCache.count(w))){
		whatNamesCache[w]=Configurator::getLocalizedTextFromFile("fo/"+whatToString(w));
	}
	return whatNamesCache[w];
}
std::vector<FOWhat> FO::getAllWhats(){
	return {BBase, BIMine, BOMine};
}

