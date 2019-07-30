#include <iostream>
#include "model.h"

EventQueue Model::loop(){
	std::cerr<<"Calling to model"<<std::endl;
	return EventQueue();
}
void Model::applyEvent(Event* event){
	std::cerr<<"Calling to model"<<std::endl;
}
Model::~Model(){
}

