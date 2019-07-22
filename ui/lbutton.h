#pragma once
#include <string>
#include "lcomponent.h"
#include "lcolor.h"
#include "../callback.h"

class LButton:public LComponent{
	private:
		std::string text;
		Callback<Event*>* onClick;
		bool expand=true; // For optimization
		bool down=false; // For drag over button
		LColor col;
	public:
		LButton* setColor(const LColor&);
		LColor getColor() const;
		LButton(Rect p, std::string t, Callback<Event*>*);
		LButton(Rect p, const char* t, Callback<Event*>*);
		virtual ~LButton();
		virtual void draw(LDrawer*);
		virtual std::pair<Event*, bool> applyEvent(LEvent*);
};

