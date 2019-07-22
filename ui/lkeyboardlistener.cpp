#include "lkeyboardevent.h"
#include "levent.h"
#include "leventtype.h"
#include "lkeyboardlistener.h"

class LDrawer;

LKeyboardListener::LKeyboardListener(LKey k, Callback<Event*>* c){
	onDown=c;
	key=k;
}
LKeyboardListener::~LKeyboardListener(){
	delete onDown;
}
void LKeyboardListener::draw(LDrawer*){
}
std::pair<Event*, bool> LKeyboardListener::applyEvent(LEvent* e){
	if(e->getType()!=Keyboard){
		return std::pair<Event*, bool>(nullptr, 0);
	}
	if(((LKeyboardEvent*)e)->getKeyboardType()==KEY_Down){
		return std::pair<Event*, bool>(onDown->call(), 0);
	}
	return std::pair<Event*, bool>(nullptr, 0);
}

