#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "dane.h"
   
dane::dane(const char* imie, const char* nazwisko)
{
	strcpy(this->imie, imie);
	strcpy(this->nazwisko, nazwisko);
}

bool operator==(const dane& d1, const dane& d2)
{
	return strcmp(d1.imie, d2.imie) == 0 && strcmp(d1.nazwisko, d2.nazwisko)==0;
}

ostream& operator<<(ostream& out, const dane& d)
{
	out << "   dane: ";
	out << setw(dane::M) << left << d.imie << setw(dane::M) << left << d.nazwisko;
	
	return out;
}




