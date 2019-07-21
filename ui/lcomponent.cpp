#include <iostream>
#include "lcomponent.h"

LComponent::LComponent(Rect p){
	rect=p;
}
LComponent::~LComponent(){
}
Rect LComponent::getRect() const{
	return rect;
}
void LComponent::draw(LDrawer* ldr){
	std::cerr<<"Calling to LDRawer::draw"<<std::endl;
}
std::pair<Event*, bool> LComponent::applyEvent(LEvent* e){
	std::cerr<<"Calling to LDRawer::applyEvent"<<std::endl;
	return std::pair<Event*, bool>(nullptr, 0);
}

