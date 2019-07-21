#include "configurator.h"

void Configurator::configureResourceNode(ResourceType t, int& add, int& addP, int& taxMin, int& taxMax, int& startVal){
	add=-1;
	addP=10;
	taxMin=0;
	taxMax=20;
	startVal=100;
	//TODO from files
}
const char* Configurator::getWindowTitle(){
	return "CyberAnt";
}
const char* Configurator::getPlay(){
	return "Play";
}
const char* Configurator::getBack(){
	return "Back";
}
const char* Configurator::getExit(){
	return "Exit";
}

