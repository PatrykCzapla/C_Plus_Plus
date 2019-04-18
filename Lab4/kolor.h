#pragma once
#include <iostream>

using namespace std;

const int ZAKRES = 255;
const int ILOSC_KOLORU_DO_MALOWANIA = 1000;

enum kolor_zdefiniowany { CYAN, MAGENTA, YELLOW, BLACK, RED, GREEN, BLUE };

class Kolor {
private:
	int cyan;
	int magenta;
	int yellow;
	static int ilosc_C;
	static int ilosc_M;
	static int ilosc_Y;
	static int ilosc_K;

public:
	//Do uzupe³nienia
	Kolor(int c=255, int m=255, int y=255);
	Kolor(kolor_zdefiniowany a);
	int operator[](kolor_zdefiniowany a);
	friend ostream& operator<<(ostream& out, Kolor& a);
	friend istream& operator>>(istream& in, Kolor& a);
	friend Kolor operator-(Kolor a, Kolor b);
	friend Kolor& operator-=(Kolor& a, Kolor b);

};