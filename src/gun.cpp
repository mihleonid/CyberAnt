#include <iostream>
#include "gun.h"
#include "field.h"
#include "storage.h"
#include "tubed.h"
#include "random.h"
#include "ask.h"

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
			start:;
			if(iron>=cost){
				iron-=cost;
				if(f->damage(strength)){
					++strength;
				}
			}else{
				int need=cost-iron;
				for(Point pp:getField()->getnb(getPos())){
					FO* ff=getField()->get(pp);
					if(ff==nullptr){
						continue;
					}
					if(ff->getType()&FOStorage){
						need=dynamic_cast<Storage*>(ff)->have.sub(Iron, need);
					}
				}
				if(need==0){
					iron=cost;
					goto start;
				}else{
					iron=cost-need;
				}
				for(Point pp:getField()->getnb(getPos())){
					FO* ff=getField()->get(pp);
					if(ff==nullptr){
						continue;
					}
					if(ff->getType()&FOTubed){
						dynamic_cast<Tubed*>(ff)->send(new Ask(this, ResourceSet(Iron, need)));
					}
				}
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
	return std::pair<LImage*, LColor>(ass->get("gun"), LColor(0, iron, 0));
	return std::pair<LImage*, LColor>(ass->get("gun"), levelColor());//TODO bar
}
void Gun::put(ResourceSet g){
	iron+=g.get(Iron);
}

