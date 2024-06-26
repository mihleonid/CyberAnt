#pragma once
#include <string>
#include "foenum.h"
#include "resource.h"
#include "ui/lquality.h"

class Configurator{
	private:
		static std::string wtitle;
		static std::string back;
		static std::string exit;
		static std::string play;
		static std::string settings;
		static std::string baseContains;
		static std::string currentPrefab;
		static std::string currentLocale;
		static std::string smoothString;
		static std::string qualityL;
		static std::string qualityM;
		static std::string qualityH;
		static std::string qualityU;
		static std::string gameOver;
		static LQuality quality;
		static bool qualityGetted;
		static bool smooth;
		static bool smoothGetted;
		static void getCurrentLocale();
	public:
		static void configureResourceNode(ResourceType type, int& add, int& addPossible, int& taxMin, int& taxMax, int& startVal);
		static const char* getWindowTitle();
		static const char* getBack();
		static const char* getExit();
		static const char* getPlay();
		static const char* getSettings();
		static const char* getCurrentPrefab();
		static const char* getBaseContains();
		static const char* getSmoothString();
		static const char* getQualityL();
		static const char* getQualityM();
		static const char* getQualityH();
		static const char* getQualityU();
		static const char* getGameOver();
		static std::string getLocalePath();
		static std::string getTextFromFile(std::string path); // without assets dir and txt
		static void setTextToFile(std::string path, std::string text); // without assets dir and txt
		static std::string getLocalizedTextFromFile(std::string path); // without assets dir and txt, from assets/{currentLocale}/
		static LQuality getQuality();
		static bool getSmooth();
};

