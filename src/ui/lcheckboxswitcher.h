#pragma once
#include "lrectedcomponent.h"
#include "lcolor.h"
#include "lcheckbox.h"

class LCheckBoxSwitcher:public LRectedComponent{
	private:
		LColor col;
		std::vector<LCheckBox*> all;
	public:
		LCheckBoxSwitcher* setColor(const LColor&);
		LColor getColor() const;

		LCheckBoxSwitcher* add(LCheckBox*);

		LCheckBoxSwitcher(Rect p);
		~LCheckBoxSwitcher();

		virtual void draw(LDrawer*);
		virtual EventQueue applyEvent(LEvent*);
		virtual std::vector<LEventType> acceptedTypes();
};

