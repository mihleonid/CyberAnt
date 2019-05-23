#pragma once
class FieldModel;
#include "model.h"
#include "field.h"
#include "event.h"
#include "resourceset.h"

class FieldModel:public Model{
	private:
		bool baseBuilded=false; // Нельзя строить много баз
	public:
		Field field; // Поле, на котором ведётся игра
		Resourceset* rset; // Ресурсы в базе

		FieldModel();
		void applyEvent(void* c); // Пока такой механизм событий. Нужно будет изменить потом.
		void loop(); // Проход цикла
		~FieldModel();
};
