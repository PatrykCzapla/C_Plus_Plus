#include "moneta.h"
// uzupe³nij
moneta::moneta(string nominal, int rok, double cena)
{
	this->nominal = nominal;
	this->rok = rok;
	this->cena = cena;
	ile_lat_przewidywan = 0;
	oblicz_wartosc(0);
}
moneta::moneta(string nominal, int rok, double cena, grading &gr) :grading(gr)
{
	this->cena = cena;
	this->nominal = nominal;
	this->rok = rok;
	ile_lat_przewidywan = 0;
	oblicz_wartosc(0);
}
moneta::moneta(string nominal, int rok, double cena, int nota, firma centrum):grading(nota,centrum)
{
	this->cena = cena;
	this->nominal = nominal;
	this->rok = rok;
	ile_lat_przewidywan = 0;
	oblicz_wartosc(0);
}
moneta::moneta(const moneta& b) :grading((grading&)b)
{
	cena = b.cena;
	rok = b.rok;
	nominal = b.nominal;
	ile_lat_przewidywan = b.ile_lat_przewidywan;
	oblicz_wartosc(0);
}
moneta::~moneta()
{
	delete[] przewidywana_wartosc;
}
moneta& moneta::operator = (const moneta& b)
{
	if (this == &b)return *this;
	nota = b.nota;
	wsp_ceny = b.wsp_ceny;
	firma_gradingowe = new firma;
	*firma_gradingowe = *(b).firma_gradingowe;
	cena = b.cena;
	rok = b.rok;
	nominal = b.nominal;
	ile_lat_przewidywan = b.ile_lat_przewidywan;
	oblicz_wartosc(0);
	return *this;
}
void moneta::oblicz_wartosc(int ile_lat)
{
	przewidywana_wartosc = new double[ile_lat+1];
	przewidywana_wartosc[0] = cena*wsp_ceny;
	for (int i = 1; i <= ile_lat; i++)
	{
		przewidywana_wartosc[i] = przewidywana_wartosc[i - 1] *1.05;
	}
	ile_lat_przewidywan = ile_lat;
}
ostream& operator<<(ostream& out, const moneta& b)
{
	out << "Moneta o nominale " << b.nominal << ", " << "z roku " << b.rok << ", cena: " << b.cena << "zl, wartosc: " << b.cena*b.wsp_ceny << "zl " << (grading&)b << endl;
	return out;
}
void moneta::wypisz_przewidywana_wartosc()
{
	cout << "Moneta o nominale " << nominal << ", z roku " << rok << ", cena: " << cena <<" "<< (grading&)(*this) << endl << "Przewidywana wartosc w kolejnych"<<ile_lat_przewidywan<<" latach:" << endl;
	for (int i = 0; i <= ile_lat_przewidywan; i++)
	{
		cout << i << ": " << przewidywana_wartosc[i] << endl;
	}
}

