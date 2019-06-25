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
}
EventQueue FieldView::getEvents(){
	SDL_Event evt;
	EventQueue v;
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
	return v;
}
void FieldView::init(){
	scrollX=0;
	scrollY=0;
	mouseDown=false;
	mouseMoved=false;
	win = SDL_CreateWindow(Configurator::getWindowTitle(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
	if (win == nullptr) {
		std::cerr << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
		throw 1;
	}
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (ren == nullptr) {
		std::cerr << "SDL_CreateRenderer error: " << SDL_GetError() << std::endl;
		throw 1;
	}
	if (TTF_Init() != 0) {
		std::cerr << "TTF_Init error" << std::endl;
		throw 1;
	}
	ass=new Assets(ren);
}
FieldView::~FieldView() {
    delete ass;
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
}
std::pair<int, int> FieldView::draw(int x, int y, SDL_Texture* tex) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(ren, tex, NULL, &pos);
    return std::pair<int, int>(pos.w, pos.h);
}
std::pair<int, int> FieldView::drawText(int x, int y, const char* text){
	SDL_Texture* txt=ass->makeText(ren, text);
	std::pair<int, int> res=draw(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
std::pair<int, int> FieldView::drawText(int x, int y, int text){
	SDL_Texture* txt=ass->makeText(ren, std::to_string(text).c_str());
	std::pair<int, int> res=draw(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}

std::pair<int, int> FieldView::drawRight(int x, int y, SDL_Texture* tex) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    pos.x-=pos.w;
    SDL_RenderCopy(ren, tex, NULL, &pos);
    return std::pair<int, int>(pos.w, pos.h);
}
std::pair<int, int> FieldView::drawTextRight(int x, int y, const char* text){
	SDL_Texture* txt=ass->makeText(ren, text);
	std::pair<int, int> res=drawRight(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
std::pair<int, int> FieldView::drawTextRight(int x, int y, int text){
	SDL_Texture* txt=ass->makeText(ren, std::to_string(text).c_str());
	std::pair<int, int> res=drawRight(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
#undef FW
#undef FH

