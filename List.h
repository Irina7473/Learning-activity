#pragma once
#include "Element.h"
#define tab "\t"

class List
{
	Element* Head;  //Указатель на начальный элемент списка
public:
	List();	
	List(initializer_list<int> list); //конструктор из контейнера
	List(const List& other);
	List(List&& other);
	~List()	{cout << "LDestructor:\t" << this << endl;}
	
	Element* getHead()const { return Head; }
	Element* getElement(int ind)const;  //поиск элемента по индексу
	Element* search_data_list(int data)const;  //поиск элемента по значению
	int lengthList();  //нахождение длины списка
	void push_front(int Data); //добавление элемента в начало списка
	void push_back(int Data); //добавление элемента в конец списка
	void insert(int ind, int Data); //добавление элемента по индексу

	void pop_front();	//Удаляет начальный элемент списка
	void pop_back();	//Удаляет последний элемент списка
	void erase(int ind);	//Удаляет значение из списка по указанному индексу
	
	void print();
	
	List& operator =(const List& other);
	List& operator =(List&& other);

	Element* operator[](const int ind)
	{	return this->getElement(ind); }
		
};
ostream& operator<<(ostream& os, const List& list);
List operator +(const List& left, const List& right);

