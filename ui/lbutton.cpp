#include "ldrawer.h"
#include "lmouseevent.h"
#include "levent.h"
#include "leventtype.h"
#include "lbutton.h"

LButton::LButton(Rect p, std::string t, Callback<Event*>* c):LRectedComponent(p){
	text=t;
	onClick=c;
}
LButton::LButton(Rect p, const char* t, Callback<Event*>* c):LRectedComponent(p){
	text=std::string(t);
	onClick=c;
}
LButton::~LButton(){
	delete onClick;
}
void LButton::draw(LDrawer* ldr){
	if(expand){
		Rect r=ldr->drawText(rect.getA().getX(), rect.getA().getY(), text.c_str());
		if(r.getB().getX()>rect.getB().getX()){
			rect=Rect(rect.getA(), rect.getB().setX(r.getB().getX()));
		}
		if(r.getB().getY()>rect.getB().getY()){
			rect=Rect(rect.getA(), rect.getB().setY(r.getB().getY()));
		}
		if(r.getA().getX()<rect.getA().getX()){
			rect=Rect(rect.getA().setX(r.getA().getX()), rect.getB());
		}
		if(r.getA().getY()<rect.getA().getY()){
			rect=Rect(rect.getA().setY(r.getA().getY()), rect.getB());
		}
		expand=false;
	}
	ldr->drawRect(rect, col);
	ldr->drawTextCenter((rect.getA().getX()+rect.getB().getX())/2, rect.getA().getY(), text.c_str());
	
}
LButton* LButton::setColor(const LColor& c){
	col=c;
	return this;
}
LColor LButton::getColor() const{
	return col;
}
std::pair<Event*, bool> LButton::applyEvent(LEvent* e){
	if(e->getType()!=Mouse){
		return std::pair<Event*, bool>(nullptr, 0);
	}
	if(rect.contain(((LMouseEvent*)e)->getPos())){
		if(((LMouseEvent*)e)->getMouseType()==BUTTON_Up){
			if(!down){
				return std::pair<Event*, bool>(nullptr, 0);
			}
			down=false;
			return std::pair<Event*, bool>(onClick->call(), 1);
		}
		if(((LMouseEvent*)e)->getMouseType()==BUTTON_Down){
			down=true;
			return std::pair<Event*, bool>(nullptr, 1);
		}
	}
	return std::pair<Event*, bool>(nullptr, 0);
}

