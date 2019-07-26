#include <algorithm>
#include "lscene.h"
#include "levent.h"
#include "lcomponent.h"

LScene* LScene::add(LComponent* c){
	cps.push_back(c);
	subscribe(c);
	return this;
}
LScene* LScene::erase(LComponent* c){
	cps.erase(std::remove(cps.begin(), cps.end(), c), cps.end());
	unsubscribe(c);
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
		cps[i]->applyTalk();
		cps[i]->draw(ldr);
	}
}
LScene::~LScene(){
	clearDelete();
}
EventQueue LScene::applyEvent(LEvent* e){
	return send(e);
}

