#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Zaklecie
{
protected:
	string nazwa;
	int poziom_trudnosci;
public:
	Zaklecie(string nazwa, int poziom_trudnosci);
	virtual int wypowiedz_zaklecie() = 0;
	int jaki_poziom_trudnosci() const { return poziom_trudnosci; }
	void info(ostream&) const;
	friend ostream& operator<<(ostream&, const Zaklecie&);
};

class ZaklecieOfensywne : public Zaklecie
{
protected:
	int obrazenia;
public:
	// uzupelnij
	ZaklecieOfensywne(string nazwa, int poziom_trudnosci, int obrazenia);
	int wypowiedz_zaklecie();

};

class ZaklecieDefensywne : public Zaklecie
{
protected:
	int odzyskane_punkty_zycia;
public:
	// uzupelnij
	ZaklecieDefensywne(string nazwa, int poziom_trudnosci, int pktzycia);
	int wypowiedz_zaklecie();

};

