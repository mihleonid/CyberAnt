#include <iostream>
#include <string>
#include <queue>
#include "configurator.h"
#include "resource.h"
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

void FieldView::loop(const Model* mode){
	win->clear();
	win->getDrawer()->color(LColor(true, 1, 0, 0));
	//TODO Draw from lwindow
	const FieldModel* model=(const FieldModel*)mode;
	clamp(scrollX, -70, BlocksX*FW-win->getW()+20);
	clamp(scrollY, -160, BlocksY*FH-win->getH()+20);
	for(int i=0;i<BlocksX;i++){
		for(int j=0;j<BlocksY;j++){
			if(FW*i-scrollX+FW<0){
				continue;
			}
			if(FW*i-scrollX>win->getW()){
				continue;
			}
			if(FW*i-scrollX+FH<0){
				continue;
			}
			if(FH*j-scrollY>win->getH()){
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
			if(c!=nullptr){
				if(c->getHealth()!=c->getMaxHealth()){
					Point start=Point(FW*i-scrollX, FH*j-scrollY+FH-2);
					win->getDrawer()->drawRect(Rect(start, start.setDY(2).setDX(FW*c->getHealth()/c->getMaxHealth())), LColor(true, 255, 0, 0));
				}
			}
		}
	}
	Point fps=win->getDrawer()->drawText(0, 20, "FPS: ").getB();
	win->getDrawer()->drawText(fps.getX(), 20, win->getFps());

	if(model->rset!=nullptr){
		Rect crect=win->getDrawer()->drawTextRight(win->getCorner().getX(), 0, (std::string(Configurator::getBaseContains())+std::string(": ")).c_str());
		for(ResourceType t:Resource::getAllTypes()){
			crect=win->getDrawer()->drawTextRight(crect.getB(), model->rset->get(t));
			win->getDrawer()->drawTextRight(crect.getA(), (Resource::typeToLocalizedString(t)+": ").c_str());
		}
	}

	Rect prefab=win->getDrawer()->drawText(Point(0, 52), (std::string(Configurator::getCurrentPrefab())+std::string(": ")).c_str());
	win->getDrawer()->drawText(Point(prefab.getB().getX(), prefab.getA().getY()), FO::whatToLocalizedString(model->getPrefab()).c_str());

	win->draw();
}
void FieldView::init(LWindow* cwin){
	scrollX=0;
	scrollY=0;
	mouseDown=false;
	mouseMoved=false;
	win=cwin;
	ass=new Assets();
}
FieldView::~FieldView(){
	delete ass;
}

