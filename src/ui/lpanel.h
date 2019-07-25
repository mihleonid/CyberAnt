#pragma once
#include "lrectedcomponent.h"
#include "lcolor.h"

class LScene;

class LPanel:public LRectedComponent{
	private:
		LColor col;
		LScene* scn;
	public:
		LPanel* setColor(const LColor&);
		LColor getColor() const;
		LScene* getScene();
		LPanel(Rect p);
		virtual ~LPanel();
		virtual void draw(LDrawer*);
		virtual EventQueue applyEvent(LEvent*);
		virtual std::vector<LEventType> acceptedTypes();
};

