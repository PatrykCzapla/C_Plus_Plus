#include "kolor.h"

using namespace std;

int main()
{
	cout << endl;
	cout << "****************ETAP 1****************" << endl;
	cout << "Tworzenie kolorow" << endl;
	cout << "**************************************" << endl;
	cout << endl;
	
	
	Kolor k1;
	cout << "W kolorze domyslnym jest: " << endl << k1[RED] << " czerwonego" << endl <<
		 k1[GREEN]<< " zielonego" << endl << k1[BLUE] << " niebieskiego" << endl;

	Kolor k2(184,3,500);
	cout << "Kolor fioletowy (184,3,255): " << k2 << endl;
	Kolor k3(RED);
	cout << "Predefiniowany: " << k3 << " - czerwony" << endl;
	Kolor k4(GREEN);
	cout << "Predefiniowany: " << k4 << " - zielony" << endl;
	Kolor k5(BLUE);
	cout << "Predefiniowany: " << k5 << " - niebieski" << endl;
	Kolor k6(CYAN);
	cout << "Predefiniowany: " << k6 << " - turkusowy" << endl;
	Kolor k7(MAGENTA);
	cout << "Predefiniowany: " << k7 << " - karmazynowy" << endl;
	Kolor k8(YELLOW);
	cout << "Predefiniowany: " << k8 << " - zolty" << endl;
	

	cout << endl;
	cout << "****************ETAP 2****************" << endl;
	cout << "Mieszanie kolorow" << endl;
	cout << "**************************************" << endl;
	cout << endl;
	
	
	Kolor k9;
	cout << "Podaj kolor RGB szesnastkowo (np: ab33ff): ";
	cin >> k9; 
	cout << "Kolor wczytany: " << k9 << endl;

	cout << "Odjecie od czerwonego koloru zielonego pozostawia czerwony: ";
	cout << Kolor(RED) - Kolor(GREEN) << endl;
	cout << "Odjecie podstawowego koloru od dopelniajacego daje podstawowy: " << endl;
	cout << "Cyan - Zielony: " << Kolor(CYAN) - Kolor(GREEN) << " (niebieski)" << endl;
	cout << "Kolor bialy k1: " << k1 << endl;
	(((k1 -= Kolor(BLUE)) -= Kolor(GREEN)) -= Kolor(RED)) -= k8;
	cout << "zminiamy w czarny k1: " << k1 << endl;
	

	cout << endl;
	cout << "****************ETAP 3****************" << endl;
	cout << "Rysowanie" << endl;
	cout << "**************************************" << endl;
	cout << endl;

	/*
	cout << "Napelnienie farby..." << endl;
	Kolor::uzupelnij(CYAN);
	Kolor::uzupelnij(MAGENTA);
	Kolor::uzupelnij(YELLOW);
	Kolor::uzupelnij(BLACK);
	cout << "Cyan: " << k1(CYAN) << ", magenta: " << k1(MAGENTA) << ", yellow: " << k1(YELLOW) << endl;

	cout << "Rysowanie..." << endl;
	cout << "Kolorem zielonym" << endl;
	k4.maluj();
	cout << "Zostalo:" << endl;
	cout << "Cyan: " << k1(CYAN) << ", magenta: " << k1(MAGENTA) << ", yellow: " << k1(YELLOW) << ", black: " << k1(BLACK) << endl;
	cout << "Kolorem zielonym" << endl;
	k4.maluj();
	cout << "Zostalo:" << endl;
	cout << "Cyan: " << k1(CYAN) << ", magenta: " << k1(MAGENTA) << ", yellow: " << k1(YELLOW) << ", black: " << k1(BLACK) << endl;
	cout << "Kolorem szarym" << endl;
	Kolor(200, 200, 200).maluj();
	cout << "Zostalo:" << endl;
	cout << "Cyan: " << k1(CYAN) << ", magenta: " << k1(MAGENTA) << ", yellow: " << k1(YELLOW) << ", black: " << k1(BLACK) << endl;
	cout << "Innymi kolorami" << endl;
	k2.maluj();
	Kolor(234, 125, 44).maluj();
	Kolor(YELLOW).maluj();
	cout << "Zostalo:" << endl;
	cout << "Cyan: " << k1(CYAN) << ", magenta: " << k1(MAGENTA) << ", yellow: " << k1(YELLOW) << ", black: " << k1(BLACK) << endl;
	cout << "I jeszcze jedna kreska" << endl;
	Kolor(200, 100,	50).maluj();
	cout << "Zostalo:" << endl;
	cout << "Cyan: " << k1(CYAN) << ", magenta: " << k1(MAGENTA) << ", yellow: " << k1(YELLOW) << ", black: " << k1(BLACK) << endl;
	*/

	cout << endl << endl;
	system("pause");
	return 0;
}