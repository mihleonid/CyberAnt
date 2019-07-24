#include "menucontroller.h"
#include "menuview.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lkeyboardlistener.h"
#include "fieldcontroller.h"
#include "settingscontroller.h"
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
			LWindow* win;
			virtual Event* call(){
				return new GameControllerEvent(new SettingsController(win));
			}
	} settings;
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(true, false);
			}
	} exit;
	play* p=new play;
	play* p2=new play;
	settings* set=new settings;
	settings* set2=new settings;
	p->win=win;
	p2->win=win;
	set->win=win;
	set2->win=win;
	return (new LScene())
	->add((new LButton(Rect(win->getCenter().setDY(-50).setDX(-70), win->getCenter().setDY(-30).setDX(70)), Configurator::getPlay(), p))->setColor(LColor(true, 0, 50, 240)))
	->add((new LButton(Rect(win->getCenter().setDY(-10).setDX(-70), win->getCenter().setDY(10).setDX(70)), Configurator::getSettings(), set))->setColor(LColor(true, 0, 50, 240)))
	->add(new LKeyboardListener(K_P, p2))
	->add(new LKeyboardListener(K_S, set2))
	->add(new LKeyboardListener(K_Q, new exit))
	->add((new LButton(Rect(win->getCenter().setDY(30).setDX(-70), win->getCenter().setDY(50).setDX(70)), Configurator::getExit(), new exit))->setColor(LColor(true, 0, 50, 240)));
}

