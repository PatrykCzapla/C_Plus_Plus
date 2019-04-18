#include <iomanip>
#include <fstream>
#include <string>
#include <iterator>
#include "sklep.h"
using namespace std;

void Zapasy::dodaj_do_zapasow(Alkohol *w)
{
	zapasy.push_back(w);
}

double Zapasy::wartosc_zapasow()
{
	double suma = 0;
	list<Alkohol*>::const_iterator it = zapasy.begin();
	for (; it != zapasy.end(); ++it)
	{
		suma += (*it)->pobierz_cene();
	}
	return suma;
}

Alkohol * Zapasy::sprzedaj()
{
	int w = (rand() % zapasy.size());
	list<Alkohol*>::const_iterator it = zapasy.begin();
	advance(it, w);

	Alkohol* do_sprzed = (*it);
	zapasy.erase(it);
	return do_sprzed;	
}

void Zapasy::wczytaj(const char *s)
{
	fstream plik;
	char nazwa[100];
	double cena;
	int rok;
	int rodzaj;
	plik.open("wino.bin", ios::in | ios::binary);
	if (!plik)
	{
		cout << "Nie ma takiego pliku" << endl;
		return;
	}
	while(!plik.eof())
	{
		plik.read((char*)nazwa, 100 * sizeof(char));
		if (!plik)
		{
			cout << "Nie udalo sie wczytac." << endl;
			return;
		}
		plik.read((char*)&cena, sizeof(double));
		if (!plik)
		{
			cout << "Nie udalo sie wczytac." << endl;
			return;
		}
		plik.read((char*)&rok, sizeof(int));
		if (!plik)
		{
			cout << "Nie udalo sie wczytac." << endl;
			return;
		}
		plik.read((char*)&rodzaj, sizeof(int));
		if (!plik)
		{
			cout << "Nie udalo sie wczytac." << endl;
			return;
		}
		rodzaje_win w = rodzaje_win(rodzaj);
		Wino s(nazwa, cena, rok, w);
		dodaj_do_zapasow(&s);
	}
	plik.close();
}

ostream & operator<<(ostream & out, const Zapasy & s)
{
	if (s.zapasy.empty()) 
	{
		out << "Brak towaru." << endl;
		return out;
	}
	else
	{
		int i = 1;
		list<Alkohol*>::const_iterator it = s.zapasy.begin();
		for (; it != s.zapasy.end(); ++it,i++)
		{
			out <<i<<". "<< *(*it) << endl;
		}
		return out;
	}
}
