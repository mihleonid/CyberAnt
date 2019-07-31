#include "fieldeventlistener.h"
#include "fieldevent.h"
#include "gamecontrollerevent.h"
#include "fieldview.h"
#include "ui/lmouseevent.h"
#include "ui/lkeyboardevent.h"
#include "common.hpp"

EventQueue FieldEventListener::getEvents(std::queue<LEvent*> q, View* vie){
	FieldView* view=dynamic_cast<FieldView*>(vie);
	EventQueue v;
	while(!(q.empty())){
		LEvent* evt=q.front();
		q.pop();
		if(evt->getType()==LEventType::Mouse){
			LMouseEvent* mevt=(LMouseEvent*)evt;
			if(mevt->getMouseType()==MOUSE_Move){
				if(view->mouseDown){
					view->mouseMoved=true;
					view->scrollX-=mevt->getPos().getX()-view->mouseX;
					view->scrollY-=mevt->getPos().getY()-view->mouseY;
					view->mouseX=mevt->getPos().getX();
					view->mouseY=mevt->getPos().getY();
				}
			}
			if(mevt->getMouseType()==BUTTON_Down){
				view->mouseDown=true;
				view->mouseX=mevt->getPos().getX();
				view->mouseY=mevt->getPos().getY();
			}
			if(mevt->getMouseType()==BUTTON_Up){
				view->mouseDown=false;
				if(!view->mouseMoved){
					int x=mevt->getPos().getX()+view->scrollX;//screen coordinats
					int y=mevt->getPos().getY()+view->scrollY;
					x/=FW;//field coordinats
					y/=FH;
					clamp(x, 0, BlocksX);
					clamp(y, 0, BlocksY);
					v.push(new FieldEvent(EUpgrade, Point(x, y)));
					v.push(new FieldEvent(EBuild, Point(x, y)));
				}
				view->mouseMoved=false;
			}
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
						view->scrollX+=3;
					}
					if(kevt->getShift()){
						view->scrollX+=3;
					}
					view->scrollX+=2;
				case K_RIGHT:
					view->scrollX++;
					break;
				case K_A:
					if(kevt->getCtrl()){
						view->scrollX-=3;
					}
					if(kevt->getShift()){
						view->scrollX-=3;
					}
					view->scrollX-=2;
				case K_LEFT:
					view->scrollX--;
					break;
				case K_S:
					if(kevt->getCtrl()){
						view->scrollY+=3;
					}
					if(kevt->getShift()){
						view->scrollY+=3;
					}
					view->scrollY+=2;
				case K_DOWN:
					view->scrollY++;
					break;
				case K_W:
					if(kevt->getCtrl()){
						view->scrollY-=3;
					}
					if(kevt->getShift()){
						view->scrollY-=3;
					}
					view->scrollY-=2;
				case K_UP:
					view->scrollY--;
					break;
				default:
					break;
			}
			continue;
		}
	}
	return v;
}

