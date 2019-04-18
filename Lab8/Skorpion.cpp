#include <iostream> 
using namespace std;
#include "Skorpion.h"

// uzupelnij


// Klasa Skorpion

void Skorpion::przyjmij_atak(int obrazenia)
{
	punktyZycia -= obrazenia;
}

ostream& operator<<(ostream& out, const Skorpion& p)
{
	p.info(out);
	return out;
}

// Klasa SkorpionOlbrzymi

// uzupelnij
int SkorpionOlbrzymi::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	if (sila_ataku > poziom_ochrony_przeciwnika) return 2;
	else return 0;
}
int SkorpionOlbrzymi::atak_ostrym_odnozem() const
{
	return 2;
}

void SkorpionOlbrzymi::info(ostream& out) const
{
	cout << "Skorpion Olbrzymi - poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punktyZycia << endl;
}
// Klasa JadowitySkorpionOlbrzymi

// uzupelnij
int JadowitySkorpionOlbrzymi::atak_jadowitym_kolcem() const
{
	return 8;
}
int JadowitySkorpionOlbrzymi::ktory_atak = 0;
int JadowitySkorpionOlbrzymi::wykonaj_atak(int poziom_ochrony_przeciwnika) const
{
	if (ktory_atak == 2)
	{
		return atak_jadowitym_kolcem();
		ktory_atak = 0;
	}
	if (sila_ataku > poziom_ochrony_przeciwnika)
	{
		return 2;
		ktory_atak++;
	}
	else
	{
		return 0;
		ktory_atak++;
	}
}
void JadowitySkorpionOlbrzymi::info(ostream&) const
{
	cout << "adowity Skorpion Olbrzymi - poziom ochrony: " << poziom_ochrony << " punkty zycia: " << punktyZycia << endl;
}