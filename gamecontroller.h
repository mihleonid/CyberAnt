#pragma once
#include "controller.h"

class GameController{
	private:
		Controller* currentController;

		Uint32 mLastFrame; // Время прошлого кадра
		int FUPS=26; // FPS=UPS=...

		void initFps(); // Записать время первого кадра
		void delayFps(); // Сделать задержку

		void loop(); // Игровой цикл

		Controller* changeController(Controller* ctl); // Возвращает текущий

	public:
		GameController();
		~GameController();
};

