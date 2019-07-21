#include "menucontroller.h"
#include "menuview.h"

MenuController::MenuController(LWindow* win){
	initialize(nullptr, new MenuView, win);
}

