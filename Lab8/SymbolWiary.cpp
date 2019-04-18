#include <iostream> 
using namespace std;
#include "SymbolWiary.h"

// klasa SymbolWiary

// SymbolWiary::SymbolWiary(string nazwa, string opis) : Przedmiot(nazwa, opis) {}

// uzupelnij


SymbolWiary::SymbolWiary(string nazwa, string opis):Przedmiot(nazwa,opis)
{

};

bool SymbolWiary::uzyj() const
{
	cout << "Symbol wiary rozswietla wszystko dookola - Bostwo slucha - Czas na modlitwe!"<<endl;
	return true;
}