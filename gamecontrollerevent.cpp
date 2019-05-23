#include "gamecontrollerevent.h"

GameControllerEvent::GameControllerEvent(int fupsdelta){
	FUPSDelta=fupsdelta;
}
GameControllerEvent::GameControllerEvent(Controller* newctl){
	newCtl=newctl;
}
GameControllerEvent::GameControllerEvent(Controller* newctl, int d){
	newCtl=newctl;
	delHist=d;
}
GameControllerEvent::GameControllerEvent(bool e, bool b){
	exit=e;
	back=b;
}

virtual bool GameControllerEvent::forGameController(){
	return true;
}

