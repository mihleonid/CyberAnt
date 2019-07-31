#include "settingscontroller.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lwindow.h"
#include "ui/lcheckboxswitcher.h"
#include "ui/lkeyboardlistener.h"
#include "fieldcontroller.h"
#include "gamecontrollerevent.h"
#include "configurator.h"
#include "acallback.h"

void SettingsController::init(LWindow* win){
	initialize(nullptr, nullptr, nullptr, win);
}
LScene* SettingsController::generateUIScene(){
	typedef class:public Callback<Event*>{
		public:
			virtual Event* call(){
				return new GameControllerEvent(false, true);
			}
	} backi;
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
	//TODO relative
	LCheckBox* ql=new LCheckBox(Rect(win->getCenter().setDY(-60).setDX(-70), win->getCenter().setDY(-40).setDX(70)), Configurator::getQualityL(), (new configput)->init("quality", "L", ""));
	ql->setColor(LColor(true, 0, 50, 240));
	ql->setChecked(Configurator::getQuality()==LQLow);
	LCheckBox* qm=new LCheckBox(Rect(win->getCenter().setDY(-100).setDX(-70), win->getCenter().setDY(-80).setDX(70)), Configurator::getQualityM(), (new configput)->init("quality", "M", ""));
	qm->setChecked(Configurator::getQuality()==LQMedium);
	qm->setColor(LColor(true, 0, 50, 240));
	LCheckBox* qh=new LCheckBox(Rect(win->getCenter().setDY(-140).setDX(-70), win->getCenter().setDY(-120).setDX(70)), Configurator::getQualityH(), (new configput)->init("quality", "H", ""));
	qh->setChecked(Configurator::getQuality()==LQHigh);
	qh->setColor(LColor(true, 0, 50, 240));
	LCheckBox* qu=new LCheckBox(Rect(win->getCenter().setDY(-180).setDX(-70), win->getCenter().setDY(-160).setDX(70)), Configurator::getQualityU(), (new configput)->init("quality", "U", ""));
	qu->setChecked(Configurator::getQuality()==LQUltra);
	qu->setColor(LColor(true, 0, 50, 240));
	LCheckBoxSwitcher* qswitcher=new LCheckBoxSwitcher(Rect(win->getCenter().setDY(-180).setDX(-70), win->getCenter().setDY(-40).setDX(70)));
	qswitcher
		->add(ql)
		->add(qm)
		->add(qh)
		->add(qu);
	return (new LScene())
	->add(new LKeyboardListener(K_Q, new backi))
	->add(smooth)
	->add(qswitcher)
	->add((new LButton(Rect(win->getCenter().setDY(20).setDX(-70), win->getCenter().setDY(40).setDX(70)), Configurator::getBack(), new backi))->setColor(LColor(true, 0, 50, 240)));
}

