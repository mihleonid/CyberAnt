#include <iostream>
#include "to.h"

TO::TO(ResourceSet r){
	have=r;
}
Tubed* TO::where(const std::vector<Tubed*>& nbs){
	std::cerr<<"Calling TO::where"<<std::endl;
	return nullptr;
}
bool TO::whant(const Putable* p){
	return false;
}
TO::~TO(){
}

