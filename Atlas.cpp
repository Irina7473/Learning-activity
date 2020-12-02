#include "Atlas.h"

Atlas:: Atlas()
{
	reservoirs = new Reservoir * [count];
	for (int i = 0; i < count; i++)
		reservoirs[i] = nullptr;
}

Atlas:: Atlas(const Atlas& atlas)
{
	count = atlas.count;
	rec = atlas.rec;
	reservoirs = new Reservoir * [count];
	for (int i = 0; i < rec; i++)
		reservoirs[i] = new Reservoir(*atlas.reservoirs[i]);
}

Atlas:: ~ Atlas()  
{
	for (int i = 0; i < rec; i++)
		delete reservoirs[i];
	delete[] reservoirs;
}

void Atlas::resize(int newsize)
{
	Reservoir** temp = new Reservoir * [newsize];
	for (int i = 0; i < count; i++)
		temp[i] = reservoirs[i];

	delete[] reservoirs;
	count = newsize;
	reservoirs = temp;
}

Atlas& Atlas:: operator=(const Atlas& other)
{
	if (this != &other) 
	{
		this->~Atlas();
		rec = other.rec;
		reservoirs = new Reservoir * [rec];
		for (int i = 0; i < rec; i++)
			reservoirs[i] = new Reservoir(*other.reservoirs[i]);
	}
	return *this; 
}

void Atlas::addreservoir(const Reservoir& RES)
{
	if (rec == count) resize(count*2);
	Reservoir* newres = new Reservoir(RES);
	reservoirs[rec] = newres;
	rec++;
}

void Atlas::delreservoir(std:: string name)
{
	int f = findreservoir(name);
	if (f != 1000)
	{
		reservoirs[f] = reservoirs[rec - 1];
		reservoirs[rec - 1] = nullptr;
		rec--;
	}
	else std::cout << "Водоем " << name << " не найден\n";
}

int Atlas::findreservoir(std:: string name)
{
	for (int i = 0; i < rec; i++)
	{
		Reservoir* RES = reservoirs[i];
		if (RES->getName() == name)
			return i;
	}
	return 1000;
}

Atlas Atlas::findtype(std::string tres)
{
	Atlas Tres;
	for (int i = 0; i < rec; i++)
	{
		Reservoir* RES = reservoirs[i];
		if (RES->gettype() == tres)
			Tres.addreservoir(*RES);
	}
	return Tres;
	
}

void Atlas::comparevolume(std::string tres)
{
	Atlas Tres(findtype(tres));
	int max = Tres.reservoirs[0]->Volume();
	int imaxV = 0;
	int min = Tres.reservoirs[0]->Volume();
	int iminV = 0;

	for (int i = 0; i < Tres.getrec(); i++)
	{
		int V = Tres.reservoirs[i]->Volume();
		if (max < V)
		{
			max = V;
			imaxV = i;
		}
		if (min > V)
		{
			min = V;
			iminV = i;
		}
	}
	std::cout << "Водоем типа " << tres << " наибольшего объема : " << Tres.reservoirs[imaxV]->getName() << " - " << max << '\n';
	std::cout << "Водоем типа " << tres << " наименьшего объема : " << Tres.reservoirs[iminV]->getName() << " - " << min << '\n';
	
}

void Atlas::comparearea(std::string tres)
{
	Atlas Tres(findtype(tres));
	int max = Tres.reservoirs[0]->Area();
	int imaxV = 0;
	int min = Tres.reservoirs[0]->Area();
	int iminV = 0;

	for (int i = 0; i < Tres.getrec(); i++)
	{
		int V = Tres.reservoirs[i]->Area();
		if (max < V)
		{
			max = V;
			imaxV = i;
		}
		if (min > V)
		{
			min = V;
			iminV = i;
		}
	}
	std::cout << "Водоем типа " << tres << " наибольшей площади : " << Tres.reservoirs[imaxV]->getName() << " - " << max << '\n';
	std::cout << "Водоем типа " << tres << " наименьшей площади : " << Tres.reservoirs[iminV]->getName() << " - " << min << '\n';
	
}

std:: ostream& operator<< (std:: ostream& os, const Atlas& atlas)
{
	os << "Водоемы :\n";
	for (int i = 0; i < atlas.getrec() ; i++)
		os << atlas.getreservoirs(i);
	return os;
}
