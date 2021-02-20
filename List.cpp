#include "List.h"

List::List()
{
	Head = nullptr;
	cout << "LConstructor:\t" << this << endl;
}

List::List(initializer_list<int> list)
//конструктор из контейнера
{for (auto& element : list)	this->push_back(element) ;}
/*
//конструктор копирует только голову без элементов
List::List(const List& other) : Head(other.Head)
{cout << "LCopyConstructor:\t" << this << endl;}
*/
List::List(const List& other) 
//конструктор копирует все элементы
{
	Element* Temp = other.Head;
	while (Temp->getpNext() != nullptr)
	{
		push_back(Temp->getData());  
		Temp = Temp->getpNext();
	}
	push_back(Temp->getData());
	cout << "LCopyConstructor:\t" << this << endl;
}

List::List(List&& other) : Head(other.Head)
{
	other.Head = nullptr;
	cout << "LMoveConstructor:\t" << this << endl;
}

Element* List::getElement(int ind)const
//поиск элемента по индексу
{
	Element* Temp = Head;
	int i = 1;
	while (i < ind && Temp != NULL)
	{
		Temp = Temp->pNext;
		i++;
	}
	if (Temp == NULL)
		return 0;
	else
		return Temp;
}

Element* List::search_data_list(int data) const
//поиск элемента по значению
{
	Element* Temp = Head;
	if (Head != nullptr)
	{
		while (Temp->pNext != nullptr)
		{
			if (Temp->Data == data) return Temp;
			Temp = Temp->pNext;
		}
	}
	return Temp;
}

int List::lengthList()
//нахождение длины списка
{
	int length = 0;
	if (Head != nullptr)
	{ 
		Element* Temp = Head;
		while (Temp->pNext != nullptr) 
		{ 
			Temp = Temp->pNext; 
			length++;
		}
	}
	return ++length;
}

	void List:: push_front(int Data) 
	//добавление элемента в начало списка
	{   /*
		Element* New = new Element(Data);// создаем новый элемент
		New->pNext = Head;//присоединяем новый элемент к списку в начало
		Head = New;//в голову пишем адрес нового элемента
		*/
		Head = new Element(Data, Head);
	}

	void List::push_back(int Data)
		//добавление элемента в конец списка
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head; 
		while (Temp->pNext != nullptr) { Temp = Temp->pNext; }
		Temp->pNext = new Element(Data,nullptr);
	}

	void List:: insert(int ind, int Data) 
		//добавление элемента по индексу
	{
		if (ind > (lengthList()+1))
		{
			cout << "Номер индекса превышает размер списка, введите номер не больше, чем " << (lengthList()+1) << endl;
			cin >> ind;
		}
		if (ind == 1) push_front(Data);
		else this->getElement(ind-1)->pNext = new Element(Data, this->getElement(ind-1)->pNext);
	}

	void List::pop_front()//Удаляет начальный элемент списка
	{
		if (Head != nullptr)
		{
			Element* Temp = Head;
			Head = Temp->pNext;
			delete Temp;
		}
	}

	void List::pop_back()//Удаляет последний элемент списка
	{
		if (Head != nullptr)
		{
			Element* Temp = Head;
			while (Temp->pNext->pNext != nullptr)
				Temp = Temp->pNext;
			Temp->pNext->~Element();
			Temp->pNext= nullptr;
		}
	}

	void List::erase(int ind)//Удаляет значение из списка по указанному индексу
	{
		if (ind > lengthList())
		{
			cout << "Номер индекса превышает размер списка, введите номер не больше, чем " << lengthList() << endl;
			cin>> ind;
		}
		if (ind == 1) pop_front();
		else
		{
			Element* Temper = getElement(ind-1)->pNext;
			getElement(ind-1)->pNext = getElement(ind-1)->pNext->pNext;
			delete Temper;
		}
	}

		void List:: print()
	{
		Element* Temp = Head; //Temp-итератор, указатель для доступа к элементам
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; //переход на следующий элемент
		}
	}
		
	List& List::operator =(const List& other)
	{
		if (this != &other) Head = other.Head;
		return *this;
	}

	List& List::operator =(List&& other)
	{
		Head = other.Head;
		other.Head = nullptr;
		return *this;
	}

	ostream& operator<<(ostream& os, const List& list)
	{
		Element* Temp = list.getHead();
		while (Temp->getpNext() != nullptr)
		{
			os << Temp->getData() << tab;
			Temp = Temp->getpNext();
		}
		os << Temp->getData() << tab;
		cout << endl;
		return os;
	}
	/*
	List operator+(const List& left, const List& right)
	//я не копировала элементы в новый список, а только адреса первых
	//это не безопасно при изменении исходных списков
	//работает в паре с конструктором копирования только головы
	{
		List result(left);
		Element* Temp = left.getHead();
		while (Temp->getpNext() != nullptr)
			Temp = Temp->getpNext();
		Temp->setpNext(right.getHead());
		return result;
	}
	*/
	List operator+(const List& left, const List& right)
		//полное копирование списков с элементами
	{
		List result(left);
		Element* Temp = result.getHead();
		while (Temp->getpNext() != nullptr) 
			Temp = Temp->getpNext();   

		Temp = right.getHead();
		while (Temp->getpNext() != nullptr)
		{
			result.push_back(Temp->getData());
			Temp = Temp->getpNext();
		}
		result.push_back(Temp->getData());
		return result;
	}
