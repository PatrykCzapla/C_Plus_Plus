#pragma once
#include <iostream>
#include <iterator>
#include <set>
#include <list>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
#include "druzyna.h"

class Grupa_pilkarska
{
	set<Druzyna> druzyny;
	string nazwa;
public:
	Grupa_pilkarska(string _nazwa = "") : nazwa(_nazwa) {};
	string nazwaGrupy() const { return nazwa; };
	
	// Etap 2
	// 0.5 pkt
	int rozmiar() const;
	bool czyPusta() const;
	void dodaj(Druzyna d);
	void usun(Druzyna d);
	// 0.5 pkt
	bool czy_jest_czescia(Grupa_pilkarska& gr) const;

	// gotowa
	friend ostream& operator<<(ostream& out, const Grupa_pilkarska& g);
	
	//// Etap 3
	//// 0.5 pkt
	//friend Grupa_pilkarska operator+(const Grupa_pilkarska& g1, const Grupa_pilkarska& g2);
	//// 0.5 pkt
	//friend Grupa_pilkarska operator-(const Grupa_pilkarska& g1, const Grupa_pilkarska& g2);

	//// Etap 4
	//// 0.5 pkt
	//friend void uaktualnij_grupe(Grupa_pilkarska& g, Druzyna& d);
	//// 1.0 pkt
	//friend list<Druzyna> najlepsze(Grupa_pilkarska& g, int _punkty);
};