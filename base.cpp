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
	return have.empty();
}
void Base::put(ResourceSet g){
	have.add(g);
}
ResourceSet Base::mine(ResourceSet need){
	return have.sub(need);//TODO const
}

