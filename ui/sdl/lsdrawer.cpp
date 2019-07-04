#include "lsdrawer.h"

LSDrawer::LSDrawer(SDL_Renderer* r){
	ren=r;
}
LSDrawer::~LSDrawer(){
	if(ren!=nullptr){
		SDL_DestroyRenderer(ren);
	}
}
Rect LSDrawer::draw(int x, int y, SDL_Texture* tex){
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(ren, tex, NULL, &pos);
	return Rect(Point(pos.w+pos.x, pos.h+pos.y), Point(pos.w, pos.h));
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
	return Rect(Point(pos.w+pos.x, pos.h+pos.y), Point(pos.w, pos.h));
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
	return Rect(Point(pos.w+pos.x, pos.h+pos.y), Point(pos.w, pos.h));
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
	//TODO
	TTF_Font* font=nullptr;
	SDL_Color white={(Uint8)(col.fg().r()), (Uint8)(col.fg().g()), (Uint8)(col.fg().b())};
	SDL_Surface* surfaceMessage=TTF_RenderText_Solid(font, c, white);
	SDL_Texture* message=SDL_CreateTextureFromSurface(ren, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	return message;
}
void LSDrawer::clear(){
	SDL_RenderClear(ren);
}
void LSDrawer::present(){
	SDL_RenderPresent(ren);
}

void LSDrawer::color(){
	col.def();
}
void LSDrawer::color(LColor c){
	col=c;
}

