#include "lcheckboxswitcher.h"
#include "lscene.h"
#include "levent.h"
#include "lmouseevent.h"

LCheckBoxSwitcher::LCheckBoxSwitcher(Rect p):LRectedComponent(p){
}
LCheckBoxSwitcher::~LCheckBoxSwitcher(){
	for(int i=0;i<all.size();++i){
		delete all[i];
	}
}
void LCheckBoxSwitcher::draw(LDrawer* ldr){
	for(int i=0;i<all.size();++i){
		all[i]->applyTalk();
		if(all[i]->getChecked()){
			for(int j=0;j<i;++j){
				all[i]->setChecked(false);
			}
			for(int j=i+1;j<all.size();++j){
				all[i]->setChecked(false);
			}
		}
		all[i]->draw(ldr);
	}
}
LCheckBoxSwitcher* LCheckBoxSwitcher::setColor(const LColor& c){
	col=c;
	return this;
}
LColor LCheckBoxSwitcher::getColor() const{
	return col;
}
std::vector<LEventType> LCheckBoxSwitcher::acceptedTypes(){
	return {Mouse};
}
EventQueue LCheckBoxSwitcher::applyEvent(LEvent* e){
	LMouseEvent* evt=(LMouseEvent*)e;
	if(!rect.contain(evt->getPos())){
		return EventQueue();
	}
	for(int i=0;i<all.size();++i){
		if(all[i]->getRect().contain(evt->getPos())){
			if(all[i]->getChecked()){
				return EventQueue();
			}
			EventQueue q=all[i]->applyEvent(e);
			if(all[i]->getChecked()){
				for(int j=0;j<i;++j){
					all[i]->setChecked(false);
				}
				for(int j=i+1;j<all.size();++j){
					all[i]->setChecked(false);
				}
			}
			return q;
		}
	}
	return EventQueue();
}
LCheckBoxSwitcher* LCheckBoxSwitcher::add(LCheckBox* cb){
	all.push_back(cb);
	return this;
}

