#pragma once

#include "Silnik.hpp"

class FabrykaSamolotow;

class Samolot
{
	friend class FabrykaSamolotow;

private:
	Silnik * silnik;
	int liczbaSiedzen;
	int kosztProdukcjiBezSilnika;
	float wagaBezSilnika;
	float oplywowosc;

protected:
	virtual void ZwrocInformacje(std::ostream& out) const;
	virtual Samolot* Replikuj(FabrykaSamolotow& fabryka) const = 0;
	Silnik& ZwrocSilnik() const;

public:
	Samolot(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc);
	virtual ~Samolot();

	int ZwrocLiczbeSiedzen() const;
	int ZwrocCene() const;
	int ZwrocKosztProdukcji() const;
	virtual float ZwrocWage() const;
	virtual float ZwrocOplywowosc() const;
	virtual float ZwrocWspolczynnikMocy() const;

	float ZwrocPrzyspieszenie() const;
	float ZwrocPredkoscMaksymalna() const;


	friend std::ostream& operator << (std::ostream& out, const Samolot& samolot);
};

class SamolotPasazerski :public Samolot
{
	bool ogrzewanie=0;
protected:
	void ZwrocInformacje(std::ostream& out) const;
public:
	SamolotPasazerski(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc);
	void UstawPodgrzewanieSiedzen(bool w);
	virtual float ZwrocWspolczynnikMocy() const;
	virtual SamolotPasazerski* Replikuj(FabrykaSamolotow& fabryka) const;
};

class SamolotTransportowy :public Samolot
{
	float towar = 0;
protected:
	void ZwrocInformacje(std::ostream& out) const;
public:
	SamolotTransportowy(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc);
	void UstawIloscTowaru(float w);
	virtual float ZwrocWage() const;
};

class SamolotWyczynowy :public Samolot
{
	bool klapy = 0;
protected:
	void ZwrocInformacje(std::ostream& out) const;
public:
	SamolotWyczynowy(Silnik* silnik, int liczbaSiedzen, int kosztProdukcjiBezSilnika, float wagaBezSilnika, float oplywowosc);
	void UstawCzyKlapyOtwarte(bool w);
	virtual float ZwrocOplywowosc() const
	{
		if (klapy == 1)return Samolot::ZwrocOplywowosc()*0.9;
		else return Samolot::ZwrocOplywowosc();
	}
};