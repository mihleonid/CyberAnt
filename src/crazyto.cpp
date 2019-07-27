#include "crazyto.h"

CrazyTO::CrazyTO(ResourceSet r):TO(r){
}
const Tubed* CrazyTO::where(const std::vector<std::pair<const Tubed*, const Point&>>& nbs){
	for(int i=0;i<nbs.size();++i){
		if(!(was.count(nbs[i].first))){
			was.insert(nbs[i].first);
			return nbs[i].first;
		}
	}
	return nullptr;
}
bool CrazyTO::whant(const Putable* p){
	return true;
}

