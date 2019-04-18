#include "Silnik.hpp"

void Silnik::ZwrocInformacje(std::ostream & out) const
{
	out << "  Waga: " << waga << std::endl;
	out << "  Moc: " << moc << std::endl;
}

Silnik::Silnik(float waga, float moc, int kosztProdukcji):waga(waga),moc(moc),kosztProdukcji(kosztProdukcji)
{
}

Silnik::~Silnik()
{
}

float Silnik::ZwrocWage() const
{
	return waga;
}

float Silnik::ZwrocMoc() const
{
	return moc;
}

int Silnik::ZwrocKosztProdukcji() const
{
	return kosztProdukcji;
}

float Silnik::ObliczPredkoscMaksymalna(float oplywowosc, float wspolczynnikMocy) const
{
	return (0.1*oplywowosc*moc*wspolczynnikMocy + 300.0);
}

std::ostream & operator<<(std::ostream & out, const Silnik & silnik)
{
	silnik.ZwrocInformacje(out);
	return out;
}

std::ostream & operator<<(std::ostream & out, const SilnikSpalinowy & silnik)
{
	silnik.ZwrocInformacje(out);
	return out;
}

std::ostream & operator<<(std::ostream & out, const SilnikElektryczny & silnik)
{
	silnik.ZwrocInformacje(out);
	return out;
}

std::ostream & operator<<(std::ostream & out, const SilnikOdrzutowy & silnik)
{
	silnik.ZwrocInformacje(out);
	return out;
}


void SilnikSpalinowy::ZwrocInformacje(std::ostream & out) const
{
	out << " Silnik spalinowy:" << std::endl;
	out << "  Waga: " << ZwrocWage() << std::endl;
	out << "  Moc: " << ZwrocMoc() << std::endl;
}

SilnikSpalinowy::SilnikSpalinowy(float moc):Silnik(200,moc,11*moc)
{
}

SilnikSpalinowy::~SilnikSpalinowy()
{
}

float SilnikSpalinowy::ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const
{
	return (0.05*waga) / (sqrt(ZwrocMoc()*wspolczynnikMocy));
}

SilnikSpalinowy * SilnikSpalinowy::Replikuj() const
{
	return new SilnikSpalinowy(*this);
}

void SilnikElektryczny::ZwrocInformacje(std::ostream & out) const
{
	out << " Silnik elektryczny:" << std::endl;
	out << "  Waga: " << ZwrocWage() << std::endl;
	out << "  Moc: " << ZwrocMoc() << std::endl;
}

SilnikElektryczny::SilnikElektryczny(float moc):Silnik(140,moc,14*moc)
{
}

SilnikElektryczny::~SilnikElektryczny()
{
}

float SilnikElektryczny::ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const
{
	return (0.5*waga) / (ZwrocMoc()*wspolczynnikMocy);
}

SilnikElektryczny * SilnikElektryczny::Replikuj() const
{
	return new SilnikElektryczny(*this);
}

void SilnikOdrzutowy::ZwrocInformacje(std::ostream & out) const
{
	out << " Silnik odrzutowy:" << std::endl;
	out << "  Waga: " << ZwrocWage() << std::endl;
	out << "  Moc: " << ZwrocMoc() << std::endl;
}

SilnikOdrzutowy::SilnikOdrzutowy(float moc):Silnik(1100,moc,16*moc)
{
}

SilnikOdrzutowy::~SilnikOdrzutowy()
{
}

float SilnikOdrzutowy::ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const
{
	return (100 * waga) / ((ZwrocMoc()*wspolczynnikMocy)*(ZwrocMoc()*wspolczynnikMocy));
}

SilnikOdrzutowy * SilnikOdrzutowy::Replikuj() const
{
	return new SilnikOdrzutowy(*this);
}
