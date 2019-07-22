#include <iostream>
#include "lrectedcomponent.h"

LRectedComponent::LRectedComponent(const Rect& p){
	rect=p;
}
Rect LRectedComponent::getRect() const{
	return rect;
}

