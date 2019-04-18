#include <iostream> 
using namespace std;
#include "Przedmiot.h"

Przedmiot::Przedmiot(string nazwa, string opis) : nazwa(nazwa), opis(opis) {}

void Przedmiot::info(ostream& out) const
{
	out << nazwa << " (" << opis << ") ";
}

ostream& operator<<(ostream& out, const Przedmiot& p)
{
	p.info(out);
	out << endl;
	return out;
}
