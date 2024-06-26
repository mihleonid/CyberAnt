#include "random.h"
#include "crazyto.h"

CrazyTO::CrazyTO(ResourceSet r):TO(r){
}
bool CrazyTO::sended(Tubed* t){
	was.insert(t);
	return true;
}
Tubed* CrazyTO::where(const std::vector<Tubed*>& nbs){
	for(int j=0;j<5;++j){
		int i=Random::rnd()%nbs.size();
		if(!(was.count(nbs[i]))){
			return nbs[i];
		}
	}
	for(int i=0;i<nbs.size();++i){
		if(!(was.count(nbs[i]))){
			return nbs[i];
		}
	}
	return nullptr;
}
bool CrazyTO::whant(const Putable* p){
	return true;
}

