#include "Reservoir.h"

Reservoir::Reservoir(const char* name, std::string t, int wid, int len, int dep):
	Name{ new char[std::strlen(name) + 1] }, type{ t }, width{ wid }, length{ len }, depth{ dep }
{	strcpy_s(this->Name, std:: strlen(name) + 1, name); }

Reservoir::Reservoir(const Reservoir& RES):
	Name{ new char[strlen(RES.Name) + 1] }, type{RES.type}, width{ RES.width }, length{ RES.length }, depth{ RES.depth }
{strcpy_s (Name, std:: strlen(RES.Name) + 1, RES.Name); }

Reservoir& Reservoir::operator=(const Reservoir& other)
{
	if (this != &other)
	{
		delete[]Name;
		Name = new char[strlen(other.Name) + 1];
		strcpy_s(Name, strlen(other.Name) + 1, other.Name);
		type = other.type;
		width = other.width;
		length = other.length;
		depth = other.depth;
	}
	return *this;  
}

int Reservoir::Volume()
{
	int V = width * length * depth;
	return V;
}

int Reservoir::Area()
{
	int A = width * length;
	return A;
}

std::ostream& operator<< (std::ostream& os, const Reservoir& RES)
{
	os << RES.getName() <<" : тип "<<RES.gettype() << " ширина " << RES.getwidth() << " длина " << RES.getlength() << " глубина " << RES.getdepth();
	return os<<'\n';
}
