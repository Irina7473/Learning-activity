#pragma once
#include<iostream>
using namespace std;

class Element
{
	int Data;        //значение элемента
	Element* pNext;  //адрес следующего элемента
public:
	int getData()const { return Data; }
	Element* getpNext()const { return pNext; }
	void setData(int Data) { this->Data =Data; }
	void setpNext(Element* pNext) { this->pNext=pNext; }

	Element(int Data, Element* pNext);
	Element(const Element& other);
	Element(Element&& other);
	~Element(){cout << "EDestructor:\t" << this << endl;}

	Element& operator =(const Element& other);
	Element& operator =(Element&& other);

	friend class List;
};

