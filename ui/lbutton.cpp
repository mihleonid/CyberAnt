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
	if(r.getB().getX()+rect.getA().getX()>rect.getB().getX()){
		rect=Rect(rect.getA(), Point(r.getB().getX()+rect.getA().getX(), rect.getB().getY()));
	}
	if(r.getB().getY()+r.getA().getY()>rect.getB().getY()){
		rect=Rect(rect.getA(), Point(rect.getB().getX(), r.getB().getY()+r.getA().getY()));
	}
}
Event* LButton::applyEvent(LEvent* e){
	if(e->getType()!=Mouse){
		return nullptr;
	}
	if(((LMouseEvent*)e)->getMouseType()==BUTTON_Up){
		if(rect.contain(((LMouseEvent*)e)->getPos())){
			return onClick->call();
		}
	}
	return nullptr;
}

