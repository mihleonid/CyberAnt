#include "event.h"

Event::Event(EventType t, Point p, FOWhat wh){
	type=t;
	what=wh;
	pos=p;
}
Point Event::getPos(){
	return pos;
}
EventType Event::getType(){
	return type;
}
FOType Event::getWhat(){
	return what;
}

