#include "lmouseevent.h"
#include "leventtype.h"

LMouseEvent::LMouseEvent(LMouseEventType t, Point p):LEvent(LEventType::Mouse){
	mtype=t;
	pos=p;
}
LMouseEventType LMouseEvent::getMouseType() const{
	return mtype;
}
Point LMouseEvent::getPos() const{
	return pos;
}

