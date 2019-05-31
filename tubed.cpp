#include <iostream>
#include "tubed.h"

void Tubed::send(Resourceset give){}
virtual void Tubed::send(TO* give){
	std::cerr<<"Calling to tubed"<<std::endl;
}

