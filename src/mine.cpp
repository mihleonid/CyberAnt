#include <vector>
#include "random.h"
#include "mine.h"
#include "resourced.h"
#include "assets.h"
#include "tubed.h"
#include "putable.h"

Mine::Mine(Point p, Field* f, int lvl, ResourceType t):Building(p, f, lvl){
	type=FOBuilding;
	strength=1;
	typ=t;
}
bool Mine::upgrade(){
	if(Building::upgrade()){
		++strength;
		return true;
	}
	return false;
}
void Mine::update(){
	ResourceSet got;
	ResourceSet need(typ, strength);
	std::vector<Point> nbs=currField->getnb(getPos());
	std::vector<FO*> tubed;
	std::vector<FO*> putable;
	for(Point p:nbs){
		FO* fff=currField->get(p);
		if(fff==nullptr){
			continue;
		}
		if(fff->getType()&FOResourced){
			if(rand()%80<level+2){
				got.add(need);
				got.sub(dynamic_cast<Resourced*>(fff)->mine(need));
			}
		}
		if(fff->getType()&FOTubed){
			tubed.push_back(fff);
		}
		if(fff->getType()&FOPutable){
			putable.push_back(fff);
		}
	}
	if(got.empty()){
		return;
	}
	if(tubed.size()>0){
		dynamic_cast<Tubed*>(tubed[Random::rnd()%tubed.size()])->send(got);
	}else{
		if(putable.size()>0){
			dynamic_cast<Putable*>(putable[Random::rnd()%putable.size()])->put(got);
		}
	}
}
std::pair<LImage*, LColor> Mine::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->getMine(Resource::typeToString(typ)), levelColor());
}

