#include "bank.h"

   
//------------------------------------------------------------------
double bank::oproc_lokaty  = 10;		// oprocentowanie lokaty wynosi 10%
//------------------------------------------------------------------

ostream& operator<<(ostream& out, const bank& b)
{
	cout << "-------------------------------------------";
	if (!b.n)
		out << endl << "Brak kont w banku" << endl;

	for (int i = 0; i < b.n; i++)
		out << *b.konta[i] << endl;
	cout << "-------------------------------------------";

	return out;
}
//------------------------------------------------------------------

int bank::znajdz_konto(unsigned int nr_konta) const
{
	int i = -1;
	for (int j = 0; j < n; j++)
	{
		if (nr_konta == konta[i]->nr_konta)i = j;
	}
	// uzupe³nij w ETAP 3

	return i;
}

//------------------------------------------------------------------

bool bank::nowe_konto(const klient& k)
{
	// uzupe³nij w ETAP 2
	n++;
	konto**w;
	w = new (nothrow) konto*[n];
	w[n-1]= new (nothrow) konto(k.osoba, nadaj_nr_konta);
	if (w == nullptr)return false;
	if (w[n - 1] == nullptr)return false;
	for (int i = 0; i < n-1; i++)
	{
		w[i] = konta[i];
	}
	konta = w;
	nadaj_nr_konta++;
	return true;
}

//------------------------------------------------------------------

bool bank::kasuj_konto(const klient& k)
{
	// uzupe³nij w ETAP 3
	int w=znajdz_konto(k.nr_konta);
	if (w == -1)return false;
	int g =konta[w]->czy_wlasciciel_konta(k.osoba);
	if (g == 0)return false;
	konto** a;
	a = new (nothrow) konto*[n - 1];
	if (a == nullptr)return false;
	for (int i = 0; i < w; i++)
	{
		a[i] = konta[i];
	}
	for (int i = w; i < n - 1; i++)
	{
		a[i] = konta[i + 1];
	}
	konta = a;
	n--;
	return true;
}

//------------------------------------------------------------------

bool bank::wplata_na_konto(const klient& k)
{
	// uzupe³nij w ETAP 4a

	return true;
}

//------------------------------------------------------------------

bool bank::wyplata_z_konta(const klient& k)
{
	// uzupe³nij w ETAP 4b

	return true;
}

//------------------------------------------------------------------

bool bank::wez_lokate(const klient& k)
{
	// uzupe³nij w ETAP 5

	return true;
}

//------------------------------------------------------------------

bool bank::kasuj_lokate(const klient& k)
{
	// uzupe³nij w ETAP 6

	return true;
}

//------------------------------------------------------------------


