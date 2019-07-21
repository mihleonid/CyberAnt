#include <fstream>
#include <cassert>
#include <string>
#include "configurator.h"

std::string Configurator::wtitle="";
std::string Configurator::back="";
std::string Configurator::exit="";
std::string Configurator::play="";
void Configurator::configureResourceNode(ResourceType t, int& add, int& addP, int& taxMin, int& taxMax, int& startVal){
	add=-1;
	addP=10;
	taxMin=0;
	taxMax=20;
	startVal=100;
	//TODO from files
}
const char* Configurator::getWindowTitle(){
	if(wtitle.empty()){
		std::ifstream file("./assets/wintitle.txt");
		assert(file.good());
		file>>wtitle;
		file.close();
	}
	return wtitle.c_str();
}
const char* Configurator::getPlay(){
	if(play.empty()){
		std::ifstream file("./assets/play.txt");
		assert(file.good());
		file>>play;
		file.close();
	}
	return play.c_str();
}
const char* Configurator::getBack(){
	if(back.empty()){
		std::ifstream file("./assets/back.txt");
		assert(file.good());
		file>>back;
		file.close();
	}
	return back.c_str();
}
const char* Configurator::getExit(){
	if(exit.empty()){
		std::ifstream file("./assets/exit.txt");
		assert(file.good());
		file>>exit;
		file.close();
	}
	return exit.c_str();
}

