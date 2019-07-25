#include <iostream>
#include "lsubscriber.h"

EventQueue LSubscriber::applyEvent(LEvent*){
	std::cerr<<"Calling to LSubscriber::applyEvent"<<std::endl;
	return EventQueue();
}
std::vector<LEventType> LSubscriber::acceptedTypes(){
	return {};
}

