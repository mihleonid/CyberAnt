#pragma once
#include <string>
#include <map>
#include <vector>

//Типы ресурсов
enum ResourceType{Iron, Oxygen, Cristall}; // При изменении нужно исправить resource.cpp, при желании --- создать возможность постройки в foenum, fieldmodelmodel, fieldview.

class Resource{
	private:
		static std::map<ResourceType, std::string> resourceTypeCache;
	public:
		static ResourceType randomType();
		static std::string typeToString(ResourceType typ);
		static std::string typeToLocalizedString(ResourceType typ);
		static ResourceType stringToType(std::string str);
		static std::vector<ResourceType> getAllTypes();
};

