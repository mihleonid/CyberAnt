#define "ldrawer.h"

std::pair<int, int> LDrawer::draw(int x, int y, SDL_Texture* tex) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(ren, tex, NULL, &pos);
    return std::pair<int, int>(pos.w, pos.h);
}
std::pair<int, int> LDrawer::drawText(int x, int y, const char* text){
	SDL_Texture* txt=makeText(ren, text);
	std::pair<int, int> res=draw(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
std::pair<int, int> LDrawer::drawText(int x, int y, int text){
	SDL_Texture* txt=makeText(ren, std::to_string(text).c_str());
	std::pair<int, int> res=draw(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}

std::pair<int, int> LDrawer::drawRight(int x, int y, SDL_Texture* tex) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    pos.x-=pos.w;
    SDL_RenderCopy(ren, tex, NULL, &pos);
    return std::pair<int, int>(pos.w, pos.h);
}
std::pair<int, int> LDrawer::drawTextRight(int x, int y, const char* text){
	SDL_Texture* txt=makeText(ren, text);
	std::pair<int, int> res=drawRight(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
std::pair<int, int> LDrawer::drawTextRight(int x, int y, int text){
	SDL_Texture* txt=makeText(ren, std::to_string(text).c_str());
	std::pair<int, int> res=drawRight(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}

std::pair<int, int> LDrawer::drawCenter(int x, int y, SDL_Texture* tex) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    pos.x-=pos.w/2;
    SDL_RenderCopy(ren, tex, NULL, &pos);
    return std::pair<int, int>(pos.w, pos.h);
}
std::pair<int, int> LDrawer::drawTextCenter(int x, int y, const char* text){
	SDL_Texture* txt=makeText(ren, text);
	std::pair<int, int> res=drawCenter(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
std::pair<int, int> LDrawer::drawTextCenter(int x, int y, int text){
	SDL_Texture* txt=makeText(ren, std::to_string(text).c_str());
	std::pair<int, int> res=drawCenter(x, y, txt);
	SDL_DestroyTexture(txt);
	return res;
}
SDL_Texture* LDrawer::makeText(SDL_Renderer* ren, const char* c){
	SDL_Color white={255, 255, 255};
	SDL_Surface* surfaceMessage=TTF_RenderText_Solid(font, c, white);
	SDL_Texture* message=SDL_CreateTextureFromSurface(ren, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	return message;
}

Rect LDrawer::drawTextT(int x, int y, const char* c, int len){
	T_GOTO(x, y);
	std::cout<<c;
	return Rect(Point(x, y), Point(x+len, y));
}
Rect LDrawer::drawTextT(int x, int y, const char* c){
	int len=0;
	while(c[len]){
		++len;
	}
	return drawTextT(x, y, c, len);
}
Rect LDrawer::drawTextT(int x, int y, int text){
	return drawTextT(x, y, std::to_string(text).c_str());
}

Rect LDrawer::drawTextRightT(int x, int y, const char* c, int len){
	T_GOTO(x-len, y);
	std::cout<<c;
	return Rect(Point(x-len, y), Point(x, y));
}
Rect LDrawer::drawTextRightT(int x, int y, const char* c){
	int len=0;
	while(c[len]){
		++len;
	}
	return drawTextRightT(x, y, c, len);
}
Rect LDrawer::drawTextRightT(int x, int y, int text){
	return drawTextRightT(x, y, std::to_string(text).c_str());
}

Rect LDrawer::drawTextCenterT(int x, int y, const char* c, int len){
	T_GOTO(x-(len/2), y);
	std::cout<<c;
	return Rect(Point(x-(len/2), y), Point(x, y));
}
Rect LDrawer::drawTextCenterT(int x, int y, const char* c){
	int len=0;
	while(c[len]){
		++len;
	}
	return drawTextCenterT(x, y, c, len);
}
Rect LDrawer::drawTextCenterT(int x, int y, int text){
	return drawTextCenterT(x, y, std::to_string(text).c_str());
}

