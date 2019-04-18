#include <iomanip>
#include "lokata.h"
   

lokata::lokata(double wartosc, double oproc )
	: wartosc(wartosc), oproc(oproc) {}

double lokata::wartosc_lokaty() const
{
	double p = oproc;

	p /= 100;	// zamiana na u³amek

	return wartosc*(1+p);
}

ostream& operator<<(ostream& out, const lokata& l)
{
	out << fixed << setprecision(2);
	return out << " lokata: " << l.wartosc << " ( " << l.oproc<<"%)  " << " wartosc lokaty: " << l.wartosc_lokaty();
}




