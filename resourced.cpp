#include <iostream>
#include "resource.h"

bool Resource::empty(){
	std::cerr<<"Resuorce::empty must be overloaded"<<std::endl;
	return true;
}
Resourceset Resource::mine(Resourceset need){
	std::cerr<<"Resource::mine must be overloaded"<<std::endl;
	return Resourceset();
}

