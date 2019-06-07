#include <iostream>
#include "resourced.h"

bool Resource::empty(){
	std::cerr<<"Resuorce::empty must be overloaded"<<std::endl;
	return true;
}
ResourceSet Resource::mine(ResourceSet need){
	std::cerr<<"Resource::mine must be overloaded"<<std::endl;
	return Resourceset();
}

