#include <random>
#include <iostream>
#include "resource.h"

ResourceType Resource::randomType(){
	switch(rand()%3){
		case 0:
			return Iron;
		case 1:
			return Oxygen;
		case 2:
			return Cristall;
	}
	return Iron;
}
std::string Resource::typeToString(ResourceType type){
	switch(type){
		case Iron:
			return "iron";
		case Oxygen:
			return "oxygen";
		case Cristall:
			return "cristall";
		default:
			std::cerr<<"Resource::typeToString: Unknown type "<<type<<std::endl;
			return "error";
	}
}
ResourceType Resource::stringToType(std::string str){
	if(str.compare("iron")==0){
		return Iron;
	}
	if(str.compare("oxygen")==0){
		return Oxygen;
	}
	if(str.compare("cristall")==0){
		return Cristall;
	}
	std::cerr<<"Resource::stringToType: Unknown type "<<str<<std::endl;
	return Iron;
}

