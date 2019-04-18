#include <iostream>
using namespace std;
#include "klient.h"
#include "bank.h"

//-----------------------------------------------------------------------------------------------------
void main()
{
	
	//-----------------------------------------------------------------------------------------------------
	klient* kolejka[] = {	
					new klient("Jolanta", "Kowalska", poco::NOWE_KONTO),					// nr 1500	//0
					new klient("Robert",  "Popecki",  poco::NOWE_KONTO),					// nr 1501	//1
					new klient("Adam",    "Abacki",   poco::KASUJ_KONTO, 1501),							//2
							
					new klient("Robert",  "Popecki",  poco::KASUJ_KONTO, 1600),							//3
					new klient("Jolanta", "Kowalska", poco::KASUJ_KONTO, 1500),							//4	
					new klient("Robert",  "Popecki",  poco::KASUJ_KONTO, 1501),							//5	
					new klient("Robert",  "Popecki",  poco::KASUJ_KONTO, 1600),							//6

					new klient("Ada",	  "Tonieta",  poco::NOWE_KONTO),					// nr 1502	//7
					new klient("Adam",	  "Tonieten", poco::NOWE_KONTO),					// nr 1503	//8

					new klient("Ada",	  "Tonieta",  poco::WPLATA_NA_KONTO, 1502, -600),				//9		
					new klient("Ada",	  "Tonieta",  poco::WPLATA_NA_KONTO, 1502, 500),				//10
					new klient("Ada",	  "Tonieta",  poco::WPLATA_NA_KONTO, 1503, 200),				//11

					new klient("Adam",	  "Tonieten", poco::WPLATA_NA_KONTO, 1502, 250),				//12
					new klient("Adam",	  "Tonieten", poco::WPLATA_NA_KONTO, 1503, 450),				//13

					new klient("Adam",	  "Tonieten", poco::WYPLATA_Z_KONTA, 1502, 250),				//14
					new klient("Adam",	  "Tonieten", poco::WYPLATA_Z_KONTA, 1503, 250),				//15

					new klient("Robert",  "Tamten",   poco::NOWE_KONTO),					// nr 1504	//16

					new klient("Adam",	  "Tonieten", poco::WEZ_LOKATE, 1502, 1000),					//17
					new klient("Adam",	  "Tonieten", poco::WEZ_LOKATE, 1503, 1000),					//18
					new klient("Adam",	  "Tonieten", poco::KASUJ_KONTO,  1503),						//19
					new klient("Adam",	  "Tonieten", poco::KASUJ_LOKATE, 1503),					//20
					new klient("Adam",	  "Tonieten", poco::WEZ_LOKATE, 1503, 500),						//21
					new klient("Adam",	  "Tonieten", poco::KASUJ_LOKATE, 1503),					//22
					new klient("Adam",	  "Tonieten", poco::WEZ_LOKATE, 1503, 100),						//23
					new klient("Adam",	  "Tonieten", poco::KASUJ_LOKATE, 1503),						//24

					new klient("Robert",  "Tamten",   poco::WPLATA_NA_KONTO, 1504, 2000),				//25
					new klient("Robert",  "Tamten",   poco::WEZ_LOKATE, 1504, 2000),					//26
					new klient("Robert",  "Tamten",   poco::WEZ_LOKATE, 1504, 2000),					//27
					new klient("Robert",  "Tamten",   poco::KASUJ_LOKATE, 1504),						//28

					new klient("Ada",	  "Tonieta",  poco::WYPLATA_Z_KONTA, 1502, 500),				//29
					
				};
	int N = sizeof(kolejka) / sizeof(klient*);
	   
	bank B;

	// W KOLEJNYCH ETAPACH USTAW ODPOWIEDNI¥ WARTOŒæ N
	// np dla ETAP 2 ustaw N=2

	for (int i = 0; i < N; i++)
	{
		cout << endl << "klient nr: " <<i<< *kolejka[i] << endl;

		if (i % 10 == 0) bank::zmiana_oproc_lokaty() += 5;

		 
		// odkomentuj w ETAP 1

		if (kolejka[i]->ide_do_banku(B))
			cout << "klient zalatwiona" << endl;
		else
			cout << "klient NIE zalatwiona" << endl;
		
		
		cout <<endl<< "BANK"<<i<<":"<<endl<<B;
		cin.get();
	}

	for (int i = 0; i < N; i++) delete kolejka[i];
	
	system("pause");
}
