#include <map>
#include <SDL.h>
#include "lcontrol.h"
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
    {SDLK_b, LKey::K_B},
    {SDLK_c, LKey::K_C},
    {SDLK_d, LKey::K_D},
    {SDLK_e, LKey::K_E},
    {SDLK_f, LKey::K_F},
    {SDLK_g, LKey::K_G},
    {SDLK_h, LKey::K_H},
    {SDLK_i, LKey::K_I},
    {SDLK_j, LKey::K_J},
    {SDLK_k, LKey::K_K},
    {SDLK_l, LKey::K_L},
    {SDLK_m, LKey::K_M},
    {SDLK_n, LKey::K_N},
    {SDLK_o, LKey::K_O},
    {SDLK_p, LKey::K_P},
    {SDLK_q, LKey::K_Q},
    {SDLK_r, LKey::K_R},
    {SDLK_s, LKey::K_S},
    {SDLK_t, LKey::K_T},
    {SDLK_u, LKey::K_U},
    {SDLK_v, LKey::K_V},
    {SDLK_w, LKey::K_W},
    {SDLK_x, LKey::K_X},
    {SDLK_y, LKey::K_Y},
    {SDLK_z, LKey::K_Z},

    {SDLK_RIGHT, LKey::K_RIGHT},
    {SDLK_LEFT, LKey::K_LEFT},
    {SDLK_UP, LKey::K_UP},
    {SDLK_DOWN, LKey::K_DOWN},
    {SDLK_RETURN, LKey::K_ENTER},
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
			q.push(new LMouseEvent(LMouseEventType::BUTTON_Down, Point(evt.button.x, evt.button.y)));
		}
		if(evt.type==SDL_MOUSEBUTTONUP){
			q.push(new LMouseEvent(LMouseEventType::BUTTON_Up, Point(evt.button.x, evt.button.y)));
		}
		if(evt.type==SDL_KEYDOWN){
			switch (evt.key.keysym.sym){
				case SDLK_ESCAPE:
					{
						q.push(new LEvent(LEventType::Back));
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
	return e;
}

