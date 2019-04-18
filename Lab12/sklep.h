#pragma once
#include <iostream>
#include <vector>
#include <list>
#include "alkohol.h"
using namespace std;

class Zapasy
{
	list<Alkohol*> zapasy;
public:
	Zapasy() {};

	//Etap 2
	void dodaj_do_zapasow(Alkohol*);
	friend ostream& operator<<(ostream& out, const Zapasy& s);
	double wartosc_zapasow();
	Alkohol* sprzedaj();

	//Etap 3
	void wczytaj(const char*);

	//Etap 4
	//list<Alkohol*> usun_duplikaty();

	//Etap 5
	//list<Alkohol*> sprzedaj(double cena);
};

