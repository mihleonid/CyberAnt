#include "base.h"

Base::Base(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=(FOType)(FOBuilding|FOResourced|FOStorage|FOPutable);
}
void Base::update(){
}
LImage Base::getImage(Assets* ass) const{
	LImage img=ass->get("base");
	img.applyColors(levelColor());
	return img;
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

