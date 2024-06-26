#pragma once
#include "event.h"
#include "controller.h"

class GameControllerEvent:public Event{
	private:
		int FUPSDelta=0;
		Controller* newCtl=nullptr;
		bool exit=false;
		int back=0;
		int delHist=0; // Сколько удалять из истории переходов. -k значит оставить первые k. +k или k=0 значит удалить последние k.
		// История переходов: мы из меню идём в режим игры, потом хотим обратно - вызываем back
		// Меню -> игра -> пауза -> меню. Тут не должно быть никакого назад - чистим историю.
	public:
		GameControllerEvent(int FUPSDelta);
		GameControllerEvent(bool exit, bool back);
		GameControllerEvent(bool exit, int back);
		GameControllerEvent(Controller* newCtl, int delhist);
		GameControllerEvent(Controller* newCtl);

		int getFUPSDelta() const;
		int getDeleting() const;
		bool getExit() const;
		int getBack() const;
		Controller* getController();

		virtual bool forGameController() const;
};

