#pragma once
#include <set>
// Этот класс нужен для поля (список не пустых)
template<class T> class XStack{
	private:
		int maxs; // Максимальный размер

		T* arr;
		int top;

		int* dels; // Номера, которыми было замещено удаление
		int delc; // Количество удалённых
	public:
		XStack(int maxsize);
		int push(T el); // returns new element index
		T pop();
		T get();
		int size();
		T get(int pos);
		std::pair<int*, int>  getDeleted(); // Когда жлемент удаляется, вместо него ставится другой
		int remove(int pos); // Номер, кого нужно обновить
		T operator[](int pos);
};

