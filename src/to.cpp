#include <iostream>
#include "to.h"

TO::TO(ResourceSet r){
	have=r;
}
const Tubed* TO::where(const std::vector<std::pair<const Tubed*, const Point&>>& nbs){
	std::cerr<<"Calling TO::where"<<std::endl;
	return nullptr;
}

