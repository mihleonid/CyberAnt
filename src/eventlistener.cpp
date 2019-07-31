#include <iostream>
#include "eventlistener.h"

EventQueue EventListener::getEvents(std::queue<LEvent*>, View*){
	std::cerr<<"Calling to EventListener::getEvents(...). Use nullptr instead new EventListener"<<std::endl;
	return EventQueue();
}
EventListener::~EventListener(){
}

