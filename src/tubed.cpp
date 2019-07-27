#include <iostream>
#include "tubed.h"
#include "crazyto.h"

void Tubed::send(ResourceSet give){
	send(new CrazyTO(give));
}
void Tubed::send(TO* give){
	std::cerr<<"Calling to tubed"<<std::endl;
}

