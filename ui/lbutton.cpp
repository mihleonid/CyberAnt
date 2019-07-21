#include "ldrawer.h"
#include "lmouseevent.h"
#include "levent.h"
#include "leventtype.h"
#include "lbutton.h"

LButton::LButton(Rect p, std::string t, Callback<Event*>* c):LComponent(p){
	text=t;
	onClick=c;
}
LButton::LButton(Rect p, const char* t, Callback<Event*>* c):LComponent(p){
	text=std::string(t);
	onClick=c;
}
LButton::~LButton(){
	delete onClick;
}
void LButton::draw(LDrawer* ldr){
	Rect r=ldr->drawText(rect.getA().getX(), rect.getA().getY(), text.c_str());
	if(r.getB().getX()>rect.getB().getX()){
		rect=Rect(rect.getA(), rect.getB().setX(r.getB().getX()));
	}
	if(r.getB().getY()>rect.getB().getY()){
		rect=Rect(rect.getA(), rect.getB().setY(r.getB().getY()));
	}
}
std::pair<Event*, bool> LButton::applyEvent(LEvent* e){
	if(e->getType()!=Mouse){
		return std::pair<Event*, bool>(nullptr, 0);
	}
	if(rect.contain(((LMouseEvent*)e)->getPos())){
		if(((LMouseEvent*)e)->getMouseType()==BUTTON_Up){
			return std::pair<Event*, bool>(onClick->call(), 1);
		}
		return std::pair<Event*, bool>(nullptr, 1);
	}
	return std::pair<Event*, bool>(nullptr, 0);
}

