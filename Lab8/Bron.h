#pragma once
#include <iostream> 
#include <string>
using namespace std;
#include "Przedmiot.h"

class Bron : public Przedmiot
{
protected:
	int obrazenia;
public:
	Bron(string nazwa, string opis, int obrazenia);
	virtual int atak_bronia() const;
	void info(ostream&) const;
};

