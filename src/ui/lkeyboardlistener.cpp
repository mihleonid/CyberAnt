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
Event* LKeyboardListener::applyEvent(LEvent* e){
	if(e->getType()!=Keyboard){
		return nullptr;
	}
	if(((LKeyboardEvent*)e)->getKeyboardType()==KEY_Down){
		if(((LKeyboardEvent*)e)->getKey()==key){
			return onDown->call();
		}
	}
	return nullptr;
}

