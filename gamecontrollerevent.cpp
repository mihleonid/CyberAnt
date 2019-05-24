#include "gamecontrollerevent.h"

GameControllerEvent::GameControllerEvent(int fupsdelta){
	FUPSDelta=fupsdelta;
}
GameControllerEvent::GameControllerEvent(Controller* newctl, bool h){
	newCtl=newctl;
	leaveHist=h;
}
GameControllerEvent::GameControllerEvent(Controller* newctl){
	newCtl=newctl;
	leaveHist=true;
}
GameControllerEvent::GameControllerEvent(Controller* newctl, int d){
	newCtl=newctl;
	delHist=d;
}
GameControllerEvent::GameControllerEvent(bool e, bool b){
	exit=e;
	back=b;
}

int GameControllerEvent::getFUPSDelta(){
	return FUPSDelta;
}
bool GameControllerEvent::getBack(){
	return back;
}
bool GameControllerEvent::getExit(){
	return exit;
}
bool GameControllerEvent::getLeaving(){
	return leaveHist;
}
int GameControllerEvent::getDeleting(){
	return delHist;
}
Controller* GameControllerEvent::getController(){
	return newCtl;
}

virtual bool GameControllerEvent::forGameController(){
	return true;
}

