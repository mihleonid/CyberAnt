#include <iostream>
#include "view.h"

void View::init(LWindow*){
	std::cerr<<"Calling to view"<<std::endl;
}
void View::loop(const Model* m){
	std::cerr<<"Calling to view"<<std::endl;
}
View::~View(){
}

