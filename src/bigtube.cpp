#include <iostream>
#include "bigtube.h"

BigTube::BigTube(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=(FOType)(FOBuilding|FOTubed);
}
void BigTube::update(){
	std::vector<Point> nbs=getField()->getnb(getPos());
	std::vector<Tubed*> aims;
	for(int k=0;k<nbs.size();++k){
		FO* cf=getField()->get(nbs[k]);
		if(cf==nullptr){
			continue;
		}
		for(int i=0;i<tos.size();++i){
			tos[i]->proccessFO(cf);
		}
		if((cf->getType())&FOPutable){
			for(int i=0;i<tos.size();++i){
				if(tos[i]->whant(dynamic_cast<Putable*>(cf))){
					dynamic_cast<Putable*>(cf)->put(tos[i]->have);
					delete tos[i];
					tos[i]=tos[tos.size()-1];
					tos.pop_back();
					--i;
				}
			}
		}
		if((cf->getType())&FOTubed){
			aims.push_back(dynamic_cast<Tubed*>(cf));
		}
	}
	if(aims.empty()){
		return;
	}
	for(int i=0;i<tos.size();++i){
		Tubed* res=tos[i]->where(aims);
		if(res==nullptr){
#ifdef DEBUG
			std::cout<<"Losing TO. At Point("<<getPos().getX()<<", "<<getPos().getY()<<")"<<std::endl;
#endif
			delete tos[i];
			tos[i]=tos[tos.size()-1];
			tos.pop_back();
			--i;
			continue;
		}
		res->send(tos[i]);
		tos[i]=tos[tos.size()-1];
		tos.pop_back();
		--i;
	}
}
std::pair<LImage*, LColor> BigTube::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->get("bigtube"), LColor(tos.size()/10, 0, 0));
	return std::pair<LImage*, LColor>(ass->get("bigtube"), levelColor());// Network overloading TODO to bar
}
void BigTube::send(TO* g){
	tos.push_back(g);
	g->sended(this);
}

