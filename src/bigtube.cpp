#include "bigtube.h"

BigTube::BigTube(Point p, Field* f, int lvl):Building(p, f, lvl){
	what=BBase;
	type=(FOType)(FOBuilding|FOTubed);
}
void BigTube::update(){
	std::vector<Point> nbs=getField()->getnb(getPos());
	std::vector<std::pair<const Tubed*, const Point&>> aims;
	for(Point p:nbs){
		FO* cf=getField()->get(p);
		if((cf->getType())&FOPutable){
			for(int i=0;i<tos.size();++i){
				if(tos[i]->whant((Putable*)cf)){
					((Putable*)cf)->put(tos[i]->have);
					delete tos[i];
					tos[i]=tos[tos.size()-1];
					tos.pop_back();
					--i;
				}
			}
		}
		if((cf->getType())&FOTubed){
			aims.push_back({(const Tubed*)cf, p});
		}
	}
}
std::pair<LImage*, LColor> BigTube::getImage(Assets* ass) const{
	return std::pair<LImage*, LColor>(ass->get("base"), levelColor());
}
void BigTube::send(TO* g){
	tos.push_back(g);
}

