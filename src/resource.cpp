#include <iostream>
#include "resource.h"
#include "configurator.h"
#include "random.h"

std::map<ResourceType, std::string> Resource::resourceTypeCache;
ResourceType Resource::randomType(){
	auto all=getAllTypes();
	return all[Random::rnd(all.size())-1];
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
std::string Resource::typeToLocalizedString(ResourceType w){
	if(!(resourceTypeCache.count(w))){
		resourceTypeCache[w]=Configurator::getLocalizedTextFromFile("resource/"+typeToString(w));
	}
	return resourceTypeCache[w];
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
std::vector<ResourceType> Resource::getAllTypes(){
	return {Iron, Oxygen /*Cristall*/}; 
}

