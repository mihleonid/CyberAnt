#pragma once
#include "foenum.h"
#include "resource.h"

class Configurator{
	public:
		static void configureResourceNode(ResourceType type, int& add, int& addPossible, int& taxMin, int& taxMax, int& startVal);
		static const char* getWindowTitle();
};

