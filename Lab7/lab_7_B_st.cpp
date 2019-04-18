#include <iostream>
#include <string>
#include "grading.h"
#include "moneta.h"
using namespace std;

const int N = 10;

void sortuj(/* do uzupe³nienia */);

int main()
{
	cout << "---------------ETAP 1 - test klasy grading--------------------" << endl << endl;
	{
		grading gr1, gr2(66), gr3(70, firma::Professional_Coin_Grading_Service), gr4(gr3);
		grading gr5(50, firma::Polskie_Centrum_Gradingu), gr6;

		cout << gr1 << gr2 << gr3 << gr4;
		
		gr6 = gr5;
		cout << gr6;
	}

	cout << "--------------------------------------------------------------" << endl << endl;

	cout << "---------------ETAP 2 - test klasy banknnot-------------------" << endl << endl;
	{
		grading gr1(70, firma::Professional_Coin_Grading_Service);

		moneta b1, b2("1 zl"), b3("6 gr - szostak koronny Jan Kazimierz Ag", 1622, 200);
		moneta b4("20 zl - Chrobry Au", 1925, 2300, gr1);
		moneta b5("5 zl - Nike Ag", 1928, 900, 53);
		moneta b6("5 zl - Nike Ag", 1930, 1500, 66, firma::Numismatic_Guaranty_Corporation);
		moneta b7(b4), b8;	
		b8 = b4;

		cout << b1 << b2 << b3;
		cout << b4;
		cout << b5 << b6 << b7 << b8;

		cout << endl;
		b8.oblicz_wartosc(0);
		b8.wypisz_przewidywana_wartosc();
		b8.oblicz_wartosc(9);
		b8.wypisz_przewidywana_wartosc();
		b8.oblicz_wartosc(5);
		b8.wypisz_przewidywana_wartosc();

		b1 = b8;
		b1.wypisz_przewidywana_wartosc();
		moneta b9(b8);
		b9.wypisz_przewidywana_wartosc();

	}

	cout << "--------------------------------------------------------------" << endl << endl;

	/*cout << "---------------ETAP 3 - sortowanie----------------------------" << endl << endl;

	moneta kolekcja[N] = {
		moneta("20 zl - Chrobry Au", 1925, 2200, 62, firma::Numismatic_Guaranty_Corporation),
		moneta("1,5 gr - poltorak litewski Jan Kazimierz Ag", 1916, 90, 54),
		moneta("3 gr - trojak koronny Jan III Sobieski Ag", 1924, 230, 45),
		moneta("5 talarow Au", 1755, 8000, 44, firma::Professional_Coin_Grading_Service),
		moneta("5 talarow Au", 1755, 9600, 51, firma::Polskie_Centrum_Gradingu),
		moneta("szelag gdanski Kazimierz Jagiellonczyk Ag", 1490, 16000, 57, firma::Gliwickie_Centrum_Numizmatyczne),
		moneta("dukat wilenski Zygmunt II August Au", 1563, 75000, 53, firma::Numismatic_Guaranty_Corporation),
		moneta("100 dukatow Zygmunt III Waza Ag", 1621, 7000000, 65, firma::Polskie_Centrum_Gradingu),
		moneta("denar Boleslawa Chrobrego PRINCES POLONIE Ag", 1000, 74000, 67, firma::Professional_Coin_Grading_Service),
		moneta("1/3 gr - szelag - boratynka Jana Kazimierza Cu", 1658, 22, 66, firma::Gliwickie_Centrum_Numizmatyczne)
	};
	cout << "Kolekcja banknotow: " << endl;
	for (int i = 0; i<N; i++) cout << kolekcja[i];

	cout << endl;
	cout << "Kolekcja posortowana wg noty: " << endl;
	sortuj(kolekcja, N);
	for (int i = 0; i<N; i++) cout << kolekcja[i];

	cout << endl;
	cout << "Kolekcja posortowana wg wartosci: " << endl;
	sortuj(kolekcja, N, cmp_wartosc);
	for (int i = 0; i<N; i++) cout << kolekcja[i];*/

	cout << endl;
	system("pause");
	return 0;
}
