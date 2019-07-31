#include "ldrawer.h"
#include "levent.h"
#include "leventtype.h"
#include "ltextbox.h"

LTextBox::LTextBox(Point p, std::string t){
	pos=p;
	text=t;
}
LTextBox::LTextBox(Point p, const char* t){
	pos=p;
	text=std::string(t);
}
LTextBox::~LTextBox(){
}
void LTextBox::draw(LDrawer* ldr){
	ldr->drawTextCenter(pos.getX(), pos.getY(), text.c_str());
}
std::vector<LEventType> LTextBox::acceptedTypes(){
	return {};
}
EventQueue LTextBox::applyEvent(LEvent* e){
	return EventQueue();
}

