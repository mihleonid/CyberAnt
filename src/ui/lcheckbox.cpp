#include "ldrawer.h"
#include "lmouseevent.h"
#include "levent.h"
#include "leventtype.h"
#include "lcheckbox.h"

LCheckBox::LCheckBox(Rect p, std::string t, ACallback<Event*, bool>* o):LRectedComponent(p){
	text=t;
	onStateChanged=o;
}
LCheckBox::LCheckBox(Rect p, const char* t, ACallback<Event*, bool>* o):LRectedComponent(p){
	text=std::string(t);
	onStateChanged=o;
}
LCheckBox::~LCheckBox(){
}
void LCheckBox::draw(LDrawer* ldr){
	if(expand){
		Rect r=ldr->drawText(rect.getA().getX(), rect.getA().getY(), ("[ ] "+text).c_str());
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
	ldr->color(col);
	if(checked){
		ldr->drawTextCenter((rect.getA().getX()+rect.getB().getX())/2, rect.getA().getY(), ("[X] "+text).c_str());
	}else{
		ldr->drawTextCenter((rect.getA().getX()+rect.getB().getX())/2, rect.getA().getY(), ("[ ] "+text).c_str());
	}
}
bool LCheckBox::getChecked(){
	return checked;
}
void LCheckBox::setChecked(bool b){
	checked=b;
}
LCheckBox* LCheckBox::setColor(const LColor& c){
	col=c;
	return this;
}
LColor LCheckBox::getColor() const{
	return col;
}
std::vector<LEventType> LCheckBox::acceptedTypes(){
	return {Mouse};
}
EventQueue LCheckBox::applyEvent(LEvent* e){
	if(rect.contain(((LMouseEvent*)e)->getPos())){
		if(((LMouseEvent*)e)->getMouseType()==BUTTON_Up){
			if(!down){
				return EventQueue();
			}
			down=false;
			e->prevent();
			checked=!checked;
			return EventQueue(onStateChanged->call(checked));
		}
		if(((LMouseEvent*)e)->getMouseType()==BUTTON_Down){
			e->prevent();
			down=true;
			return EventQueue();
		}
	}else{
		down=false;
	}
	return EventQueue();
}

