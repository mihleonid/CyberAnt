#include "menucontroller.h"
#include "menuview.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lkeyboardlistener.h"
#include "fieldcontroller.h"
#include "gamecontrollerevent.h"
#include "configurator.h"

MenuController::MenuController(LWindow* win){
	initialize(nullptr, new MenuView, win);
}
LScene* MenuController::generateUIScene(){
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
	return (new LScene())
	->add((new LButton(Rect(win->getCenter().setDY(-40).setDX(-70), win->getCenter().setDY(-20).setDX(70)), Configurator::getPlay(), p))->setColor(LColor(true, 0, 50, 240)))
	->add(new LKeyboardListener(K_P, p2))
	->add(new LKeyboardListener(K_Q, new exit))
	->add((new LButton(Rect(win->getCenter().setDY(20).setDX(-70), win->getCenter().setDY(40).setDX(70)), Configurator::getExit(), new exit))->setColor(LColor(true, 0, 50, 240)));
}

