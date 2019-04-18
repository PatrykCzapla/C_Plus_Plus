#pragma once
#include <iostream>
using namespace std;
#include "klient.h"
#include "konto.h"
   
class klient;
class bank 
{
private:
	konto** konta;		// dynamiczna tablica  wskaŸników do kont bankowych
	int n;				// bie¿¹ca liczba kont w banku (rozmiar powy¿szej dynamicznej tablicy)

public:
	unsigned int nadaj_nr_konta;	// bank kontroluje nadawanie kolejnych numerów dla nowych kont
	static double oproc_lokaty;		// reklama banku: udziela lokat np na 10%

private:
	int znajdz_konto(unsigned int nr_konta) const;	// w ETAP 3 - znajdŸ konto o podanym numerze

public:
	bank() : konta(nullptr), n(0), nadaj_nr_konta(1500) {}
	~bank() 
	{
		for (int i = 0; i < n; i++) 	delete konta[i];
		delete konta;
	}

private:	// sprawy za³atwiamy tylko w banku
	bool nowe_konto(const klient& k);				// odkomentuj w ETAP 1
	bool kasuj_konto(const klient& k);			// odkomentuj w ETAP 1
	bool wplata_na_konto(const klient& k);		// odkomentuj w ETAP 1
	bool wyplata_z_konta(const klient& k);		// odkomentuj w ETAP 1
	
	bool wez_lokate(const klient& k);				// odkomentuj w ETAP 1
	bool kasuj_lokate(const klient& k);			// odkomentuj w ETAP 1

public:
	static double& zmiana_oproc_lokaty() { return oproc_lokaty; }
	//double& zmiana_oproc_pozyczki() { return oproc_pozyczki; }
			
	friend ostream& operator<<(ostream& out, const bank& b);
	friend class klient;
};