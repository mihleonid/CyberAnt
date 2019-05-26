#include <random>
#include <iostream>
#include "resource.h"

ResourceType Resource::randomType(){
	switch(rand()%3){
		case 0:
			return RIron;
		case 1:
			return ROxygen;
		case 2:
			return RCristall;
	}
}
std::string Resource::typeToString(ResourceType type){
	switch(type){
		case RIron:
			return "iron";
		case ROxygen:
			return "oxygen";
		case RCristall:
			return "cristall";
		default:
			std::cerr<<"Resource::typeToString: Unknown type "<<type<<std::endl;
			return "error"
	}
}
ResourceType Resource::stringToType(std::string str){
	if(str.compare("iron")==0){
		return RIron;
	}
	if(str.compare("oxygen")==0){
		return ROxygen;
	}
	if(str.compare("cristall")==0){
		return RCristall;
	}
	std::cerr<<"Resource::stringToType: Unknown type "<<str<<std::endl;
	return RIron;
}

