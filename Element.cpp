#include "Element.h"

Element:: Element(int Data, Element* pNext = nullptr) 
	: Data(Data), pNext(pNext)
{cout << "EConstructor:\t" << this << endl;}

Element::Element(const Element& other) 
	: Data(other.Data), pNext(other.pNext)
{cout << "ECopyConstructor:\t" << this << endl;}

Element::Element (Element&& other) 
	: Data(other.Data), pNext(other.pNext)
{
	other.pNext = nullptr;
	cout << "EMoveConstructor:\t" << this << endl;
}

Element& Element::operator =(const Element& other)
{
	if (this != &other)
	{
		Data = other.Data;
		pNext = other.pNext;
	}
	return *this;
}

Element& Element:: operator =(Element&& other)
{
	Data = other.Data;
	pNext = other.pNext;
	other.pNext = nullptr;
	return *this;
}