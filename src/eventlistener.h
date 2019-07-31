#pragma once
#include <queue>
#include "eventqueue.h"
#include "ui/levent.h"
#include "view.h"

class EventListener{
	public:
		virtual EventQueue getEvents(std::queue<LEvent*>, View*); //Здесь использована прямая коммуникация
		virtual ~EventListener();
};

