#pragma once
#include "Header.h"

class Reservoir
{
	char* Name; //название
	int width; //ширина в метрах
	int length; //длина в метрах
	int depth; //максимальная глубина в метрах
	std::string type;
		
public:
	Reservoir() : Reservoir{ nullptr, " ", 0, 0, 0 } {}   //конструктор по умолчанию
	Reservoir(const char* name, std::string t, int wid, int len, int dep);   //конструктор
	Reservoir(const Reservoir& RES);  //конструктор копирования

	~Reservoir() { delete[] Name;}   //деструктор

	//доступ к полям водоема для чтения
	const char* getName() const { return Name; }
	std::string gettype() const { return type; }
	int getwidth() const { return width; }
	int getlength() const { return length; }
	int getdepth() const { return depth; }

	Reservoir& operator= (const Reservoir& other); //оператор присваивания

	int Volume(); //определение приблиз объема водоема(ширина*длина*максимальная глубина)
	int Area(); //определение приблиз площади водной поверхности водоема (ширина*длина)
};

std::ostream& operator<< (std::ostream& os, const Reservoir& RES); 