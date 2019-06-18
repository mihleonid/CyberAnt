#include "base.h"

Base::Base(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=(FOType)(FOBuilding|FOResourced|FOStorage|FOPutable);
}
void Base::update(){
}
SDL_Texture* Base::getTexture(Assets* ass, SDL_Renderer* ren) const{
	return ass->tex(ass->getbase(), ren, ((Building*)this)->level);
}
bool Base::empty(){
	return false;
}
void Base::put(ResourceSet g){
	have.add(g);
}
ResourceSet Base::mine(ResourceSet need){
	ResourceSet rest=have.sub(need);
	need.sub(rest);
	return need;
}

