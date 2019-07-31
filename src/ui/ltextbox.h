#pragma once
#include <string>
#include "lcomponent.h"

//TODO Anchors
class LTextBox:public LComponent{
	private:
		Point pos;
		std::string text;
	public:
		LTextBox(Point p, std::string t);
		LTextBox(Point p, const char* t);
		virtual ~LTextBox();
		virtual void draw(LDrawer*);
		virtual EventQueue applyEvent(LEvent*);
		virtual std::vector<LEventType> acceptedTypes();
};

