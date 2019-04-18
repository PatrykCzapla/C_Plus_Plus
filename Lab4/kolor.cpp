
// uzupe³nij plik implementacyjny klasy kolor
#include "kolor.h"

int Kolor::ilosc_C=0;
int Kolor::ilosc_M=0;
int Kolor::ilosc_Y=0;
int Kolor::ilosc_K=0;
Kolor::Kolor(int c, int m, int y)
{
	if (c > 255)c = 255;
	if (c < 0)c = 0;
	if (m > 255)m = 255;
	if (m < 0)m = 0;
	if (y > 255)y = 255;
	if (y < 0)y = 0;
	cyan = ZAKRES - c;
	magenta = ZAKRES - m;
	yellow = ZAKRES - y;
	
}
Kolor::Kolor(kolor_zdefiniowany a)
{
	if (a == BLACK)cyan = magenta = yellow = 0;
	if (a == CYAN)
	{
		cyan = 255;
		magenta = yellow = 0;
	}
	if (a == MAGENTA)
	{
		magenta = 255;
		cyan = yellow = 0;
	}
	if (a == YELLOW)
	{
		yellow = 255;
		cyan = magenta = 0;
	}
	if (a == RED)
	{
		cyan = 0;
		yellow = magenta = 255;
	}
	if (a == GREEN)
	{
		magenta = 0;
		yellow = cyan = 255;
	}
	if (a == BLUE)
	{
		yellow = 0;
		cyan = magenta = 255;
	}
}
int Kolor::operator[](kolor_zdefiniowany a)
{
	if (a == 4)return -(cyan - ZAKRES);
	if (a == 5)return -(magenta - ZAKRES);
	if (a == 6)return -(yellow - ZAKRES);
}
ostream& operator<<(ostream& out, Kolor& a)
{
	int red = -(a.cyan - ZAKRES);
	int green = -(a.magenta - ZAKRES);
	int blue = -(a.yellow - ZAKRES);
	out << "RGB:" << red << "," << green << "," << blue << endl;
	return out;
}
istream& operator>>(istream& in, Kolor& a)
{
	int c, r=0, g=0, b=0;
	in >> hex >> c;
	r = c >> 16;
	g = c << 16;
	g >> 24;
	b = c << 24;
	b >> 24;
	Kolor w;
	w = Kolor(r, g, b);
	a.cyan=w.cyan;
	a.magenta = w.magenta;
	a.yellow = w.yellow;
	return in;
}
Kolor operator-(Kolor a, Kolor b)
{
	int red,green ,blue;
	Kolor t;
	red = -(a.cyan - ZAKRES) + (b.cyan - ZAKRES);
	green = -(a.magenta - ZAKRES) + (b.magenta - ZAKRES);
	blue = -(a.yellow - ZAKRES) + (b.yellow - ZAKRES);
	t = Kolor(red, green, blue);
	return t;
}
Kolor& operator-=(Kolor& a, Kolor b)
{
	a = a - b;
	return a;
}