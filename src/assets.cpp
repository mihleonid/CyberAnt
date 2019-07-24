#include "assets.h"
#include "common.hpp"

LImage* Assets::getNode(std::string type){
	return get(type+"node");
}
LImage* Assets::getMine(std::string type){
	return get(type+"mine");
}
LImage* Assets::get(std::string str){
	if(!(cache.count(str))){
		cache[str]=new LImage(ASSETS_DIR+str);
	}
	return cache[str];
}
Assets::~Assets(){
	for(auto i=cache.begin();i!=cache.end();++i){
		delete i->second;
	}
}

