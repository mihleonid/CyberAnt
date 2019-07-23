#pragma once
#include "foenum.h"
#include "resource.h"

class Configurator{
	private:
		static std::string wtitle;
		static std::string back;
		static std::string exit;
		static std::string play;
		static std::string baseContains;
		static std::string currentPrefab;
	public:
		static void configureResourceNode(ResourceType type, int& add, int& addPossible, int& taxMin, int& taxMax, int& startVal);
		static const char* getWindowTitle();
		static const char* getBack();
		static const char* getExit();
		static const char* getPlay();
		static const char* getCurrentPrefab();
		static const char* getBaseContains();
};

