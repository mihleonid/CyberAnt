#include <fstream>
#include "ltsurface.h"

LTSurface::LTSurface(){
	surf=nullptr;
	w=0;
	h=0;
}
int LTSurface::getW() const{
	return w;
}
int LTSurface::getH() const{
	return h;
}
LTSurface::LTSurface(int x, int y){
	w=x;
	h=y;
	if(x*y!=0){
		surf=new std::pair<char, LColor>[x*y];
	}else{
		surf=nullptr;
	}
}
LTSurface::LTSurface(const LTSurface& a){
	w=a.getW();
	h=a.getH();
	if(w*h!=0){
		surf=new std::pair<char, LColor>[w*h];
	}else{
		surf=nullptr;
	}
	for(int x=0;x<w;++x){
		for(int y=0;y<h;++y){
			set(x, y, a.get(x, y));
		}
	}
}
LTSurface::LTSurface(const LTSurface& a, const LColor& c){
	w=a.getW();
	h=a.getH();
	if(w*h!=0){
		surf=new std::pair<char, LColor>[w*h];
	}else{
		surf=nullptr;
	}
	for(int x=0;x<w;++x){
		for(int y=0;y<h;++y){
			set(x, y, a.get(x, y));
		}
	}
	applyColors(c);
}
LTSurface::~LTSurface(){
	if(surf!=nullptr){
		delete surf;
	}
}
LTSurface::LTSurface(const char* c){
	std::ifstream str(c);
	str>>w>>h;
	surf=new std::pair<char, LColor>[w*h];
	char curl;
	LColor curc;
	for(int y=0;y<h;++y){
		for(int x=0;x<w;++x){
			str>>curl;
			if(curl=='^'){
				str>>curl;
				if((curl=='S')||(curl=='s')){
					curc=LColor(1, 1, 1);
				}
				if(((char)std::tolower(curl))!=curl){
					// Capital
					curc.setFg(LMonoColor(((char)(std::tolower(curl)))));
				}else{
					// Small
					curc.setBg(LMonoColor(curl));
				}
				str>>curl;
			}
			set(x, y, curl, curc);
		}
	}
	str.close();
}
std::pair<char, LColor> LTSurface::get(int x, int y) const{
	return surf[y*w+h];
}
void LTSurface::set(int x, int y, char c, LColor col){
	set(x, y, std::pair<char, LColor>(c, col));
}
void LTSurface::set(int x, int y, std::pair<char, LColor> p){
	surf[y*w+h]=p;
}
void LTSurface::applyColors(LColor c){//TODO const
	for(int i=0;i<w*h;++i){
		if(surf[i].second==LColor(1, 1, 1)){
			surf[i].second=c;
		}
	}
}

