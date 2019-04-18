#pragma once

#include "grading.h"

class moneta : public grading
{
	string nominal;
	double cena;
	int rok;
	double *przewidywana_wartosc;
	int ile_lat_przewidywan;

public:
	moneta(string nominal = "nieznany", int rok = 0, double cena = 0);
	moneta(string nominal, int rok, double cena, grading &gr);
	moneta(string nominal, int rok, double cena, int nota, firma centrum = firma::BRAK);
	moneta(const moneta& b);

	~moneta();

	moneta& operator = (const moneta& b);

	void oblicz_wartosc(int ile_lat = 0);
	void wypisz_przewidywana_wartosc();

	friend ostream& operator<<(ostream& out, const moneta& b);
};