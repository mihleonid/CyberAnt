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
		void add(LComponent*);
		void erase(LComponent*);
		void clear();
		void clearDelete();
		void draw(LDrawer*);
		EventQueue applyEvent(LEvent*);
		~LScene();
};

