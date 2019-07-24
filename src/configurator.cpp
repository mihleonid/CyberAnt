#include <fstream>
#include <iostream>
#include <cassert>
#include <string>
#include "configurator.h"
#include "common.hpp"

std::string Configurator::wtitle="";
std::string Configurator::back="";
std::string Configurator::exit="";
std::string Configurator::play="";
std::string Configurator::baseContains="";
std::string Configurator::currentPrefab="";
std::string Configurator::currentLocale="";
void Configurator::configureResourceNode(ResourceType t, int& add, int& addP, int& taxMin, int& taxMax, int& startVal){
	add=-1;
	addP=10;
	taxMin=0;
	taxMax=20;
	startVal=100;
	//TODO from files
}
//TODO fast read;
#define getString(A, B){\
	getCurrentLocale();\
	if(A.empty()){\
		std::ifstream file((ASSETS_DIR+currentLocale+"/"+std::string(B)+".txt").c_str());\
		if(!file.good()){\
			std::cerr<<(ASSETS_DIR+currentLocale+"/"+std::string(B)+".txt").c_str()<<" is a bad file"<<std::endl;\
		}\
		assert(file.good());\
		std::string s;\
		bool start=false;\
		while(file>>s){\
			if(start){\
				A+=" ";\
			}\
			start=true;\
			A+=s;\
		}\
		file.close();\
	}\
	return A.c_str();\
}
void Configurator::getCurrentLocale(){
	if(currentLocale.empty()){
		std::ifstream file(ASSETS_DIR "currentlocale.txt");
		if(!file.good()){
			std::cerr<<ASSETS_DIR<<"currentlocale.txt is a bad file"<<std::endl;
		}
		assert(file.good());
		file>>currentLocale;
		file.close();
	}
}
const char* Configurator::getWindowTitle(){
	getString(wtitle, "wintitle");
}
const char* Configurator::getPlay(){
	getString(play, "play");
}
const char* Configurator::getBack(){
	getString(back, "back");
}
const char* Configurator::getExit(){
	getString(exit, "exit");
}
const char* Configurator::getBaseContains(){
	getString(baseContains, "basecontains");
}
const char* Configurator::getCurrentPrefab(){
	getString(currentPrefab, "currentprefab");
}
#undef getString

