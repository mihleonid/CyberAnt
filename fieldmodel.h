#pragma once
class FieldModel;
#include "field.h"
#include "event.h"
#include "resourceset.h"

class FieldModel{
	private:
		bool baseBuilded=false; // Нельзя строить много баз
	public:
		Field field; // Поле, на котором ведётся игра
		Resourceset* rset; // Ресурсы в базе
		void applyEvent(Event* c); // Пока такой механизм событий. Нужно будет изменить потом.
		void loop(); // Проход цикла
		void start(); // Начало
		void stop(); // Конец
};

