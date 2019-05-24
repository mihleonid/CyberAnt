#pragma once
#include <stack>
#include "controller.h"

class GameController{
	private:
		Controller* currentController;
		std::stack<Controller*> history;

		Uint32 mLastFrame; // Время прошлого кадра
		int FUPS=26; // FPS=UPS=...

		void initFps(); // Записать время первого кадра
		void delayFps(); // Сделать задержку

		void loop(); // Игровой цикл

		void changeController(Controller* ctl, bool h); // h - записывать ли в историю текущий
		void clearHist(int k); // k>0 -> удаляет последние k. k<0 -> оставляет первые -k.
		bool back(); // Нужно ли выходить

	public:
		GameController();
		~GameController();
};

