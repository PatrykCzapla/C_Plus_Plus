#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Skorpion
{	
protected:
	int punktyZycia = 15;
	int sila_ataku = 2;
	int poziom_ochrony = 2;

public:
	virtual ~Skorpion() {};
	bool czyZyje() const { return punktyZycia > 0; }
	int jaki_poziom_ochrony() const { return poziom_ochrony; }

	virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const = 0;
	void przyjmij_atak(int obrazenia);

	virtual void info(ostream&) const = 0;
	friend ostream& operator<<(ostream&, const Skorpion&);
};

class SkorpionOlbrzymi : public Skorpion
{
public:
	// uzupelnij
	int wykonaj_atak(int poziom_ochrony_przeciwnika) const override;
	int atak_ostrym_odnozem() const;
	~SkorpionOlbrzymi() {};
	void info(ostream&) const;
};

class JadowitySkorpionOlbrzymi : public SkorpionOlbrzymi
{
	static int ktory_atak;
	int punktyZycia = 30;
	int sila_ataku = 4;
	int poziom_ochrony = 4;
public:
	int atak_jadowitym_kolcem() const;
	// uzupelnij
	~JadowitySkorpionOlbrzymi() {};
	int wykonaj_atak(int poziom_ochrony_przeciwnika) const override;
	void info(ostream&) const;
};