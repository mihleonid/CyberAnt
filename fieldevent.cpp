#include "fieldevent.h"

FieldEvent::FieldEvent(FieldEventType t, Point p, FOWhat wh){
	type=t;
	what=wh;
	pos=p;
}
Point FieldEvent::getPos(){
	return pos;
}
FieldEventType FieldEvent::getType(){
	return type;
}
FOType FieldEvent::getWhat(){
	return what;
}
bool FieldEvent::forGameController(){
	return false;
}

