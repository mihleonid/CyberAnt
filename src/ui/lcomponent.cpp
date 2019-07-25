#include <iostream>
#include "lcomponent.h"

LComponent::~LComponent(){
}
void LComponent::draw(LDrawer* ldr){
	std::cerr<<"Calling to LComponent::draw"<<std::endl;
}
EventQueue LComponent::applyEvent(LEvent* e){
	std::cerr<<"Calling to LComponent::applyEvent"<<std::endl;
	return EventQueue();
}

