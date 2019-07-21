#include <algorithm>
#include "lscene.h"
#include "levent.h"
#include "lcomponent.h"

LScene* LScene::add(LComponent* c){
	cps.push_back(c);
	return this;
}
LScene* LScene::erase(LComponent* c){
	cps.erase(std::remove(cps.begin(), cps.end(), c), cps.end());
	return this;
}
void LScene::clear(){
	cps.clear();
}
void LScene::clearDelete(){
	for(int i=0;i<cps.size();++i){
		delete cps[i];
	}
	cps.clear();
}
void LScene::draw(LDrawer* ldr){
	for(int i=0;i<cps.size();++i){
		cps[i]->draw(ldr);
	}
}
LScene::~LScene(){
	clearDelete();
}
EventQueue LScene::applyEvent(LEvent* e){
	EventQueue eq;
	for(int i=0;i<cps.size();++i){
		eq.push(cps[i]->applyEvent(e));
	}
	return eq;
}

