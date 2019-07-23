#pragma once
#include <vector>
#include "../eventqueue.h"

class LComponent;
class LDrawer;
class LEvent;

class LScene{
	private:
		std::vector<LComponent*> cps;
	public:
		LScene* add(LComponent*);
		LScene* erase(LComponent*);
		void clear();
		void clearDelete();
		void draw(LDrawer*);
		EventQueue applyEvent(LEvent*, bool& stop);
		~LScene();
};

