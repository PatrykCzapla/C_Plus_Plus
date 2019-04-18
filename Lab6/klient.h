#pragma once

#include <iostream>
using namespace std;
#include "dane.h"
#include "bank.h"
   

enum  poco { NOWE_KONTO, KASUJ_KONTO, WPLATA_NA_KONTO, WYPLATA_Z_KONTA, WEZ_LOKATE, KASUJ_LOKATE };
class bank;

class klient 
{
	dane osoba;
		
	enum  poco cel;
	unsigned int nr_konta;
	double kwota;
	
public:
	
	klient(const char* imie, const char* nazwisko, enum  poco cel = poco::NOWE_KONTO, unsigned int nr_konta = 0, double kwota=0);
	
	bool ide_do_banku(bank& b);	// odkomentuj w ETAP 1

	friend ostream& operator<<(ostream& out, const klient& k);	
	friend class bank;
	
};