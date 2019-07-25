#include "settingscontroller.h"
#include "settingsview.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lkeyboardlistener.h"
#include "fieldcontroller.h"
#include "gamecontrollerevent.h"
#include "configurator.h"

SettingsController::SettingsController(LWindow* win){
	initialize(nullptr, new SettingsView, win);
}
LScene* SettingsController::generateUIScene(){
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(false, true);
			}
	} back;
	return (new LScene())
	->add(new LKeyboardListener(K_Q, new back))
	->add((new LButton(Rect(win->getCenter().setDY(20).setDX(-70), win->getCenter().setDY(40).setDX(70)), Configurator::getBack(), new back))->setColor(LColor(true, 0, 50, 240)));
}

