#include <queue>
#include "ui/lbutton.h"
#include "ui/lkeyboardlistener.h"
#include "ui/lkeyboardevent.h"
#include "ui/lcolor.h"
#include "ui/levent.h"
#include "ui/leventtype.h"
#include "point.h"
#include "gamecontrollerevent.h"
#include "event.h"
#include "configurator.h"
#include "menuview.h"
#include "fieldcontroller.h"

void MenuView::loop(const Model* mode){
	win->clear(LColor(true, 0, 120, 230));
	win->draw();
	win->present();
}
EventQueue MenuView::getEvents(){
	std::pair<EventQueue, std::queue<LEvent*>> pair=win->getEvents();
	while(!(pair.second.empty())){
		if(pair.second.front()->getType()==LEventType::Exit){
			pair.first.push(new GameControllerEvent(true, false));
		}
		if(pair.second.front()->getType()==LEventType::Back){
			pair.first.push(new GameControllerEvent(false, true));
		}
		delete pair.second.front();
		pair.second.pop();
	}
	return pair.first;
}
void MenuView::init(LWindow* cwin){
	win=cwin;
}
MenuView::~MenuView(){
}

