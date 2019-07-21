#include <random>
#include <vector>
#include "mine.h"
#include "resourced.h"
#include "assets.h"
//#include "tubed.h"
#include "putable.h"

Mine::Mine(Point p, Field* f, int lvl, ResourceType t):Building(p, f, lvl){
	what=BIMine;
	type=FOBuilding;
	strength=1;
	typ=t;
}
void Mine::upgrade(){
	Building::upgrade();
	++strength;
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
		/*
		if(fff->type&FOTubed){
			tubed.push_back(fff);
		}
		*/
		if(fff->getType()&FOPutable){
			putable.push_back(fff);
		}
	}
	/* TODO tubes
	if(tubed.size()>0){
		dynamic_cast<Tubed*>(tubed[rand()%tubed.size()])->send(got);
	}else{
	*/
		if(putable.size()>0){
			dynamic_cast<Putable*>(putable[rand()%putable.size()])->put(got);
		}
	/*
	}
	*/
}
std::pair<LImage*, LColor> Mine::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->getMine(Resource::typeToString(typ)), levelColor());
}

