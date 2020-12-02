#include "Class_Apartment.h" 

Apartment:: Apartment(int numAp, int area) : NumberAp{ numAp }, Area{ area }
{
	persons = new Person * [R];
	for (int i = 0; i < R; i++)
		persons[i] = nullptr;
}

Apartment:: Apartment(const Apartment& apart)
{
	NumberAp = apart.NumberAp;
	Area = apart.Area;
	R = apart.R;
	res = apart.res;
	persons = new Person * [R];
	for (int i = 0; i < res; i++)
		persons[i] = new Person(*apart.persons[i]);
}

Apartment:: ~Apartment()  
{
	for (int i = 0; i < res; i++)
		delete persons[i];
	delete[] persons;
}

Apartment& Apartment:: operator=(const Apartment& other)
{
	if (this != &other)  
	{
		this->~Apartment();
		res = other.res;

		NumberAp = other.NumberAp;
		Area = other.Area;

		persons = new Person * [R];
		for (int i = 0; i < res; i++)
			persons[i] = new Person(*other.persons[i]);
	}
	return *this;  
}

void Apartment:: addperson(const Person& person)
{

	Person* newperson = new Person(person);
	persons[res] = newperson;
	res++;
}

void Apartment:: delperson(string name)
{
	int f = findPerson(name);
	if (f != 100)
	{
		persons[f] = persons[res - 1];
		persons[res - 1] = nullptr;
		res--;
		cout << "Жилец удален" << endl;
		cout <<* this << endl;
	}
	else cout << "Контакт с ФИО " << name << " ненайден\n\n";
}

int Apartment::findPerson(string name)
{
	for (int i = 0; i < res; i++)
	{
		Person* pers = persons[i];
		if (pers->getName() == name)
			return i;
	}
	return 100;
}

void Apartment:: showpersonfone(int r) 
{
		cout << "Телефон жильцы квартиры № " << this->NumberAp << " " << persons[r]->getName() << " :" << endl;
		cout << persons[r]->getPhone() << endl;
		cout << endl;
}

ostream& operator<< (ostream & os, const Apartment & apartment)
{
		os << "В квартире № "<< apartment.getNumberAp() << " площадью "<< apartment.getArea()<<" проживают: ";

		for (int i = 0; i < apartment.getres(); i++)
			os << apartment.getpersons(i) << ' ';
		return os;
}