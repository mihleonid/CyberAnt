#include <cassert>
#include <SDL.h>
#include <SDL2/SDL_ttf.h>
#include "lsdrawer.h"

LSDrawer::LSDrawer(SDL_Renderer* r){
	ren=r;
	font=TTF_OpenFont("assets/ubuntumono.ttf", 21);
	assert(font!=nullptr);
	assert(ren!=nullptr);
}
LSDrawer::~LSDrawer(){
	SDL_DestroyRenderer(ren);
	TTF_CloseFont(font);
}
void LSDrawer::drawRect(const Rect& r, const LColor& c){
	if(c.bg().transparent()){
		return;
	}
	SDL_SetRenderDrawColor(ren, c.bg().r(), c.bg().g(), c.bg().b(), 0);
	SDL_Rect re;
	re.x=r.getA().getX();
	re.y=r.getA().getY();
	re.w=r.getB().getX()-r.getA().getX();
	re.h=r.getB().getY()-r.getA().getY();
	SDL_RenderFillRect(ren, &re);
}
void LSDrawer::drawRect(const Rect& r){
	drawRect(r, col);
}
Rect LSDrawer::draw(int x, int y, LImage* img){
	return draw(x, y, img->newTexture(ren));
}
Rect LSDrawer::draw(int x, int y, LImage* img, const LColor& c){
	return draw(x, y, img->newTexture(c, ren));
}
Rect LSDrawer::draw(int x, int y, SDL_Texture* tex){
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(ren, tex, NULL, &pos);
	return Rect(Point(pos.x, pos.y), Point(pos.w+pos.x, pos.h+pos.y));
}
Rect LSDrawer::drawText(int x, int y, const char* text){
	SDL_Texture* txt=makeText(ren, text);
	Rect res=draw(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
Rect LSDrawer::drawText(int x, int y, int text){
	SDL_Texture* txt=makeText(ren, std::to_string(text).c_str());
	Rect res=draw(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}

Rect LSDrawer::drawRight(int x, int y, SDL_Texture* tex){
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	pos.x-=pos.w;
	SDL_RenderCopy(ren, tex, NULL, &pos);
	return Rect(Point(pos.x, pos.y), Point(pos.w+pos.x, pos.h+pos.y));
}
Rect LSDrawer::drawTextRight(int x, int y, const char* text){
	SDL_Texture* txt=makeText(ren, text);
	Rect res=drawRight(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
Rect LSDrawer::drawTextRight(int x, int y, int text){
	SDL_Texture* txt=makeText(ren, std::to_string(text).c_str());
	Rect res=drawRight(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}

Rect LSDrawer::drawCenter(int x, int y, SDL_Texture* tex){
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	pos.x-=pos.w/2;
	SDL_RenderCopy(ren, tex, NULL, &pos);
	return Rect(Point(pos.x, pos.y), Point(pos.w+pos.x, pos.h+pos.y));
}
Rect LSDrawer::drawTextCenter(int x, int y, const char* text){
	SDL_Texture* txt=makeText(ren, text);
	Rect res=drawCenter(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
Rect LSDrawer::drawTextCenter(int x, int y, int text){
	SDL_Texture* txt=makeText(ren, std::to_string(text).c_str());
	Rect res=drawCenter(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
SDL_Texture* LSDrawer::makeText(SDL_Renderer* ren, const char* c){
	SDL_Color white={(Uint8)(col.fg().r()), (Uint8)(col.fg().g()), (Uint8)(col.fg().b())};
	SDL_Surface* surfaceMessage=TTF_RenderUTF8_Solid(font, c, white);
	SDL_Texture* message=SDL_CreateTextureFromSurface(ren, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	return message;
}
void LSDrawer::clear(){
	color();
	SDL_RenderClear(ren);
}
void LSDrawer::clear(const LColor& c){
	color(c);
	SDL_RenderClear(ren);
	color();
}
void LSDrawer::present(){
	SDL_RenderPresent(ren);
}

void LSDrawer::color(){
	col.def();
	SDL_SetRenderDrawColor(ren, col.bg().r(), col.bg().g(), col.bg().b(), 0);
}
void LSDrawer::color(const LColor& c){
	col=c;
	SDL_SetRenderDrawColor(ren, col.bg().r(), col.bg().g(), col.bg().b(), 0);
}
