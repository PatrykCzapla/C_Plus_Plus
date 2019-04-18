#pragma once

#include "Silnik.hpp"
#include "Samolot.hpp"

class FabrykaSamolotow
{
private:
	int srodkiDoProdukcji = 0;

public:
	int ZwrocSrodki() const;
	void OdnowSrodki(int noweSrodki);

	Silnik * Produkuj(const Silnik& wzorzec);
	//Samolot * Produkuj(const Samolot& wzorzec);
};