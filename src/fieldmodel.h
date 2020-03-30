#pragma once
#include "model.h"
#include "field.h"
#include "event.h"
#include "resourceset.h"

class FieldModel:public Model{
	private:
		bool baseBuilded=false; // Нельзя строить много баз
		FOWhat prefab=BBase;
	public:
		Field field; // Поле, на котором ведётся игра
		ResourceSet* rset; // Ресурсы в базе

		FieldModel();
		FOWhat getPrefab() const;
		void applyEvent(Event* c);
		EventQueue loop(); // Проход цикла
		virtual ~FieldModel();
};

