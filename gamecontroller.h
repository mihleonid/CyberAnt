#pragma once
class GameController;
#include "ui.h"
#include "fieldmodel.h"

class GameController{
	public:
		Controller* currentController;

		// Идёт ли игра?
		bool gaming;
		// FPS=UPS=...
		int FUPS=26;

		GameController();
		~GameController();
		void start(); // Начать игру
		void stop(); // Остановить игру
	private:
		View* fieldView;
		Model* fieldModel;
		Uint32 mLastFrame; // Время прошлого кадра
		void initFps(); // Записать время первого кадра
		void delayFps(); // Сделать задержку
		void loop(); // Игровой цикл

		Controller* changeController(Controller* ctl); // Возвращает текущий
};

