#pragma once
#include <map>
#include <vector>
#include "leventtype.h"
#include "../eventqueue.h"

class LSubscriber;
class LEvent;

class LEventSender{
	private:
		std::map<LEventType, std::vector<LSubscriber*>> subs;
		void subscribe(LSubscriber*, LEventType);
		void unsubscribe(LSubscriber*, LEventType);
	protected:
		EventQueue send(LEvent*);
	public:
		void subscribe(LSubscriber*);
		void unsubscribe(LSubscriber*);
};

