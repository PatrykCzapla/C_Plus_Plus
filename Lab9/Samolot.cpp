#include "Samolot.hpp"

#include "FabrykaSamolotow.hpp"

#pragma region Samolot

std::ostream & operator<<(std::ostream & out, const Samolot & samolot)
{
	samolot.ZwrocInformacje(out);
	return out;
}

void Samolot::ZwrocInformacje(std::ostream & out) const
{
	out << "Cena: " << ZwrocCene() << std::endl;
	out << *silnik;
	out << "Liczba siedzien: " << liczbaSiedzen << std::endl;
	out << "Waga: " << wagaBezSilnika + silnik->ZwrocWage() << std::endl;
	out << "Oplywowosc: " << oplywowosc << std::endl;
	out << "Przyspieszenie: " << ZwrocPrzyspieszenie() << std::endl;
	out << "Predkosc maksymalna: " << ZwrocPredkoscMaksymalna() << std::endl;
}

Silnik & Samolot::ZwrocSilnik() const
{
	return *silnik;
}

Samolot::Samolot(Silnik * silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc):silnik(silnik),liczbaSiedzen(liczbaSiedzen),kosztProdukcjiBezSilnika(kosztProdukcjiBezSilnika),wagaBezSilnika(wagaBezSilnika),oplywowosc(oplywowosc)
{
}

Samolot::~Samolot()
{
	delete silnik;
}

int Samolot::ZwrocLiczbeSiedzen() const
{
	return liczbaSiedzen;
}

int Samolot::ZwrocCene() const
{
	return static_cast<int>(ZwrocKosztProdukcji() * 1.4f);
}

int Samolot::ZwrocKosztProdukcji() const
{
	return kosztProdukcjiBezSilnika + silnik->ZwrocKosztProdukcji();
}

float Samolot::ZwrocWage() const
{
	return wagaBezSilnika + silnik->ZwrocWage();
}

float Samolot::ZwrocOplywowosc() const
{
	return oplywowosc;
}

float Samolot::ZwrocWspolczynnikMocy() const
{
	return 1.0f;
}

float Samolot::ZwrocPrzyspieszenie() const
{
	return silnik->ObliczPrzyspieszenie(ZwrocWage(), ZwrocWspolczynnikMocy());
}

float Samolot::ZwrocPredkoscMaksymalna() const
{
	return silnik->ObliczPredkoscMaksymalna(ZwrocOplywowosc(), ZwrocWspolczynnikMocy());
}

// Implementacja konstruktora i destruktora

#pragma endregion
#pragma region Samolot Pasazerski

// Implementacja samolotu pasazerskiego

#pragma endregion
#pragma region Samolot Transportowy

// Implementacja samolotu transportowego

#pragma endregion
#pragma region Samolot Wyczynowy

// Implementacja samolotu wyczynowego

#pragma endregion

void SamolotPasazerski::ZwrocInformacje(std::ostream & out) const
{
	out << "Samolot pasazerski:" << std::endl;
	Samolot::ZwrocInformacje(out);
	if (ogrzewanie == 0)out << "Podgrzewanie siedzien (wylaczone)" << std::endl;
	else out << "Podgrzewanie siedzien (wlaczone)" << std::endl;
}

SamolotPasazerski::SamolotPasazerski(Silnik * silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc):Samolot(silnik,liczbaSiedzen,kosztProdukcjiBezSilnika,wagaBezSilnika,oplywowosc)
{
}

void SamolotPasazerski::UstawPodgrzewanieSiedzen(bool w)
{
	ogrzewanie = w;
}

float SamolotPasazerski::ZwrocWspolczynnikMocy() const
{
	if (ogrzewanie == 1)return 0.9;
	else return 1;
}

SamolotPasazerski * SamolotPasazerski::Replikuj(FabrykaSamolotow & fabryka) const
{

}

void SamolotTransportowy::ZwrocInformacje(std::ostream & out) const
{
	out << "Samolot transportowy:" << std::endl;
	Samolot::ZwrocInformacje(out);
	out << "Pojemna przestrzen towarowa(ilosc towaru: " << towar << ")" << std::endl;
}

SamolotTransportowy::SamolotTransportowy(Silnik * silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc):Samolot(silnik, liczbaSiedzen, kosztProdukcjiBezSilnika, wagaBezSilnika, oplywowosc)
{
}

void SamolotTransportowy::UstawIloscTowaru(float w)
{
	towar = w;
}

float SamolotTransportowy::ZwrocWage() const
{
	return Samolot::ZwrocWage() + towar;
}

void SamolotWyczynowy::ZwrocInformacje(std::ostream & out) const
{
	out << "Samolot wyczynowy:" << std::endl;
	Samolot::ZwrocInformacje(out);
	out << "Dodatkowe klapy:";
	if (klapy == 1)out << "(otwarte)" << std::endl;
	else out << "(zamkniete)" << std::endl;
}

SamolotWyczynowy::SamolotWyczynowy(Silnik * silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc) :Samolot(silnik, liczbaSiedzen, kosztProdukcjiBezSilnika, wagaBezSilnika, oplywowosc)
{
}

void SamolotWyczynowy::UstawCzyKlapyOtwarte(bool w)
{
	klapy = w;
}

