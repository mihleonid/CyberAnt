#include <queue>
#include "ui/lbutton.h"
#include "ui/levent.h"
#include "point.h"
#include "gamecontrollerevent.h"
#include "event.h"
#include "menuview.h"
#include "fieldcontroller.h"

void MenuView::loop(const Model* mode){
	win->update();
	win->present();
}
EventQueue MenuView::getEvents(){
	std::pair<EventQueue, std::queue<LEvent*>> pair=win->getEvents();
	while(!(pair.second.empty())){
		delete pair.second.front();
		pair.second.pop();
	}
	return pair.first;
}
void MenuView::init(LWindow* cwin){
	win=cwin;
	typedef class:public Callback<Event*>{
		public:
			LWindow* win;
			virtual Event* call(){
				return new GameControllerEvent(new FieldController(win));
			}
	} play;
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(true, false);
			}
	} exit;
	play* p=new play;
	p->win=win;
	win->getScene()->add(new LButton(Rect(Point(0)), "Play", p));//TODO win
	win->getScene()->add(new LButton(Rect(Point(0, 24)), "EXIT", new exit));
}

