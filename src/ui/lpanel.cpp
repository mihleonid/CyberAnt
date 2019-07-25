#include "lpanel.h"
#include "lscene.h"
#include "levent.h"
#include "lmouseevent.h"

LPanel::LPanel(Rect p):LRectedComponent(p){
	scn=new LScene();
}
LPanel::~LPanel(){
	delete scn;
}
void LPanel::draw(LDrawer* ldr){
	scn->draw(ldr);
}
LPanel* LPanel::setColor(const LColor& c){
	col=c;
	return this;
}
LColor LPanel::getColor() const{
	return col;
}
LScene* LPanel::getScene(){
	return scn;
}
std::vector<LEventType> LPanel::acceptedTypes(){
	return LEvent::getAllTypes();
}
EventQueue LPanel::applyEvent(LEvent* e){
	if(e->getType()==Mouse){
		if(!rect.contain(((LMouseEvent*)e)->getPos())){
			return EventQueue();
		}
	}
	return scn->applyEvent(e);
}

