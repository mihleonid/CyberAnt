#include <algorithm>
#include <SDL.h>
#include "lcontrol.h"
#include "../subscriber.h"
#include "levent.h"
#include "lmouseevent.h"
#include "lkeyboardevent.h"

const std::map<const SDL_Keycode, const LKey> LSControlMap = {
    {SDLK_0, LKey::K_0},
    {SDLK_1, LKey::K_1},
    {SDLK_2, LKey::K_2},
    {SDLK_3, LKey::K_3},
    {SDLK_4, LKey::K_4},
    {SDLK_5, LKey::K_5},
    {SDLK_6, LKey::K_6},
    {SDLK_7, LKey::K_7},
    {SDLK_8, LKey::K_8},
    {SDLK_9, LKey::K_9},
    {SDLK_a, LKey::K_A},
    {SDLK_d, LKey::K_D},
    {SDLK_h, LKey::K_H},
    {SDLK_j, LKey::K_J},
    {SDLK_k, LKey::K_K},
    {SDLK_l, LKey::K_L},
    {SDLK_s, LKey::K_S},
    {SDLK_w, LKey::K_W},
    {SDLK_RIGHT, LKey::K_RIGHT},
    {SDLK_LEFT, LKey::K_LEFT},
    {SDLK_UP, LKey::K_UP},
    {SDLK_DOWN, LKey::K_DOWN},
};
void LControl::loop(){
	SDL_Event evt;
	while(SDL_PollEvent(&evt)){
		if(evt.type==SDL_QUIT){
			q.push(new LEvent(LEventType::Exit));
			return;
		}
		if(evt.type==SDL_MOUSEMOTION){
			q.push(new LMouseEvent(LMouseEventType::MOUSE_Move, Point(evt.motion.x, evt.motion.y)));
		}
		if(evt.type==SDL_MOUSEBUTTONDOWN){
			q.push(new LMouseEvent(LMouseEventType::BUTTON_Down, Point(evt.motion.x, evt.motion.y)));
		}
		if(evt.type==SDL_MOUSEBUTTONUP){
			q.push(new LMouseEvent(LMouseEventType::BUTTON_Up, Point(evt.motion.x, evt.motion.y)));
		}
		if(evt.type==SDL_KEYDOWN){
			switch (evt.key.keysym.sym){
				case SDLK_ESCAPE:
					{
						q.push(new LEvent(LEventType::Exit));
						return;
					}
				default:
					{
						if(LSControlMap.count(evt.key.keysym.sym)){
							q.push(new LKeyboardEvent(LKeyboardEventType::KEY_Down, LSControlMap.at(evt.key.keysym.sym), evt.key.keysym.mod&KMOD_SHIFT, evt.key.keysym.mod&KMOD_CTRL));
						}
						break;
					}
			}
		}
	}
}
LEvent* LControl::next(){
	if(q.empty()){
		return nullptr;
	}
	LEvent* e=q.front();
	q.pop();
	for(int i=0;i<subs[e->getType()].size();++i){
		subs[e->getType()][i]->applyEvent(e);
	}
	return e;
}
void LControl::subscribe(Subscriber* s, LEventType t){
	subs[t].push_back(s);
}
void LControl::unsubscribe(Subscriber* s, LEventType t){
	subs[t].erase(std::remove(subs[t].begin(), subs[t].end(), s), subs[t].end());
}
void LControl::unsubscribe(Subscriber* s){
	for(auto i=subs.begin();i!=subs.end();++i){
		unsubscribe(s, i->first);
	}
}

