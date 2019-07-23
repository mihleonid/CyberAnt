#pragma once
#include <queue>
#include <map>
#include <vector>
#include "../subscriber.h"
#include "leventtype.h"
class LEvent;

class LControl{
	private:
		std::queue<LEvent*> q;
		std::map<LEventType, std::vector<Subscriber*>> subs;
	public:
		void loop();
		LEvent* next();

		void subscribe(Subscriber*, LEventType);
		void unsubscribe(Subscriber*, LEventType);
		void unsubscribe(Subscriber*);
};

