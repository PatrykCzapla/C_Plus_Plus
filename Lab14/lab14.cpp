#include <iostream>
#include <set>
#include <list>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
#include "druzyna.h"
#include "grupa.h"

int main()
{
	Druzyna argentyna("Argentyna", 1241, 5), niemcy("Niemcy", 1558, 1), brazylia("Brazylia", 1431, 2);
	Druzyna hiszpania("Hiszpania", 1126, 10), portugalia("Portugalia", 1274, 4), belgia("Belgia", 1298, 3);
	Druzyna szwajcaria("Szwajcaria", 1199, 6), francja("Francja", 1198, 7), chile("Chile", 1135, 9);
	Druzyna peru("Peru", 1125, 11), anglia("Anglia", 1051, 12), polska("Polska", 1183, 8);
	
	auto m1 = make_pair(argentyna, Rodzaj_meczu::TOWARZYSKI);
	auto m2 = make_pair(argentyna, Rodzaj_meczu::ELIMINACJE);
	auto m3 = make_pair(argentyna, Rodzaj_meczu::MISTRZOSTWA);
	auto m4 = make_pair(niemcy, Rodzaj_meczu::TOWARZYSKI);
	auto m5 = make_pair(niemcy, Rodzaj_meczu::ELIMINACJE);
	auto m6 = make_pair(niemcy, Rodzaj_meczu::MISTRZOSTWA);
	auto m7 = make_pair(brazylia, Rodzaj_meczu::TOWARZYSKI);
	auto m8 = make_pair(brazylia, Rodzaj_meczu::ELIMINACJE);
	auto m9 = make_pair(brazylia, Rodzaj_meczu::MISTRZOSTWA);
	auto m10 = make_pair(hiszpania, Rodzaj_meczu::TOWARZYSKI);
	auto m11 = make_pair(hiszpania, Rodzaj_meczu::ELIMINACJE);
	auto m12 = make_pair(hiszpania, Rodzaj_meczu::MISTRZOSTWA);
	auto m13 = make_pair(szwajcaria, Rodzaj_meczu::TOWARZYSKI);
	auto m14 = make_pair(szwajcaria, Rodzaj_meczu::ELIMINACJE);
	auto m15 = make_pair(szwajcaria, Rodzaj_meczu::MISTRZOSTWA);
	auto m16 = make_pair(anglia, Rodzaj_meczu::TOWARZYSKI);
	auto m17 = make_pair(anglia, Rodzaj_meczu::ELIMINACJE);
	auto m18 = make_pair(anglia, Rodzaj_meczu::MISTRZOSTWA);

	auto w1 = make_pair(0, 0), w13 = make_pair(2, 0), w25 = make_pair(4, 0);
	auto w2 = make_pair(0, 1), w14 = make_pair(2, 1), w26 = make_pair(4, 1);
	auto w3 = make_pair(0, 2), w15 = make_pair(2, 2), w27 = make_pair(4, 2);
	auto w4 = make_pair(0, 3), w16 = make_pair(2, 3), w28 = make_pair(4, 3);
	auto w5 = make_pair(0, 4), w17 = make_pair(2, 4), w29 = make_pair(4, 4);
	auto w6 = make_pair(0, 5), w18 = make_pair(2, 5), w30 = make_pair(4, 5);
	auto w7 = make_pair(1, 0), w19 = make_pair(3, 0), w31 = make_pair(5, 0);
	auto w8 = make_pair(1, 1), w20 = make_pair(3, 1), w32 = make_pair(5, 1);
	auto w9 = make_pair(1, 2), w21 = make_pair(3, 2), w33 = make_pair(5, 2);
	auto w10 = make_pair(1, 3), w22 = make_pair(3, 3), w34 = make_pair(5, 3);
	auto w11 = make_pair(1, 4), w23 = make_pair(3, 4), w35 = make_pair(5, 4);
	auto w12 = make_pair(1, 5), w24 = make_pair(3, 5), w36 = make_pair(5, 5);

	cout << " ********************* Etap 1 (4.0 pkt) ********************* " << endl << endl;

	Druzyna d1;
	cout << d1;

	Druzyna gujana("Gujana", 73, 182);
	cout << gujana;

	vector<pair<Druzyna, Rodzaj_meczu>> mecze1 = { m4, m8, m12, m1 };
	vector<pair<int, int>> wyniki1 = {w4, w14, w7, w22};
	Druzyna azerbejdzan("Azerbejdzan", 321, 105, mecze1, wyniki1);
	cout << azerbejdzan;

	cout << endl << " ********************* Etap 2 (1.0 pkt) ********************* " << endl << endl;

	Grupa_pilkarska gd1;
	if (gd1.czyPusta())
	{
		cout << "Grupa " << gd1.nazwaGrupy() << " rozmiar: " << gd1.rozmiar() << endl;
		cout << gd1 << endl;
	}

	Grupa_pilkarska europa("Europa");
	europa.dodaj(niemcy);
	europa.dodaj(belgia);
	europa.dodaj(szwajcaria);
	europa.dodaj(francja);
	europa.dodaj(polska);
	europa.dodaj(hiszpania);
	europa.dodaj(anglia);
	europa.dodaj(portugalia);
	if (!europa.czyPusta())
	{
		cout << "Grupa " << europa.nazwaGrupy() << " rozmiar: " << europa.rozmiar() << endl;
		cout << europa << endl;
	}

	Grupa_pilkarska wielka_trojka("Wielka Trojka");
	wielka_trojka.dodaj(belgia);
	wielka_trojka.dodaj(brazylia);
	wielka_trojka.dodaj(niemcy);
	cout << wielka_trojka << endl;

	if (!wielka_trojka.czy_jest_czescia(europa))
	{
		cout << wielka_trojka.nazwaGrupy() << " NIE JEST CZESCIA " << europa.nazwaGrupy() << endl;
	}
	else cout << "Blad...";

	cout << endl << "Zalozmy ze na miejsce Brazylii wskoczy na chwile Polska :)" << endl;
	wielka_trojka.usun(brazylia);
	wielka_trojka.dodaj(polska);
	if (wielka_trojka.czy_jest_czescia(europa))
	{
		cout << wielka_trojka.nazwaGrupy() << " JEST CZESCIA " << europa.nazwaGrupy() << endl;
	}
	else cout << "Blad...";
	wielka_trojka.usun(polska);
	wielka_trojka.dodaj(brazylia);

	/*cout << endl << " ********************* Etap 3 (1.0 pkt) ********************* " << endl << endl;

	Grupa_pilkarska ameryka_poludniowa("Ameryka Poludniowa");
	ameryka_poludniowa.dodaj(brazylia);
	ameryka_poludniowa.dodaj(argentyna);
	ameryka_poludniowa.dodaj(chile);
	ameryka_poludniowa.dodaj(peru);
	cout << ameryka_poludniowa << endl;

	Grupa_pilkarska am_plus_wt = ameryka_poludniowa + wielka_trojka;
	cout << am_plus_wt << endl;

	Grupa_pilkarska am_minus_wt = ameryka_poludniowa - wielka_trojka;
	cout << am_minus_wt << endl;

	cout << endl << " ********************* Etap 4 (2 pkt) ********************* " << endl << endl;

	Grupa_pilkarska fifa12 = europa + ameryka_poludniowa;
	cout << fifa12 << endl;

	cout << endl << "ROZGRYWKI" << endl;
	peru.rozegrano_kolejny_mecz(m5, w21); 
	peru.rozegrano_kolejny_mecz(m13, w33);
	peru.rozegrano_kolejny_mecz(m7, w6);
	cout << peru << endl;
	uaktualnij_grupe(fifa12, peru);

	polska.rozegrano_kolejny_mecz(m6, w19);
	polska.rozegrano_kolejny_mecz(m17, w34);
	polska.rozegrano_kolejny_mecz(m10, w27);
	uaktualnij_grupe(fifa12, polska);
	anglia.rozegrano_kolejny_mecz(m2, w8);
	anglia.rozegrano_kolejny_mecz(m11, w35);
	anglia.rozegrano_kolejny_mecz(m9, w11);
	uaktualnij_grupe(fifa12, anglia);
	niemcy.rozegrano_kolejny_mecz(m6, w4);
	niemcy.rozegrano_kolejny_mecz(m17, w17);
	niemcy.rozegrano_kolejny_mecz(m10, w30);
	uaktualnij_grupe(fifa12, niemcy);
	cout << fifa12 << endl;

	cout << "Druzyny z liczba punktow > 1250: " << endl;
	list<Druzyna> naj = najlepsze(fifa12, 1250);
	for (Druzyna d : naj)
	{
		cout << d;
	}

	cout << endl;
	cout << "Trzy wygrane mecze Polski i trzy przegrane Niemiec nie zmienily za bardzo rankingu...";

	cout << endl << endl;*/
	system("pause");
	return 0;
}

