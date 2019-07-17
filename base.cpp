#include "base.h"

Base::Base(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=(FOType)(FOBuilding|FOResourced|FOStorage|FOPutable);
}
void Base::update(){
}
LImage* Base::getImage(Assets* ass) const{
	return ass->get("base")->applyColors(levelColor());
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

