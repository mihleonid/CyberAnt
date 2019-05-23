#pragma once
class GameController;
#include "ui.h"
#include "fieldmodel.h"

class GameController{
	public:
		GameController();
		~GameController();
	private:
		Controller* currentController;

		Uint32 mLastFrame; // Время прошлого кадра
		int FUPS=26; // FPS=UPS=...

		void initFps(); // Записать время первого кадра
		void delayFps(); // Сделать задержку

		void loop(); // Игровой цикл

		Controller* changeController(Controller* ctl); // Возвращает текущий
};

