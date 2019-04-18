#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Wynik { PRZEGRANA, REMIS, ZWYCIESTWO = 3 };
enum Rodzaj_meczu { TOWARZYSKI = 1, ELIMINACJE = 3, MISTRZOSTWA};

class Druzyna 
{
	string reprezentacja_kraju; //nazwa kraju
	int ilosc_punktow; //pocz¹tkowe punkty
	int pozycja_w_rankingu;
	vector<pair<Druzyna, Rodzaj_meczu>> rozegrane_mecze;
	vector<pair<int, int>> wyniki_meczow; //<bramki_zdobyte, bramki_stracone>
public:
	// Etap 1
	// 0.5 pkt
	Druzyna() : reprezentacja_kraju(""), ilosc_punktow(0), pozycja_w_rankingu(0) {}
	Druzyna(string kraj, int punkty, int pozycja) :reprezentacja_kraju(kraj), ilosc_punktow(punkty), pozycja_w_rankingu(pozycja) {}
	Druzyna(string kraj, int punkty, int pozycja, vector<pair<Druzyna, Rodzaj_meczu>> rozegrane_mecze, vector<pair<int, int>> wyniki_meczow) :reprezentacja_kraju(kraj), ilosc_punktow(punkty), pozycja_w_rankingu(pozycja), rozegrane_mecze(rozegrane_mecze), wyniki_meczow(wyniki_meczow) {}

	// 0.5 pkt
	int zwyciestwa() const; //iloœæ zwyciêstw
	int remisy() const; //iloœæ remisów
	int przegrane() const; //iloœæ przegranych
	// 1.0 pkt
	pair<int, int> bramki() const;

	// 1.5 pkt
	// Punkty = poczatkowa_ilosc_punktow + (int)srednia_z(Punkty_za_mecz)
	// Punkty_za_mecz = W * R * S
	// W - Waga wyniku meczu: przegrana = 0, remis = 1, zwyciêstwo = 3
	// R - Waga rodzaju meczu: towarzyski = 1, eliminacje = 3, mistrzostwa = 4
	// S - Si³a przeciwnika =  21 - pozycja_przeciwnika_w_rankingu
	int aktualna_liczna_punktow() const;
	
	//gotowa
	friend ostream& operator<<(ostream& out, const Druzyna& d);
	friend bool operator<(const Druzyna& a, const Druzyna& b);
	friend bool operator>(const Druzyna& a, const Druzyna& b);
	friend bool operator==(const Druzyna& a, const Druzyna& b);
	// Etap 4
	// 0.5 pkt
	//void rozegrano_kolejny_mecz(pair<Druzyna, Rodzaj_meczu>, pair<int, int>);
};