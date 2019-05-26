#pragma once
#include <string>

//Типы ресурсов
enum ResourceType{RIron, ROxygen, RCristall}; // При изменении нужно исправить resource.cpp, при желании --- создать возможность постройки в foenum, fieldmodelmodel, fieldview.

class Resource{
	public:
		static ResourceType randomType();
		static std::string typeToString(ResourceType typ);
		static ResourceType stringToType(std::string str);
}

