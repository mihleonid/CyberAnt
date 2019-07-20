#pragma once
#include <string>
#include <map>
#include "ui/limage.h"

class Assets{ // Class for loading and caching limages
	private:
		std::map<std::string, LImage*> cache;
	public:
		LImage* getNode(std::string type);
		LImage* getMine(std::string type);
		LImage* get(std::string str);
		~Assets();
};

