#include "base.h"

Base::Base(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=(FOType)(FOBuilding|FOResourced|FOStorage|FOPutable|FOBase);
}
void Base::update(){
}
std::pair<LImage*, LColor> Base::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->get("base"), levelColor());
}
bool Base::empty() const{
	return have.empty();
}
void Base::put(ResourceSet g){
	have.add(g);
}
ResourceSet Base::mine(ResourceSet need){
	return have.sub(need);
}

