#pragma once
#include "event.h"
#include "controller.h"

class GameControllerEvent:public Event{
	private:
		int FUPSDelta=0;
		Controller* newCtl=nullptr;
		bool exit=false;
		bool back=false;
		int delHist=0; // Сколько удалять из истории переходов. -k значит оставить первые k. +k или k=0 значит удалить последние k.
		// История переходов: мы из меню идём в режим игры, потом хотим обратно - вызываем back
		// Меню -> игра -> пауза -> меню. Тут не должно быть никакого назад - чистим историю.
	public:
		GameControllerEvent(int FUPSDelta);
		GameControllerEvent(bool exit, bool back);
		GameControllerEvent(Controller* newCtl, int delhist);
		GameControllerEvent(Controller* newCtl);

		int getFUPSDelta();
		int getDeleting();
		bool getExit();
		bool getBack();
		Controller* getController();

		virtual bool forGameController();
};

