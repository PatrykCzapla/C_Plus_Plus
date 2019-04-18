#include <iostream> 
using namespace std;
#include "Bron.h"

// klasa Bron

//Bron::Bron(string nazwa, string opis, int obrazenia) : Przedmiot(nazwa, opis), obrazenia(obrazenia) {}

// uzupelnij

Bron::Bron(string nazwa, string opis, int obrazenia) :Przedmiot(nazwa, opis), obrazenia(obrazenia)
{};
int Bron::atak_bronia() const
{
	return obrazenia;
}
void Bron::info(ostream& out) const
{
	out << nazwa << " (" << opis << ") "<<"obrazenia: "<<obrazenia;

}


