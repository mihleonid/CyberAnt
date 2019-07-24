#include <iostream>
#include "lsubscriber.h"

Event* LSubscriber::applyEvent(LEvent*){
	std::cerr<<"Calling to LSubscriber::applyEvent"<<std::endl;
	return nullptr;
}
std::vector<LEventType> LSubscriber::acceptedTypes(){
	return {};
}

