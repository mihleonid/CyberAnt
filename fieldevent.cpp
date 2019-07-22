#include "fieldevent.h"

FieldEvent::FieldEvent(FieldEventType t, Point p, FOWhat wh){
	type=t;
	what=wh;
	pos=p;
}
FieldEvent::FieldEvent(FieldEventType t, Point p){
	type=t;
	pos=p;
}
FieldEvent::FieldEvent(FieldEventType t, FOWhat wh){
	type=t;
	what=wh;
}
Point FieldEvent::getPos() const{
	return pos;
}
FieldEventType FieldEvent::getType() const{
	return type;
}
FOWhat FieldEvent::getWhat() const{
	return what;
}

