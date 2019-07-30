#include "menucontroller.h"
#include "menuview.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lkeyboardlistener.h"
#include "fieldcontroller.h"
#include "settingscontroller.h"
#include "gamecontrollerevent.h"
#include "configurator.h"

void MenuController::init(LWindow* win){
	initialize(nullptr, new MenuView, win);
}
LScene* MenuController::generateUIScene(){
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(new FieldController());
			}
	} play;
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(new SettingsController());
			}
	} settings;
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(true, false);
			}
	} exit;
	return (new LScene())
	->add((new LButton(Rect(win->getCenter().setDY(-50).setDX(-70), win->getCenter().setDY(-30).setDX(70)), Configurator::getPlay(), new play))->setColor(LColor(true, 0, 50, 240)))
	->add((new LButton(Rect(win->getCenter().setDY(-10).setDX(-70), win->getCenter().setDY(10).setDX(70)), Configurator::getSettings(), new settings))->setColor(LColor(true, 0, 50, 240)))
	->add(new LKeyboardListener(K_P, new play))
	->add(new LKeyboardListener(K_S, new settings))
	->add(new LKeyboardListener(K_Q, new exit))
	->add((new LButton(Rect(win->getCenter().setDY(30).setDX(-70), win->getCenter().setDY(50).setDX(70)), Configurator::getExit(), new exit))->setColor(LColor(true, 0, 50, 240)));
}

