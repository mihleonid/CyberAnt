#pragma once
// Этот класс нужен для поля (список непустых)
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
		int remove(int pos); // Номер, кого нужно обновить
		T operator[](int pos);

		friend class XStackIterator;
};

