#pragma once
#include <iostream>
using namespace std;
#include "dane.h"
#include "lokata.h"

class dane;

class konto
{
private:
	dane wlasciciel;
	double saldo;		// rachunek bie¿¹cy nieoprocentowany
	lokata* l;			// na koncie mo¿na za³o¿yæ tylko jedn¹ lokatê
		
public:
	const unsigned int nr_konta;	// numer konta nie jest tajny (pole sta³e po nadaniu numeru)

public:
	konto(const dane& wlasciciel, unsigned int nr_konta);	// ETAP 2
	~konto();												// ETAP 2

	bool czy_wlasciciel_konta(const dane& os) const;		// ETAP 3
	bool czy_lokata() const;								// ETAP 3
	
	//bool wplata(double kwota);							// ETAP 4a
	//bool wyplata(double kwota);							// ETAP 4b
	//bool wez_lokate(double kwota);						// ETAP 5
	//bool kasuj_lokate(double kwota);						// ETAP 6
			
	friend ostream& operator<<(ostream& out, const konto& k);
	friend class bank;
};
