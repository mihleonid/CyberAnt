#include "fieldcontroller.h"
#include "fieldmodel.h"
#include "fieldview.h"
#include "fieldeventlistener.h"
#include "fieldevent.h"
#include "fo.h"
#include "gamecontrollerevent.h"
#include "configurator.h"
#include "ui/lscene.h"
#include "ui/lbutton.h"
#include "ui/lkeyboardlistener.h"

void FieldController::init(LWindow* win){
	initialize(new FieldModel, new FieldView, new FieldEventListener, win);
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
	LScene* scn=(new LScene)->add((new LButton(Rect(0), Configurator::getBack(), new back()))->setColor(LColor(true, 1, 0, 0)));
	scn->add(new LKeyboardListener(K_Q, new back));
	int y=75;
	for(FOWhat w:FO::getAllWhats()){
		pfsel* p=new pfsel();
		p->type=w;
		scn->add((new LButton(Rect(0, y), FO::whatToLocalizedString(w), p))->setColor(LColor(true, 1, 0, 0)));
		y+=20;
	}
	return scn;
}

