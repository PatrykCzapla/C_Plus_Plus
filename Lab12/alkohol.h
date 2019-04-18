#pragma once
#include <iostream>
using namespace std;

//Etap 1

enum rodzaje_win { SLODKIE, POLSLODKIE, POLWYTRAWNE, WYTRAWNE };
enum rodzaje_piw { BIALE, JASNE, CIEMNE, NIEFILTROWANE, NIEPASTERYZOWANE };
enum rodzaj_opakowania { PUSZKA, BUTELKA };

class Alkohol
{
protected:
	double cena;
	double zawartosc_alkoholu;
	string nazwa;

public:
	Alkohol() {};
	Alkohol(string _nazwa, double _cena, double _zawartosc_al);
	string pobierz_nazwe();
	double pobierz_cene();
	double pobierz_zawartosc_alkoholu() const;
	virtual void wyprowadz_na_ekran(ostream& out) const =0;
	friend ostream& operator<<(ostream& out, const Alkohol& w);
};

class Wino : public Alkohol
{
	int rocznik;
	rodzaje_win rodzaj;

public:
	Wino(string _nazwa, double _cena, int _rok, rodzaje_win _rodzaj);
	int pobierz_rocznik();
	string pobierz_rodzaj() const;
	virtual void wyprowadz_na_ekran(ostream& out) const;

	friend bool operator==(const Wino& w1, const Wino& w2);
};

class Piwo : public Alkohol
{
	rodzaj_opakowania opakowanie;
	rodzaje_piw rodzaj;

public:
	Piwo(string _nazwa, double _cena, double _zawartosc_al, rodzaje_piw _rodzaj, rodzaj_opakowania _opakowanie);
	string pobierz_opakowanie() const;
	string pobierz_rodzaj() const;
	virtual void wyprowadz_na_ekran(ostream& out) const;

	friend bool operator==(const Piwo& w1, const Piwo& w2);
};