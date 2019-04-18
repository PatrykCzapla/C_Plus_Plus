#include <string>
#include "alkohol.h"
using namespace std;

Alkohol::Alkohol(string _nazwa, double _cena, double _zawartosc_al):nazwa(_nazwa),cena(_cena),zawartosc_alkoholu(_zawartosc_al)
{
}

string Alkohol::pobierz_nazwe()
{
	return nazwa;
}

double Alkohol::pobierz_cene()
{
	return cena;
}

double Alkohol::pobierz_zawartosc_alkoholu() const
{
	return zawartosc_alkoholu;
}

void Alkohol::wyprowadz_na_ekran(ostream & out) const
{
}

ostream & operator<<(ostream & out, const Alkohol & w)
{
	w.wyprowadz_na_ekran(out);
	return out;
}

bool operator==(const Wino & w1, const Wino & w2)
{
	if (w1.rodzaj == w2.rodzaj&&w1.nazwa == w2.nazwa)return true;
	else return false;
}

bool operator==(const Piwo & w1, const Piwo & w2)
{
	if (w1.rodzaj == w2.rodzaj&&w1.nazwa == w2.nazwa)return true;
	else return false;
}

Wino::Wino(string _nazwa, double _cena, int _rok, rodzaje_win _rodzaj):Alkohol(_nazwa,_cena,14)
{
	rocznik = _rok;
	rodzaj = _rodzaj;
}

int Wino::pobierz_rocznik()
{
	int w;
	cin >> w;
	return w;
}

string Wino::pobierz_rodzaj() const
{
	string w;
	switch (rodzaj)
	{
	case SLODKIE:
	{
		w = "slodkie";
		break;
	}
	case POLSLODKIE:
	{
		w = "polslodkie";
		break;
	}
	case POLWYTRAWNE:
	{
		w = "polwytrawne";
		break;
	}
	case WYTRAWNE:
	{
		w = "wytrawne";
		break;
	}
	}
	return w;
}

void Wino::wyprowadz_na_ekran(ostream & out) const
{
	switch (rodzaj)
	{
	case SLODKIE:
	{
		out << nazwa << ", " << "slodkie" << ", rocznik " << rocznik << ", cena " << cena << " zl" << endl;
		break;
	}
	case POLSLODKIE:
	{
		out << nazwa << ", " << "polslodkie" << ", rocznik " << rocznik << ", cena " << cena << " zl" << endl;
		break;
	}
	case POLWYTRAWNE:
	{
		out << nazwa << ", " << "polwytrawne" << ", rocznik " << rocznik << ", cena " << cena << " zl" << endl;
		break;
	}
	case WYTRAWNE:
	{
		out << nazwa << ", " << "wytrawne" << ", rocznik " << rocznik << ", cena " << cena << " zl" << endl;
		break;
	}
	}
}

Piwo::Piwo(string _nazwa, double _cena, double _zawartosc_al, rodzaje_piw _rodzaj, rodzaj_opakowania _opakowanie):Alkohol(_nazwa,_cena,_zawartosc_al)
{
	rodzaj = _rodzaj;
	opakowanie = _opakowanie;
}

string Piwo::pobierz_opakowanie() const
{
	string w;
	switch (opakowanie)
	{
	case PUSZKA:
	{
		w = "w puszce";
		break;
	}
	case BUTELKA:
	{
		w = "butelkowe";
		break;
	}
	}
	return w;
}

string Piwo::pobierz_rodzaj() const
{
	
	string w;
	switch (rodzaj)
	{
	case BIALE:
	{
		w = "biale";
		break;
	}
	case JASNE:
	{
		w = "jasne";
		break;
	}
	case CIEMNE:
	{
		w = "ciemne";
		break;
	}
	case NIEFILTROWANE:
	{
		w = "niefiltrowane";
		break;
	}
	case NIEPASTERYZOWANE:
	{
		w = "niepasteryzowane";
		break;
	}
	}
	return w;
}

void Piwo::wyprowadz_na_ekran(ostream & out) const
{
	switch (rodzaj)
	{
	case BIALE:
	{
		out << nazwa << ", " << "biale" << ", " << zawartosc_alkoholu << "%, " << pobierz_opakowanie() << ", cena " << cena << " zl" << endl;
		break;
	}
	case JASNE:
	{
		out << nazwa << ", " << "jasne" << ", " << zawartosc_alkoholu << "%, " << pobierz_opakowanie() << ", cena " << cena << " zl" << endl;
		break;
	}
	case CIEMNE:
	{
		out << nazwa << ", " << "ciemne" << ", " << zawartosc_alkoholu << "%, " << pobierz_opakowanie() << ", cena " << cena << " zl" << endl;
		break;
	}
	case NIEFILTROWANE:
	{
		out << nazwa << ", " << "niefiltrowane" << ", " << zawartosc_alkoholu << "%, " << pobierz_opakowanie() << ", cena " << cena << " zl" << endl;
		break;
	}
	case NIEPASTERYZOWANE:
	{
		out << nazwa << ", " << "niepasteryzowane" << ", " << zawartosc_alkoholu << "%, " << pobierz_opakowanie() << ", cena " << cena << " zl" << endl;
	}
	}
}
