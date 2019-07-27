#pragma once
#include <string>
#include "lrectedcomponent.h"
#include "lcolor.h"
#include "../callback.h"
#include "../acallback.h"

class LCheckBox:public LRectedComponent{
	private:
		std::string text;
		bool expand=true; // For optimization
		bool down=false; // For drag over button
		LColor col;
		bool checked;
		bool round;
		ACallback<Event*, bool>* onStateChanged;
	public:
		bool getChecked();
		LCheckBox* setChecked(bool);
		LCheckBox* setRound(bool);
		LCheckBox* setColor(const LColor&);
		LColor getColor() const;
		LCheckBox(Rect p, std::string t, ACallback<Event*, bool>* onStateChanged);
		LCheckBox(Rect p, const char* t, ACallback<Event*, bool>* onStateChanged);
		virtual ~LCheckBox();
		virtual void draw(LDrawer*);
		virtual EventQueue applyEvent(LEvent*);
		virtual std::vector<LEventType> acceptedTypes();
};

