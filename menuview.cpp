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
	win->setScene(scn);
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
	play* p2=new play;
	p->win=win;
	p2->win=win;
	scn=(new LScene())
	->add((new LButton(Rect(win->getCenter().setDY(-40).setDX(-70), win->getCenter().setDY(-20).setDX(70)), Configurator::getPlay(), p))->setColor(LColor(true, 0, 50, 240)))
	->add(new LKeyboardListener(K_P, p2))
	->add(new LKeyboardListener(K_Q, new exit))
	->add((new LButton(Rect(win->getCenter().setDY(20).setDX(-70), win->getCenter().setDY(40).setDX(70)), Configurator::getExit(), new exit))->setColor(LColor(true, 0, 50, 240)));
}
MenuView::~MenuView(){
	delete scn;
}

