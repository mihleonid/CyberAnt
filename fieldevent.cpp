#include "fieldevent.h"

FieldEvent::FieldEvent(FieldEventType t, Point p, FOWhat wh){
	type=t;
	what=wh;
	pos=p;
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

