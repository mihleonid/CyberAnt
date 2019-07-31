#include "gun.h"
#include "field.h"
#include "random.h"

Gun::Gun(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=FOBuilding;
	strength=1;
}
void Gun::update(){
	for(Point p:getField()->getnb(getPos())){
		FO* f=getField()->get(p);
		if(f==nullptr){
			continue;
		}
		if(f->getType()&FOEnemy){
			if(Random::rnd(23)==1){
				if(f->damage(strength)){
					++strength;
				}
			}
		}
	}
}
bool Gun::upgrade(){
	if(Building::upgrade()){
		++strength;
		return true;
	}
	return false;
}
std::pair<LImage*, LColor> Gun::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->get("gun"), levelColor());
}

