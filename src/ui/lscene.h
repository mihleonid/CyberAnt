#pragma once
#include <vector>
#include "leventsender.h"

class LComponent;
class LDrawer;
class LEvent;

class LScene:public LEventSender{
	private:
		std::vector<LComponent*> cps;
	public:
		LScene* add(LComponent*);
		LScene* erase(LComponent*);
		void clear();
		void clearDelete();
		void draw(LDrawer*);
		EventQueue applyEvent(LEvent*);
		~LScene();
};

