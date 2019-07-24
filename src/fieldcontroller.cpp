#include "fieldcontroller.h"
#include "fieldmodel.h"
#include "fieldview.h"
#include "fieldevent.h"
#include "gamecontrollerevent.h"
#include "configurator.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"

FieldController::FieldController(LWindow* win){
	initialize(new FieldModel, new FieldView, win);
}
LScene* FieldController::generateUIScene(){
	typedef class:public Callback<Event*>{
		public:
		virtual Event* call(){
			return new GameControllerEvent(false, true);
		}
	} back;
	typedef class:public Callback<Event*>{
		public:
		FOWhat type;
		virtual Event* call(){
			return new FieldEvent(EPrefab, type);
		}
	} pfsel;
	pfsel* pbase=new pfsel();
	pbase->type=BBase;
	pfsel* pimine=new pfsel();
	pimine->type=BIMine;
	pfsel* pomine=new pfsel();
	pomine->type=BOMine;
	return (new LScene)
	->add((new LButton(Rect(0), Configurator::getBack(), new back()))->setColor(LColor(true, 1, 0, 0)))
	->add((new LButton(Rect(0, 75), "Base", pbase))->setColor(LColor(true, 1, 0, 0)))
	->add((new LButton(Rect(0, 95), "Iron mine", pimine))->setColor(LColor(true, 1, 0, 0)))
	->add((new LButton(Rect(0, 115), "Oxygen mine", pomine))->setColor(LColor(true, 1, 0, 0)));
}

