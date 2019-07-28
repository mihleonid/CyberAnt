#include "standingenemy.h"
#include "field.h"
#include "random.h"

StandingEnemy::StandingEnemy(Point p, Field* f):FO(p, f){
	what=BBase;
	type=FOEnemy;
}
void StandingEnemy::update(){
	for(Point p:getField()->getnb(getPos())){
		FO* f=getField()->get(p);
		if(f==nullptr){
			continue;
		}
		if(f->getType()&FOEnemy){
			return;
		}
		if(Random::rnd(40)==1){
			f->damage(1);
		}
	}
}
std::pair<LImage*, LColor> StandingEnemy::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->get("standingenemy"), LColor(0));
}

