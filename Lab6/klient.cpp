#define _CRT_SECURE_NO_WARNINGS
#include "klient.h"

//-----------------------------------------------------------------------------
ostream& operator<<(ostream& out, const klient& k)
{
	out << endl << "KLIENT: " << endl;
	out << k.osoba << " klient: ";

	switch (k.cel)
	{
	case poco::NOWE_KONTO:			out << "NOWE_KONTO"; break;
	case poco::KASUJ_KONTO:			out << "KASUJ_KONTO"; break;
	case poco::WPLATA_NA_KONTO:		out << "WPLATA_NA_KONTO"; break;
	case poco::WYPLATA_Z_KONTA:		out << "WYPLATA_Z_KONTA"; break;
	case poco::WEZ_LOKATE:			out << "WEZ_LOKATE"; break;
	case poco::KASUJ_LOKATE:		out << "KASUJ_LOKATE"; break;
	default:						out << "NIE WIEM PO CO PRZYSZEDLEM DO BANKU?"; break;
	}

	out << " nr konta: " << k.nr_konta << " kwota: " << k.kwota << endl;
	return out;
}

//-----------------------------------------------------------------------------   
klient::klient(const char* imie, const char* nazwisko, enum poco cel, unsigned int nr_konta, double kwota)
	: osoba(imie,nazwisko), cel(cel), nr_konta(nr_konta), kwota(kwota) {}

//-----------------------------------------------------------------------------

bool klient::ide_do_banku(bank& b)
{
	bool wynik_sprawy = true;

	switch (cel)
	{
	case poco::NOWE_KONTO:		wynik_sprawy = b.nowe_konto(*this);	
								break;
	case poco::KASUJ_KONTO:		wynik_sprawy = b.kasuj_konto(*this);		
								break;
	case poco::WPLATA_NA_KONTO:	wynik_sprawy = b.wplata_na_konto(*this);	
								break; 
	case poco::WYPLATA_Z_KONTA:	wynik_sprawy = b.wyplata_z_konta(*this);	
								break;
	case poco::WEZ_LOKATE:		wynik_sprawy = b.wez_lokate(*this);			
								break;
	case poco::KASUJ_LOKATE:	wynik_sprawy = b.kasuj_lokate(*this);
								break;
	default:					wynik_sprawy = true; 
								break;
	}

	return wynik_sprawy;
}

//-----------------------------------------------------------------------------






