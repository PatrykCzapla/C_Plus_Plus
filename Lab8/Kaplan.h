#pragma once
#include <iostream> 
#include <string>
using namespace std;
#include "Przedmiot.h"
#include "Bron.h"
#include "SymbolWiary.h"
#include "Zaklecie.h"

class Kaplan
{
	static const int wielkosc_ekwipunku = 4;
	static const int ilosc_zaklec = 4;
	string imie;
	int punktyZycia = 30;
	int zrecznosc = 5;
	int sila = 5;
	int madrosc = 5;

	int sila_ataku;
	int poziom_ochrony;
	int ile_zaklec = 0;

	Bron* bron_w_rece;
	SymbolWiary* symbol_w_rece;

	Zaklecie* znane_zaklecia[ilosc_zaklec];

	Przedmiot* ekwipunek[wielkosc_ekwipunku];
	void modlitwa();
public:
	
	Kaplan(string imie);
	virtual ~Kaplan();
	void przygotuj_postac();
	int wykonaj_atak(int poziom_ochrony_przeciwnika);
	void przyjmij_atak(int obrazenia);

	int znajdz_zaklecie_ofensywne() const;
	int znajdz_zaklecie_defensywne() const;

	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	friend ostream& operator<<(ostream&, const Kaplan&);
};

