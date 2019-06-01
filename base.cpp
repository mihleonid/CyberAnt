#include "base.h"

Base::Base(int xx, int yy, Field* f, int lvl):Building(xx, yy, f, lvl){
	what=BBase;
	type=(FOType)(FOBuilding|FOResourced|FOStorage|FOPutable);
}
void Base::update(){
}
SDL_Texture* Base::getTexture(Assets ass*, SDL_Renderer* ren){
	return ass->tex(ass->getbase(), ren, ((Building*)this)->level);
}
bool Base::empty(){
	return false;
}
void Base::put(Resourceset g){
	have.add(g);
}
ResourceSet Base::mine(ResourceSet need){
	Resourceset rest=have.sub(need);
	need.sub(rest);
	return need;
}

