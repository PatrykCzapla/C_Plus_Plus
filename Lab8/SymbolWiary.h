#pragma once
#include <iostream> 
#include <string>
using namespace std;
#include "Przedmiot.h"

class SymbolWiary : public Przedmiot
{

public:
	SymbolWiary(string nazwa, string opis);
	bool uzyj() const;
};