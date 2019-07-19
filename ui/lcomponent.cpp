#include <iostream>
#include "lcomponent.h"

LComponent::LComponent(Rect p){
	rect=p;
}
Rect LComponent::getRect() const{
	return rect;
}
void LComponent::draw(LDrawer* ldr){
	std::cerr<<"Calling to LDRawer::draw"<<std::endl;
}
Event* LComponent::applyEvent(LEvent* e){
	std::cerr<<"Calling to LDRawer::applyEvent"<<std::endl;
	return nullptr;
}

