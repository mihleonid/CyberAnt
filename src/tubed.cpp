#include <iostream>
#include "tubed.h"

void Tubed::send(ResourceSet give){
	send(new TO(give)); // TODO CrazyTO
}
void Tubed::send(TO* give){
	std::cerr<<"Calling to tubed"<<std::endl;
}
