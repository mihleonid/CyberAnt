#pragma once
#include <map>
#include "resource.h"

class ResourceSet{
	private:
		std::map<ResourceType, int> contain;
	public:
		ResourceSet();
		ResourceSet(ResourceType type, int count);
		bool empty() const;
		bool empty(ResourceType type) const;
		int get(ResourceType type) const;

		void add(ResourceType type, int a);
		void add(const ResourceSet& another);

		int sub(ResourceType type, int a); // Возвращает, сколько осталось
		ResourceSet sub(const ResourceSet& another); // Аналогично
};

