#pragma once
#include <map>
#include "resource.h"

class ResourceSet{
	private:
		std::map<ResourceType, int> contain;
	public:
		ResourceSet();
		bool isEmpty(ResourceType type) const;
		int get(ResourceType type) const;

		void add(ResourceType type, int a);
		void add(ResourceSet& another);

		int sub(ResourceType type, int a); // Возвращает, сколько осталось
		ResourceSet sub(ResourceSet& another); // Аналогично
};

