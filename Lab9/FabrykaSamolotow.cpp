#include "FabrykaSamolotow.hpp"

int FabrykaSamolotow::ZwrocSrodki() const
{
	return srodkiDoProdukcji;
}

void FabrykaSamolotow::OdnowSrodki(int noweSrodki)
{
	srodkiDoProdukcji += noweSrodki;
}

Silnik * FabrykaSamolotow::Produkuj(const Silnik & wzorzec)
{
	if (wzorzec.kosztProdukcji > srodkiDoProdukcji)throw std::runtime_error("Niewystarczajace srodki do produkcji silnika");
	srodkiDoProdukcji -= wzorzec.kosztProdukcji;
	return wzorzec.Replikuj();
}
