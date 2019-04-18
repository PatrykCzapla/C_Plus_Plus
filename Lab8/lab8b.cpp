#include <iostream> 
#include "Skorpion.h"
#include "Zaklecie.h"
#include "Bron.h"
#include "SymbolWiary.h"
#include "Kaplan.h"
using namespace std;

//void spotkanie(Skorpion* skorpion, Kaplan* kaplan)
//{
//	int i = 1;
//	cout << "Witaj Czarodzieju! Musisz ocalic swiat przed atakiem Pajakow" << endl;
//	while (skorpion->czyZyje() && kaplan->czyZyje())
//	{
//		cout << " ********** RUNDA "<< i++ << " **********" << endl;
//		cout << *kaplan << endl << *skorpion << endl;
//		// atakuje kaplan
//		skorpion->przyjmij_atak(kaplan->wykonaj_atak(skorpion->jaki_poziom_ochrony()));
//		if (skorpion->czyZyje()) // atakuje skorpion
//			kaplan->przyjmij_atak(skorpion->wykonaj_atak(kaplan->jaki_poziom_ochrony()));
//	}
//	cout << " ********** KONIEC WALKI **********" << endl;
//	cout << *kaplan << endl << *skorpion << endl;
//	if (skorpion->czyZyje())
//		cout << "Polegles na polu chwaly" << endl;
//	else
//		cout << "Zwyciezyles !!! Swiat uratowany" << endl;
//
//}

int main()
{
	// ==================   ETAP 1 (1,5 pkt)  ===========================
	
	cout << endl << "-------------  ETAP 1 (1,5 pkt) --------------" << endl;

	SkorpionOlbrzymi skorpion1;
	JadowitySkorpionOlbrzymi skorpion2;

	cout << skorpion1 << skorpion2 << endl;

	cout << "Atakuje " << skorpion1 << "- trafia i zadaje " << skorpion1.wykonaj_atak(1) << " obrazen" << endl;
	cout << "Atakuje " << skorpion1 << "- nie trafia i zadaje " << skorpion1.wykonaj_atak(8) << " obrazen" << endl;
	cout << "Broni sie " << skorpion1 << " - unika ataku !" << endl;
	cout << "Broni sie " << skorpion1 << "- trafiony za 20 obrazen!" << endl;
	skorpion1.przyjmij_atak(20);
	if (!skorpion1.czyZyje()) cout << skorpion1 << "- zabity!!! Huraaaa!!!" << endl << endl;

	cout << "Atakuje " << skorpion2 << "- trafia i zadaje " << skorpion2.wykonaj_atak(1) << " obrazen" << endl;
	cout << "Atakuje " << skorpion2 << "- to 2 atak wiec zawsze trafia i zadaje " << skorpion2.wykonaj_atak(100) << " obrazen" << endl;
	cout << "Atakuje " << skorpion2 << "- nie trafia i zadaje " << skorpion2.wykonaj_atak(8) << " obrazen" << endl;
	cout << "Broni sie " << skorpion2 << "- trafiony za 20 obrazen!" << endl;
	skorpion2.przyjmij_atak(20);
	cout << "Broni sie " << skorpion2 << "- trafiony za 20 obrazen!" << endl;
	skorpion2.przyjmij_atak(20);
	if (!skorpion2.czyZyje()) cout << skorpion2 << "- zabity!!! Huraaaa!!!" << endl << endl;


	// ==================   ETAP 2 (1 pkt)  ===========================

	cout << endl << "-------------  ETAP 2 (1 pkt) --------------" << endl;

	ZaklecieOfensywne zo("Widmowe Ostrza", 1, 2);
	ZaklecieDefensywne zd("Leczniczy dotyk", 1, 4);

	cout << zo << "Obrazenia: " << zo.wypowiedz_zaklecie() << endl;
	cout << zd << "Odzyskane punkty zycia: " << zd.wypowiedz_zaklecie() << endl;
	

	// ==================   ETAP 3 (1 pkt)  ===========================

	cout << endl << "-------------  ETAP 3  (1 pkt) --------------" << endl;

	Bron* miecz = new Bron("Miecz", "klasyczny miecz jednoreczny", 3);

	cout << *miecz;
	cout << "Atak mieczem - zadano " << miecz->atak_bronia() << " obrazenia" << endl;

	delete miecz; 

	SymbolWiary* symbol = new SymbolWiary("Pierscien z granitem", "pierscien z symbolem zywiolu ziemi");

	cout << endl<< *symbol << endl;
	symbol->uzyj();

	delete symbol; 


	// ==================   ETAP 4 (1 pkt)  ===========================

	cout << endl << "-------------  ETAP 4  (1 pkt) --------------" << endl;

	Kaplan kaplan("Asgaroth Tempus, Patriarcha Ziemi");
	cout << kaplan << endl;

	if (kaplan.znajdz_zaklecie_ofensywne() == -1)
		cout << "Zaklecie ofensywne niedostepne" << endl;
	else
		cout << "Zaklecie ofensywne dostepne pod indeksem: " << kaplan.znajdz_zaklecie_ofensywne() << endl;
	if (kaplan.znajdz_zaklecie_defensywne() == -1)
		cout << "Zaklecie defensywne niedostepne" << endl;
	else
		cout << "Zaklecie defensywne dostepne pod indeksem: " << kaplan.znajdz_zaklecie_defensywne() << endl;
	cout << endl;
	system("pause");

	// ==================   ETAP 5 (1,5 pkt)  ===========================

	cout << endl << "-------------  ETAP 5  (1,5 pkt) --------------" << endl;

	//cout << "Wezyr przygotowuje sie ... bierze ksiege do reki, medytuje, bierze swoj kij ..." << endl;
	//kaplan.przygotuj_postac();
	//cout << kaplan << endl;

	//if (kaplan.znajdz_zaklecie_ofensywne() == -1)
	//	cout << "Zaklecie ofensywne niedostepne" << endl;
	//else
	//	cout << "Zaklecie ofensywne dostepne pod indeksem: " << kaplan.znajdz_zaklecie_ofensywne() << endl;
	//if (kaplan.znajdz_zaklecie_defensywne() == -1)
	//	cout << "Zaklecie defensywne niedostepne" << endl;
	//else
	//	cout << "Zaklecie defensywne dostepne pod indeksem: " << kaplan.znajdz_zaklecie_defensywne() << endl;
	//cout << endl;

	cout << endl << "-------------  Symulacja  (na koniec) --------------" << endl;

	//JadowitySkorpionOlbrzymi skorpion;

	//spotkanie(&skorpion, &kaplan);

	return 0;
}