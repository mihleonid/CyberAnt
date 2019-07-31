#include "gameovercontroller.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lwindow.h"
#include "ui/lkeyboardlistener.h"
#include "fieldcontroller.h"
#include "settingscontroller.h"
#include "gamecontrollerevent.h"
#include "configurator.h"

void GameOverController::init(LWindow* win){
	initialize(nullptr, nullptr, nullptr, win);
}
LScene* GameOverController::generateUIScene(){
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(false, 2);
			}
	} backa;
	return (new LScene())
	->add(new LKeyboardListener(K_Q, new backa))
	->add((new LButton(Rect(win->getCenter().setDY(30).setDX(-70), win->getCenter().setDY(50).setDX(70)), Configurator::getBack(), new backa))->setColor(LColor(true, 0, 50, 240)));
}

