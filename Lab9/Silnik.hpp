#pragma once

#include <iostream>

class FabrykaSamolotow;

class Silnik
{
	friend class FabrykaSamolotow;

private:
	float waga;
	float moc;
	int kosztProdukcji;

protected:
	virtual void ZwrocInformacje(std::ostream& out) const;
	virtual Silnik* Replikuj() const = 0;

public:
		Silnik(float waga, float moc, int kosztProdukcji);
		virtual ~Silnik();

		float ZwrocWage() const;
		float ZwrocMoc() const;
		int ZwrocKosztProdukcji() const;

		virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const = 0;
		float ObliczPredkoscMaksymalna(float oplywowosc, float wspolczynnikMocy) const;

		friend std::ostream& operator << (std::ostream& out, const Silnik& silnik);
};

class SilnikSpalinowy :public Silnik
{
	float waga;
	int kosztProdukcji;
protected:
	virtual void ZwrocInformacje(std::ostream& out) const;
public:
	SilnikSpalinowy(float moc);
	virtual ~SilnikSpalinowy();
	virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const;
	friend std::ostream& operator << (std::ostream& out, const SilnikSpalinowy& silnik);
	virtual SilnikSpalinowy* Replikuj() const;
};

class SilnikElektryczny :public Silnik
{
	float waga;
	int kosztProdukcji;
protected:
	virtual void ZwrocInformacje(std::ostream& out) const;
public:
	SilnikElektryczny(float moc);
	virtual ~SilnikElektryczny();
	virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const;
	friend std::ostream& operator << (std::ostream& out, const SilnikElektryczny& silnik);
	virtual SilnikElektryczny* Replikuj() const;
};

class SilnikOdrzutowy :public Silnik
{
	float waga;
	int kosztProdukcji;
protected:
	virtual void ZwrocInformacje(std::ostream& out) const;
public:
	SilnikOdrzutowy(float moc);
	virtual ~SilnikOdrzutowy();
	virtual float ObliczPrzyspieszenie(float waga, float wspolczynnikMocy) const;
	friend std::ostream& operator << (std::ostream& out, const SilnikOdrzutowy& silnik);
	virtual SilnikOdrzutowy* Replikuj() const;
};