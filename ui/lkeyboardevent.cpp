#include "lkeyboardevent.h"
#include "leventtype.h"

LKeyboardEvent::LKeyboardEvent(LKeyboardEventType t, LKey k, bool s, bool c):LEvent(LEventType::Keyboard){
	mtype=t;
	key=k;
	shift=s;
	ctrl=c;
}
LKeyboardEventType LKeyboardEvent::getKeyboardType() const{
	return mtype;
}
LKey LKeyboardEvent::getKey() const{
	return key;
}
bool LKeyboardEvent::getShift() const{
	return shift;
}
bool LKeyboardEvent::getCtrl() const{
	return ctrl;
}

