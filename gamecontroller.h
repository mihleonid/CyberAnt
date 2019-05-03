#pragma once
class GameController;
#include "ui.h"
#include "fieldmodel.h"

class GameController{
	public:
		// Динамическое выделение памяти для создания композиции рекомендуется всеми вокруг (а особенно в сочетании с cmake).
		// Чтобы потключать заголовки по одному щелчку пальца (представьте цикл a.h -> b.h -> a.h - ужас, а так с помощью class всё решается).
		UI* ui;
		FieldModel* mModel;

		// Идёт ли игра?
		bool gaming;
		// FPS=UPS=...
		int FUPS=26;

		GameController();
		~GameController();
		void start(); // Начать игру
		void stop(); // Остановить игру
	private:
		Uint32 mLastFrame; // Время прошлого кадра
		void initFps(); // Записать время первого кадра
		void delayFps(); // Сделать задержку
		void loop(); // Игровой цикл
};

