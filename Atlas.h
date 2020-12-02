#pragma once
#include "Header.h"
#include "Reservoir.h"

class Atlas
{
	Reservoir** reservoirs;
	int count = 10;  //количество строк в атласе
	int rec = 0;  //количество записанных строк в атласе

public:
	Atlas();   //конструктор
	Atlas(const Atlas& atlas);  //конструктор копирования

	~ Atlas();   //деструктор

	void resize(int newsize);  //добавление строк

	//доступ к полям атласа для чтения
	const Reservoir& getreservoirs(int index) const { return *reservoirs[index];}
	int getrec() const { return rec; }

	Atlas& operator=(const Atlas& other);  //оператор присваивания

	void addreservoir(const Reservoir& RES);  //добавление строки с водоемом

	void delreservoir(std::string name);  //удаление строки с водоемом

	int findreservoir(std::string name);  //поиск строки с водоемом по названию

	Atlas findtype(std::string tres);  //поиск строки с водоемом по его типу

	void comparevolume(std::string tres);  //нахождение max и min объема водоемов одного типа

	void comparearea(std::string tres);  //нахождение max и min площади водной поверхности водоемов одного типа
	
};

std::ostream& operator<< (std::ostream& os, const Atlas& atlas);