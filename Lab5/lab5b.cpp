#include <iostream>

#include "Obrazek.hpp"


// Dane obrazka
const char imageData[] = {
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', 'O', 'O', 'O', 'O', 'O', 'O', ' ', ' ',' ', ' ', 'K', 'K', ' ', ' ', ' ', 'K', 'K', ' ', ' ', ' ',
	' ', ' ', ' ', 'O', 'O', ' ', ' ', ' ', ' ', 'O', 'O', ' ',' ', ' ', 'K', 'K', ' ', ' ', 'K', 'K', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', 'O', 'O', ' ', ' ', ' ', ' ', 'O', 'O', ' ',' ', ' ', 'K', 'K', ' ', 'K', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', 'O', 'O', ' ', ' ', ' ', ' ', 'O', 'O', ' ',' ', ' ', 'K', 'K', 'K', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', 'O', 'O', ' ', ' ', ' ', ' ', 'O', 'O', ' ',' ', ' ', 'K', 'K', ' ', 'K', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', 'O', 'O', ' ', ' ', ' ', ' ', 'O', 'O', ' ',' ', ' ', 'K', 'K', ' ', ' ', 'K', 'K', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', 'O', 'O', 'O', 'O', 'O', 'O', ' ', ' ',' ', ' ', 'K', 'K', ' ', ' ', ' ', 'K', 'K', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
	' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^','^', '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ',
	' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
};


int main()
{
	std::cout << "===================== ETAP 1 =====================" << std::endl;

	// Konstruktor bezargumentowy
	Obrazek img1;

	// Konstruktor z obrazkiem
	const Obrazek img2(13, 24, imageData);

	// Konstruktor z pustym obrazkiem
	Obrazek img3(8, 32);
	Obrazek img4(12, 20);

	// konstruktor z ujemnym rozmiarem
	Obrazek img5(32, -1);

	// Wype³nianie kolorem
	const char FillCharacter = '?';
	img4.UstawZnak(FillCharacter);

	// Rysowanie na konsoli
	std::cout << "img1 (pusty obrazek bez rozmiaru):" << std::endl << img1 << std::endl;
	std::cout << "img2 (wczytany obrazek):" << std::endl << img2 << std::endl;
	std::cout << "img3 (pusty obrazek):" << std::endl << img3 << std::endl;
	std::cout << "img4 (obrazek wypelniony '" << FillCharacter << "'):" << std::endl << img4 << std::endl;
	std::cout << "img5 (obrazek z ujemnym rozmiarem):" << std::endl << img5 << std::endl;
	std::cout << std::endl << std::endl;
//
//
//
//	std::cout << "===================== ETAP 2 =====================" << std::endl;
//
//	// Konstruktor kopiuj¹cy
//	Obrazek img6 = img2;
//
//	// Operator przypisania
//	img4 = img2;
//	img5 = img2;
//
//	// Pobieranie rozmiaru i koloru z konsoli
//	std::cout << "Wczytywanie obrazka img3 (np. 3 10 * ): ";
//	std::cin >> img3;
//
//	// Pobieranie rozmiaru obrazka
//	int img2Rows, img2Columns;
//	img2.ZwrocRozmiar(img2Rows, img2Columns);
//
//	// Operator funkcyjny (const), liczenie ilosci liter
//	int charOCount = 0, charKCount = 0, charHatCount = 0, spacesCount = 0, otherChars = 0;
//	for (int row = 0; row < img2Rows; ++row)
//	{
//		for (int column = 0; column < img2Columns; ++column)
//		{
//			switch (img2(row, column))
//			{
//				case 'O': charOCount += 1; break;
//				case 'K': charKCount += 1; break;
//				case '^': charHatCount += 1; break;
//				case ' ': spacesCount += 1; break;
//				default: otherChars += 1; break;
//			}
//		}
//	}
//
//	// Operator funkcyjny (ref), tworzenie ramki
//	const char FrameCharacter = '#';
//	for (int row = 0; row < img2Rows; ++row)
//		img4(row, 0) = img4(row, img2Columns - 1) = FrameCharacter;
//
//	for (int column = 0; column < img2Columns; ++column)
//		img4(0, column) = img4(img2Rows - 1, column) = FrameCharacter;
//
//	std::cout << "Rozmiar img2: " << img2Rows << ", " << img2Columns << std::endl;
//	std::cout << "img2 sklada sie z:" << std::endl;
//	std::cout << "\t" << charOCount << " literek O (powinno byc 32)" << std::endl;
//	std::cout << "\t" << charKCount << " literek K (powinno byc 25)" << std::endl;
//	std::cout << "\t" << charHatCount << " znakow ^ (powinno byc 20)" << std::endl;
//	std::cout << "\t" << spacesCount << " spacji (powinno byc 235)" << std::endl;
//	std::cout << "\t" << otherChars << " innych znakow (powinno byc 0)" << std::endl;
//	std::cout << "img2 (oryginalny obrazek):" << std::endl << img2 << std::endl;
//	std::cout << "img3 (obrazek wczytany z konsoli):" << std::endl << img3 << std::endl;
//	std::cout << "img4 (obrazek z ramka):" << std::endl << img4 << std::endl;
//	std::cout << "img5 (kopia oryginalnego obrazka):" << std::endl << img5 << std::endl;
//	std::cout << std::endl << std::endl;
//
//
//
//	std::cout << "===================== ETAP 3 =====================" << std::endl;
//
//	const Obrazek img4Copy(img4);
//
//	// Operator indeksuj¹cy
//	for (int i = 0; i < ((img2Rows / 2) * img2Columns); ++i)
//	{
//		char character = img4Copy[i];
//
//		switch (character)
//		{
//			case 'K':
//			case 'O':
//			img4[i] = ' ';
//			break;
//
//			case ' ':
//			img4[i] = '%';
//			break;
//
//			case FrameCharacter:
//			img4[i] = '?';
//			break;
//
//			case '^':
//			img4[i] = '_';
//			break;
//
//			default:
//			break;
//		}
//	}
//
//	// Lustrzane odbicie
//	Obrazek img7 = img6 = img5 = img4;
//	img5.Odbij();
//
//	// Obracanie
//	img6.ObrocWLewo();
//	img7.Odbij().ObrocWLewo().ObrocWLewo();
//
//	std::cout << "img4Copy (kopia obrazka 4 przed modyfikacja):" << std::endl << img4Copy << std::endl;
//	std::cout << "img4 (obrazek zmodyfikowany w polowie):" << std::endl << img4 << std::endl;
//	std::cout << "img5 (obrazek po odbiciu lustrzanym):" << std::endl << img5 << std::endl;
//	std::cout << "img6 (obrazek obrocony w lewo):" << std::endl << img6 << std::endl;
//	std::cout << "img7 (obrazek po dobiciu i dwukrotnym obrocie):" << std::endl << img7 << std::endl;
//	std::cout << std::endl << std::endl;



	return 0;
}
