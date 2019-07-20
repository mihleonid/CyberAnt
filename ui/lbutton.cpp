#include "ldrawer.h"
#include "lmouseevent.h"
#include "lbutton.h"

LButton::LButton(Rect p, std::string t, Event* (*c)()):LComponent(p){
	text=t;
	onClick=c;
}
LButton::~LButton(){
}
void LButton::draw(LDrawer* ldr){
	Rect r=ldr->drawText(rect.getA().getX(), rect.getA().getY(), text.c_str());
	if(r.getB().getX()>rect.getB().getX()){
		rect=Rect(rect.getA(), Point(r.getB().getX(), rect.getB().getY()));
	}
	if(r.getB().getY()>rect.getB().getY()){
		rect=Rect(rect.getA(), Point(rect.getB().getX(), r.getB().getY()));
	}
}
Event* LButton::applyEvent(LEvent* e){
	if(((LMouseEvent*)e)->getMouseType()==BUTTON_Down){
		if(rect.contain(((LMouseEvent*)e)->getPos())){
			return onClick();
		}
	}
	return nullptr;
}

