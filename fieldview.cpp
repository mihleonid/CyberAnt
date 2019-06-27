#include <iostream>
#include "configurator.h"
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
	/*
	const FieldModel* model=(const FieldModel*)mode;
	clamp(scrollX, -20, BlocksX*FW-SCREEN_W+20);
	clamp(scrollY, -20, BlocksY*FH-SCREEN_H+20);
	SDL_RenderClear(ren);
	for(int i=0;i<BlocksX;i++){
		for(int j=0;j<BlocksY;j++){
			const FO* c=model->field.get(i, j);
			if(c==nullptr){
				draw(FW*i-scrollX, FH*j-scrollY, ass->getFieldTex());
			}else{
				SDL_Texture* tex=c->getTexture(ass, ren);
				draw(FW*i-scrollX, FH*j-scrollY, tex);
				SDL_DestroyTexture(tex);
			}
		}
	}
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
	SDL_RenderPresent(ren);
	*/
}
EventQueue FieldView::getEvents(){
	SDL_Event evt;
	EventQueue v;
	/*
	while(SDL_PollEvent(&evt)){
		if(evt.type==SDL_QUIT){
			v.push(new GameControllerEvent(true, false));
			break;
		}
		if(evt.type==SDL_MOUSEMOTION){
			if(mouseDown){
				mouseMoved=true;
				scrollX-=evt.motion.x-mouseX;
				scrollY-=evt.motion.y-mouseY;
				mouseX=evt.motion.x;
				mouseY=evt.motion.y;
			}
		}
		if(evt.type==SDL_MOUSEBUTTONDOWN){
			mouseDown=true;
			mouseX=evt.motion.x;
			mouseY=evt.motion.y;
		}
		if(evt.type==SDL_MOUSEBUTTONUP){
			mouseDown=false;
			if(!mouseMoved){
				int x=evt.button.x+scrollX;//screen coordinats
				int y=evt.button.y+scrollY;
				x/=FW;//field coordinats
				y/=FH;
				clamp(x, 0, BlocksX);
				clamp(y, 0, BlocksY);
				v.push(new FieldEvent(EBuild, Point(x, y), BBase));
				v.push(new FieldEvent(EBuild, Point(x, y), BIMine));
			}
			mouseMoved=false;
		}
		if(evt.type==SDL_KEYDOWN){
			switch (evt.key.keysym.sym){
				case SDLK_1:
					v.push(new GameControllerEvent(-1));
					break;
				case SDLK_2:
					v.push(new GameControllerEvent(1));
					break;
				case SDLK_d:
					if(evt.key.keysym.mod&KMOD_CTRL){
						scrollX+=3;
					}
					if(evt.key.keysym.mod&KMOD_SHIFT){
						scrollX+=3;
					}
					scrollX+=2;
				case SDLK_RIGHT:
					scrollX++;
					break;
				case SDLK_a:
					if(evt.key.keysym.mod&KMOD_CTRL){
						scrollX-=3;
					}
					if(evt.key.keysym.mod&KMOD_SHIFT){
						scrollX-=3;
					}
					scrollX-=2;
				case SDLK_LEFT:
					scrollX--;
					break;
				case SDLK_s:
					if(evt.key.keysym.mod&KMOD_CTRL){
						scrollY+=3;
					}
					if(evt.key.keysym.mod&KMOD_SHIFT){
						scrollY+=3;
					}
					scrollY+=2;
				case SDLK_DOWN:
					scrollY++;
					break;
				case SDLK_w:
					if(evt.key.keysym.mod&KMOD_CTRL){
						scrollY-=3;
					}
					if(evt.key.keysym.mod&KMOD_SHIFT){
						scrollY-=3;
					}
					scrollY-=2;
				case SDLK_UP:
					scrollY--;
					break;
				case SDLK_ESCAPE:
					v.push(new GameControllerEvent(true, false));
					break;
				default:
					break;
			}
		}
	}
	*/
	return v;
}
void FieldView::init(){
	scrollX=0;
	scrollY=0;
	mouseDown=false;
	mouseMoved=false;
	win=new LWindow(Configurator::getWindowTitle());
	//ass=new Assets(nullptr/*ren*/);//TODO
}
FieldView::~FieldView() {
    delete ass;
}
#undef FW
#undef FH

