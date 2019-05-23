#pragma once
class ResourceSet;
#include <map>
#include "resource.h"

class ResourceSet{
	private:
		std::map<ResourceType, int> contain;
	public:
		ResourceSet();
		bool isEmpty(ResourceType type);
		int get(ResourceType type);

		void add(ResourceType type, int a);
		void add(ResourceSet& another);

		int sub(ResourceType type, int a); // Возвращает, сколько осталось
		ResourceSet sub(ResourceSet& another); // Аналогично
}
