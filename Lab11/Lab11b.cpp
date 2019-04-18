#include <iostream>
#include<string>
#include<complex>
#include "LList.h"
#include "LListNode.h"
#include "Buntownik.h"
using namespace std;

int main()
{
	bool wersja_alternatywna = false;
	const int size = 8;
	int wiek[size] = { 32, 42, 45, 18, 41, 81, 15, 54 };
	int wiek_sorted[size] = { 15, 18, 32, 41, 42, 45, 54, 81 };
	string file_liczby;
	string file_buntownicy;

	/*cout << " ********************** Etap 0 (0 pkt) ********************** " << endl;
	{
		LList intList1;
		cout << intList1;

		for (int i = 0; i < size; )
		{
			intList1.insertBegin(wiek[i++]);
		}
		cout << intList1;
		cout << endl;
	}
	cout << " ********************** Etap 1 (2,5 pkt) ********************** " << endl;
	{
		LList intList2;
		cout << intList2;

		for (int i = 0; i < size; )
		{
			intList2.insertEnd(wiek[i++]);;
		}
		cout << intList2;
		cout << endl;

		if (wersja_alternatywna)
		{
			LList intList3;
			cout << intList3;

			for (int i = 0; i < size; i++)
			{
				intList3.insertEnd(wiek_sorted[i]);
			}
			cout << intList3;
			cout << endl << endl;
		}
		else
		{
			LList intList3;
			cout << intList3;

			for (int i = 0; i < size; i++)
			{
				intList3.insertSorted(wiek[i]);
			}
			cout << intList3;
			cout << endl << endl;
		}
	}*/
	cout << " ********************** Etap 2 (2 pkt) ********************** " << endl;
	{
		if (wersja_alternatywna)
		{
			LList<int> list1;
			list1.insertBegin(81); list1.insertBegin(45); list1.insertBegin(32); list1.insertBegin(21);
			cout << list1;

			LList<string> list2;
			list2.insertBegin("pa"); list2.insertBegin("kota"); list2.insertBegin("Ma"); list2.insertBegin("Ala");
			cout << list2;

			LList<double> list3;
			list3.insertBegin(3.333); list3.insertBegin(2.5); list3.insertBegin(0.7); list3.insertBegin(-3.21);
			cout << list3;
		}
		else
		{
			LList<int> list1;
			list1.insertSorted(32); list1.insertSorted(45); list1.insertSorted(21); list1.insertSorted(81);
			cout << list1;

			LList<string> list2;
			list2.insertSorted("Ala"); list2.insertSorted("pa"); list2.insertSorted("kota"); list2.insertSorted("Ma");
			cout << list2;

			LList<double> list3;
			list3.insertSorted(2.5); list3.insertSorted(0.7); list3.insertSorted(-3.21); list3.insertSorted(3.333);
			cout << list3;
		}

	}
	cout << " ********************** Etap 3 (0 pkt) ********************** " << endl;
	{
		if (wersja_alternatywna)
		{
			LList<Buntownik> list4;
			list4.insertEnd(Buntownik("Jan", 1)); list4.insertSorted(Buntownik("Filip", 2)); list4.insertSorted(Buntownik("Zenon", 3)); list4.insertSorted(Buntownik("Tomasz", 4));
			cout << list4;
		}
		else
		{
			LList<Buntownik> list4;
			list4.insertSorted(Buntownik("Jan", 1)); list4.insertSorted(Buntownik("Tomasz", 4)); list4.insertSorted(Buntownik("Zenon", 3)); list4.insertSorted(Buntownik("Filip", 2));
			cout << list4;
		}
	}
	cout << " ********************** Etap 4 (1 pkt) ********************** " << endl;

	if (wersja_alternatywna)
	{
		file_liczby = "Liczby_sorted.txt";
		file_buntownicy = "Buntownicy_sorted.txt";
	}
	else
	{
		file_liczby = "Liczby.txt";
		file_buntownicy = "Buntownicy.txt";
	}

	LList<int> list5;
	list5.fromFile(file_liczby);
	cout << list5;

	LList<Buntownik> list6;
	list6.fromFile(file_buntownicy);
	cout << list6;
	system("pause");
	cout << " ********************** Etap 5 (1 pkt) ********************** " << endl;

	//list5.delete_evry_n(2);
	//cout << list5;

	//list6.delete_evry_n(7);
	//cout << list6;

	cout << " ********************** Etap 6 (1 pkt) ********************** " << endl;

	//list5.toFile("LiczbyPo.txt");
	//list6.toFile("BuntownicyPo.txt");
	//cout << endl;

	cout << " ********************** Etap 7 (0,5 pkt) ********************** " << endl;

	//LList<Buntownik> buntownicy;
	//buntownicy.fromFile(file_buntownicy);
	//buntownicy.delete_evry_n(7);
	//buntownicy.toFile(file_buntownicy);

	cout << endl;

	return 0;
}