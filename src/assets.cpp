#include "assets.h"

LImage* Assets::getNode(std::string type){
	return get(type+"node");
}
LImage* Assets::getMine(std::string type){
	return get(type+"mine");
}
LImage* Assets::get(std::string str){
	if(!(cache.count(str))){
		cache[str]=new LImage("./assets/"+str);
	}
	return cache[str];
}
Assets::~Assets(){
	for(auto i=cache.begin();i!=cache.end();++i){
		delete i->second;
	}
}

