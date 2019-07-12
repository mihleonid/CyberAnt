#include "assets.h"

LImage Assets::getNode(std::string type){
	return get(type+"node");
}
LImage Assets::getMine(std::string type){
	return get(type+"mine");
}
LImage Assets::get(std::string str){
	if(cache.count(str)){
		return LImage(cache[str]);
	}
	cache[str]=LImage("./assets/"+str);
	return LImage(cache[str]);
}

