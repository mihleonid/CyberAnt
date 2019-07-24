#include "levent.h"

LEvent::LEvent(LEventType t){
	type=t;
}
LEventType LEvent::getType() const{
	return type;
}
LEvent::~LEvent(){
}

void LEvent::prevent(){
	prevented=true;
}
bool LEvent::getPrevented(){
	return prevented;
}

