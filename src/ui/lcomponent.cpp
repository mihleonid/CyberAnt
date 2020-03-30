#include <iostream>
#include "lcomponent.h"
#include "ltalk.h"

LComponent::~LComponent(){
	while(lts.size()){
		applyTalk();
	}
}
void LComponent::draw(LDrawer* ldr){
	std::cerr<<"Calling to LComponent::draw"<<std::endl;
}
EventQueue LComponent::applyEvent(LEvent* e){
	std::cerr<<"Calling to LComponent::applyEvent"<<std::endl;
	return EventQueue();
}
void LComponent::applyTalk(){
	if(lts.empty()){
		return;
	}
	LTalk* t=lts.front();
	lts.pop();
	t->talk(this);
	delete t;
}
void LComponent::addTalk(LTalk* t){
	lts.push(t);
}

