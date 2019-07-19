#pragma once
#include <stack>
#include "controller.h"

class GameController{
	private:
		Controller* currentController;
		std::stack<Controller*> hist;

		uint mLastFrame; // Время прошлого кадра
		uint FUPS=26; // FPS=UPS=...

		void initFps(); // Записать время первого кадра
		void delayFps(); // Сделать задержку

		void loop(); // Игровой цикл

		void changeController(Controller* ctl);
		void clearHist(int k); // k>0 -> удаляет последние k. k<0 -> оставляет первые -k.
		bool back(); // Нужно ли выходить

	public:
		GameController();
		~GameController();
};

