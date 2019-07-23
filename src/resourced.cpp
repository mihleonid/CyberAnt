#include <iostream>
#include "resourced.h"

bool Resourced::empty() const{
	std::cerr<<"Resuorce::empty must be overloaded"<<std::endl;
	return true;
}
ResourceSet Resourced::mine(ResourceSet need){
	std::cerr<<"Resource::mine must be overloaded"<<std::endl;
	return ResourceSet();
}

