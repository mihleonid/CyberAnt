#pragma once
#include <queue>

class LEvent;

class LControl{
	private:
		std::queue<LEvent*> q;
	public:
		void loop();
		LEvent* next();

};

