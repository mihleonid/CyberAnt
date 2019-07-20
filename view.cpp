#include <iostream>
#include "view.h"

void View::init(){
}
void View::loop(const Model* m){
	std::cerr<<"Calling to view"<<std::endl;
}
EventQueue View::getEvents(){
	std::cerr<<"Calling to view"<<std::endl;
	return EventQueue();
}
View::~View(){
}

