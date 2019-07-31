#include <iostream>
#include "gun.h"
#include "field.h"
#include "random.h"

Gun::Gun(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=FOBuilding|FOPutable;
	strength=1;
	cost=1;
	iron=0;
}
void Gun::update(){
	for(Point p:getField()->getnb(getPos())){
		FO* f=getField()->get(p);
		if(f==nullptr){
			continue;
		}
		if(f->getType()&FOEnemy){
			if(iron>=10){
				iron-=10;
				if(f->damage(strength)){
					++strength;
				}
			}else{
#ifdef DEBUG
				std::cout<<"Gun is inactive"<<std::endl;
#endif
			}
		}
	}
}
bool Gun::upgrade(){
	if(Building::upgrade()){
		++strength;
		++cost;
		return true;
	}
	return false;
}
std::pair<LImage*, LColor> Gun::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->get("gun"), levelColor());
}
void Gun::put(ResourceSet g){
	iron+=g.get(Iron);
}

