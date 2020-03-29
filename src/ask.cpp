#include <iostream>
#include "random.h"
#include "ask.h"
#include "tubed.h"
#include "storage.h"
#include "fo.h"

Ask::Ask(const Putable* t, ResourceSet r):TO(r){
	std::cout<<"New"<<std::endl;
	target=t;
	ideal=r;
	asking=true;
	life=10;
}
Ask::Ask(Ask* cpy):TO(cpy->have){
	std::cout<<"Copy"<<std::endl;
	if(cpy->asking==false){
		std::cerr<<"Copying answered ask = game imbalance"<<std::endl;
	}
	asking=true;
	was=cpy->was;
	target=cpy->target;
	ideal=cpy->ideal;
	life=cpy->life;
}
bool Ask::sended(Tubed* t){
	if(asking){
		for(int i=0;i<was.size();++i){
			if(was[i]==t){
				return false;
			}
		}
		was.push_back(t);
		--life;
	}
	return true;
}
Tubed* Ask::where(const std::vector<Tubed*>& nbs){
	if(life==0){
#ifdef DEBUG
		std::cout<<"ASK: I am dead"<<std::endl;
#endif
		return nullptr;
	}
	if(asking){
		for(int i=1;i<nbs.size();++i){
			nbs[i]->send(new Ask(this));
		}
		return nbs[0];
	}
	if(was.empty()){
#ifdef DEBUG
		std::cout<<"ASK: I have gone"<<std::endl;
#endif
		return nullptr;
	}
	for(int i=0;i<nbs.size();++i){
		if(nbs[i]==was.back()){
			was.pop_back();
			return nbs[i];
		}
	}
#ifdef DEBUG
	std::cout<<"ASK: Network has been corrupted"<<std::endl;
#endif
	return nullptr;
}
bool Ask::whant(const Putable* p){
	if(p==target){
		if(asking==false){
			return true;
		}
	}
	return false;
}
void Ask::proccessFO(FO* f){
	if(asking){
		if(f->getType()&FOStorage){
			have=dynamic_cast<Storage*>(f)->have.sub(have);
			if(have.empty()){
				asking=false;
				have=ideal;
				was.pop_back();
			}
		}
	}
}

