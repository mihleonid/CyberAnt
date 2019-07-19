#pragma once
#include "leventtype.h"
#include "levent.h"

enum LKeyboardEventType{
	KEY_Up,
	KEY_Down,
};
enum LKey{
	K_0,
	K_1,
	K_2,
	K_3,
	K_4,
	K_5,
	K_6,
	K_7,
	K_8,
	K_9,
	K_A,
	K_D,
	K_H,
	K_J,
	K_K,
	K_L,
	K_S,
	K_W,

	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_UP,
};
class LKeyboardEvent:public LEvent{
	private:
		LKeyboardEventType mtype;
		LKey key;
		bool shift;
		bool ctrl;
	public:
		LKeyboardEvent(LKeyboardEventType, LKey, bool s, bool c);
		LKeyboardEventType getKeyboardType() const;
		bool getShift() const;
		bool getCtrl() const;
};


