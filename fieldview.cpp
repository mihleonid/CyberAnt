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
	win->update();
	//TODO Draw from lwindow
	//TODO LComponent caching texture
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
			if(c==nullptr){
				img=ass->get("field");
			}else{
				img=c->getImage(ass);
			}
			win->getDrawer()->draw(FW*i-scrollX, FH*j-scrollY, img);
			delete img;
		}
	}
	/*
	int ay=drawTextRight(SCREEN_W, 0, "Base contains: ").second;
	int x=drawText(0, 0, "FPS: ").first;
	drawText(x, 0, 24); // TODO FUPS and GameControleer data
	std::pair<int, int> c=drawTextRight(SCREEN_W, ay, model->rset->get(Iron));
	int y=drawTextRight(SCREEN_W-c.first, ay, "Iron: ").second;
	y=mmax(y, c.second);
	std::pair<int, int> cc=drawTextRight(SCREEN_W, ay+y, model->rset->get(Oxygen));
	int yy=drawTextRight(SCREEN_W-cc.first, ay+y, "Oxygen: ").second;
	yy=mmax(y+yy, c.second+yy);
	std::pair<int, int> ccc=drawTextRight(SCREEN_W, ay+yy, model->rset->get(Cristall));
	drawTextRight(SCREEN_W-ccc.first, ay+yy, "Cristall: ").second;
	*/

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
			return new GameControllerEvent(true, false);
		}
	} exit;
	win->getScene()->add(new LButton(Rect(0), "EXIT", new exit()));
}
FieldView::~FieldView(){
	delete ass;
}
#undef FW
#undef FH

