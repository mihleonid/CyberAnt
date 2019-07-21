#include <iostream>
#include <queue>
#include "configurator.h"
#include "callback.h"
#include "ui/lbutton.h"
#include "ui/levent.h"
#include "ui/leventtype.h"
#include "ui/lmouseevent.h"
#include "ui/lkeyboardevent.h"
#include "point.h"
#include "gamecontrollerevent.h"
#include "fieldevent.h"
#include "fieldview.h"
#include "fo.h"
#include "fieldmodel.h"
#include "common.hpp"

#define FW 64
#define FH 64

void FieldView::loop(const Model* mode){
	win->setScene(scn);
	win->clear();
	//TODO Draw from lwindow
	const FieldModel* model=(const FieldModel*)mode;
	clamp(scrollX, -20, BlocksX*FW-SCREEN_W+20);
	clamp(scrollY, -20, BlocksY*FH-SCREEN_H+20);
	for(int i=0;i<BlocksX;i++){
		for(int j=0;j<BlocksY;j++){
			if(FW*i-scrollX+FW<0){
				continue;
			}
			if(FW*i-scrollX>SCREEN_W){
				continue;
			}
			if(FW*i-scrollX+FH<0){
				continue;
			}
			if(FH*j-scrollY>SCREEN_H){
				continue;
			}
			const FO* c=model->field.get(i, j);
			LImage* img;
			LColor col(255, 0, 0);
			if(c==nullptr){
				img=ass->get("field");
			}else{
				std::pair<LImage*, LColor> pair=c->getImage(ass);
				img=pair.first;
				col=pair.second;
			}
			win->getDrawer()->draw(FW*i-scrollX, FH*j-scrollY, img, col);
		}
	}
	Rect baseContains=win->getDrawer()->drawTextRight(win->getCorner().getX(), 0, "Base contains: ");
	Point fps=win->getDrawer()->drawText(0, 20, "FPS: ").getB();
	win->getDrawer()->drawText(fps.getX(), 20, win->getFps()); // TODO FUPS and GameControleer data
	Rect iron=win->getDrawer()->drawTextRight(baseContains.getB(), model->rset->get(Iron));
	win->getDrawer()->drawTextRight(iron.getA(), "Iron: ");
	Rect oxygen=win->getDrawer()->drawTextRight(iron.getB(), model->rset->get(Oxygen));
	win->getDrawer()->drawTextRight(oxygen.getA(), "Oxygen: ");
	Rect cristall=win->getDrawer()->drawTextRight(oxygen.getB(), model->rset->get(Cristall));
	win->getDrawer()->drawTextRight(cristall.getA(), "Cristall: ");

	win->draw();
	win->present();
}
EventQueue FieldView::getEvents(){
	std::pair<EventQueue, std::queue<LEvent*>> pair=win->getEvents();
	EventQueue v=pair.first;
	std::queue<LEvent*> q=pair.second;
	while(!(q.empty())){
		LEvent* evt=q.front();
		q.pop();
		if(evt->getType()==LEventType::Exit){
			v.push(new GameControllerEvent(true, false));
			delete evt;
			break;
		}
		if(evt->getType()==LEventType::Mouse){
			LMouseEvent* mevt=(LMouseEvent*)evt;
			if(mevt->getMouseType()==MOUSE_Move){
				if(mouseDown){
					mouseMoved=true;
					scrollX-=mevt->getPos().getX()-mouseX;
					scrollY-=mevt->getPos().getY()-mouseY;
					mouseX=mevt->getPos().getX();
					mouseY=mevt->getPos().getY();
				}
			}
			if(mevt->getMouseType()==BUTTON_Down){
				mouseDown=true;
				mouseX=mevt->getPos().getX();
				mouseY=mevt->getPos().getY();
			}
			if(mevt->getMouseType()==BUTTON_Up){
				mouseDown=false;
				if(!mouseMoved){
					int x=mevt->getPos().getX()+scrollX;//screen coordinats
					int y=mevt->getPos().getY()+scrollY;
					x/=FW;//field coordinats
					y/=FH;
					clamp(x, 0, BlocksX);
					clamp(y, 0, BlocksY);
					v.push(new FieldEvent(EUpgrade, Point(x, y), BBase));
					v.push(new FieldEvent(EBuild, Point(x, y), BBase));
					v.push(new FieldEvent(EBuild, Point(x, y), BIMine));
				}
				mouseMoved=false;
			}
			delete mevt;
			continue;
		}
		if(evt->getType()==Keyboard){
			LKeyboardEvent* kevt=(LKeyboardEvent*)evt;
			switch (kevt->getKey()){
				case K_1:
					v.push(new GameControllerEvent(-1));
					break;
				case K_2:
					v.push(new GameControllerEvent(1));
					break;
				case K_D:
					if(kevt->getCtrl()){
						scrollX+=3;
					}
					if(kevt->getShift()){
						scrollX+=3;
					}
					scrollX+=2;
				case K_RIGHT:
					scrollX++;
					break;
				case K_A:
					if(kevt->getCtrl()){
						scrollX-=3;
					}
					if(kevt->getShift()){
						scrollX-=3;
					}
					scrollX-=2;
				case K_LEFT:
					scrollX--;
					break;
				case K_S:
					if(kevt->getCtrl()){
						scrollY+=3;
					}
					if(kevt->getShift()){
						scrollY+=3;
					}
					scrollY+=2;
				case K_DOWN:
					scrollY++;
					break;
				case K_W:
					if(kevt->getCtrl()){
						scrollY-=3;
					}
					if(kevt->getShift()){
						scrollY-=3;
					}
					scrollY-=2;
				case K_UP:
					scrollY--;
					break;
				default:
					break;
			}
			delete kevt;
			continue;
		}
	}
	while(!(q.empty())){
		delete q.front();
		q.pop();
	}
	return v;
}
void FieldView::init(LWindow* cwin){
	scrollX=0;
	scrollY=0;
	mouseDown=false;
	mouseMoved=false;
	win=cwin;
	ass=new Assets();
	typedef class:public Callback<Event*>{
		public:
		virtual Event* call(){
			return new GameControllerEvent(false, true);
		}
	} back;
	scn=(new LScene)
	->add(new LButton(Rect(0), Configurator::getBack(), new back()));
}
FieldView::~FieldView(){
	delete ass;
	delete scn;
}
#undef FW
#undef FH

