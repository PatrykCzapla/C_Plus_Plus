#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "konto.h"
#include "bank.h"
  
//-------------------------------------------------------------
ostream& operator<<(ostream& out, const konto& k)
{
	out << endl << "INFO KONTA:" << endl;
	out << "nr konta: " << k.nr_konta;
	out << k.wlasciciel;
	out << "saldo: " << fixed << setprecision(2) << k.saldo << endl;

	if (!k.l)
		out << "Brak lokaty na koncie" << endl;
	else
		out << "INFO o lokacie" << endl << *k.l;

	return out;
}

//-----------------------------------------------------------

konto::konto(const dane& wlasciciel, unsigned int nr_konta):wlasciciel(wlasciciel),nr_konta(nr_konta)
{
	// zaimplementuj w ETAP 2
	l = nullptr;
	saldo = 0;

}

//-----------------------------------------------------------
konto::~konto() 
{ 
	// zaimplementuj w ETAP 2
	delete[] l;
}		

//-----------------------------------------------------------

bool konto::czy_wlasciciel_konta(const dane& os) const
{
	// zaimplementuj w ETAP 3
	if (os == wlasciciel)return true;
	return false;
}

//-----------------------------------------------------------

bool konto::czy_lokata() const
{
	// zaimplementuj w ETAP 3
	if (l == nullptr)return false;
	return true;
}

//-----------------------------------------------------------
/*
bool konto::wplata(double kwota)
{
	// zaimplementuj w ETAP 4a

	return true;
}
*/
//-----------------------------------------------------------
/*
bool konto::wyplata(double kwota)
{
	// zaimplementuj w ETAP 4b

	return true;
}
*/
//-----------------------------------------------------------
/*
bool konto::wez_lokate(double kwota)
{
	// zaimplementuj w ETAP 5

	return true;
}
*/
//-----------------------------------------------------------
/*
bool konto::kasuj_lokate(double kwota)
{
	// zaimplementuj w ETAP 6

	return true;
}
*/
//-----------------------------------------------------------


