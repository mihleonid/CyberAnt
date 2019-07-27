#include "settingscontroller.h"
#include "settingsview.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lcheckboxswitcher.h"
#include "ui/lkeyboardlistener.h"
#include "fieldcontroller.h"
#include "gamecontrollerevent.h"
#include "configurator.h"
#include "acallback.h"

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
	typedef class:public ACallback<Event*, bool>{
		private:
			std::string f;
			std::string y;
			std::string n;
		public:
			ACallback<Event*, bool>* init(std::string file, std::string ch, std::string nc){
				f=file;
				y=ch;
				n=nc;
				return (ACallback<Event*, bool>*)this;
			}
			virtual Event* call(bool b){
				if(b){
					if(y.size()){
						Configurator::setTextToFile(f, y);
					}
				}else{
					if(n.size()){
						Configurator::setTextToFile(f, n);
					}
				}
				return nullptr;
			}
	} configput;
	LCheckBox* smooth=new LCheckBox(Rect(win->getCenter().setDY(-20).setDX(-70), win->getCenter().setDY(0).setDX(70)), Configurator::getSmoothString(), (new configput)->init("smooth", "Y", "N"));
	smooth->setColor(LColor(true, 0, 50, 240));
	smooth->setChecked(Configurator::getSmooth());
	return (new LScene())
	->add(new LKeyboardListener(K_Q, new back))
	->add(smooth)
	->add((new LButton(Rect(win->getCenter().setDY(20).setDX(-70), win->getCenter().setDY(40).setDX(70)), Configurator::getBack(), new back))->setColor(LColor(true, 0, 50, 240)));
}

