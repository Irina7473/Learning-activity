#include "Header.h"
#include "Reservoir.h"
#include "Atlas.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Reservoir" << endl;

	Reservoir A("Тургаяк","lake", 50, 50, 10);
	Reservoir B("Калды", "lake", 16, 16, 4);
	Reservoir C("Увильды", "lake", 48, 48, 12);
	
	Atlas Chel;
	Chel.addreservoir(A);
	Chel.addreservoir(B);
	Chel.addreservoir(C);
	Chel.addreservoir(Reservoir("Аргази", "basin", 66, 66, 66));
	Chel.addreservoir(Reservoir("Шершни", "basin", 46, 46, 46));
	cout << Chel << endl;

	string typeres="lake";
	cout << "Водоемы Chel типа "<<typeres<<" : " ;
	Atlas Typeres(Chel.findtype(typeres));
	for (int i = 0; i < Typeres.getrec(); i++)
		cout << Typeres.getreservoirs(i).getName()<<" ";
	cout << endl;

	Chel.comparevolume(typeres);
	Chel.comparearea(typeres);
	
	return 0;
}