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
	if(b){
		back=1;
	}
}
GameControllerEvent::GameControllerEvent(bool e, int b){
	exit=e;
	back=b;
}

int GameControllerEvent::getFUPSDelta() const{
	return FUPSDelta;
}
int GameControllerEvent::getBack() const{
	return back;
}
bool GameControllerEvent::getExit() const{
	return exit;
}
int GameControllerEvent::getDeleting() const{
	return delHist;
}
Controller* GameControllerEvent::getController(){
	return newCtl;
}

bool GameControllerEvent::forGameController() const{
	return true;
}

