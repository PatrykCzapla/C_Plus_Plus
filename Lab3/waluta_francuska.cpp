#include "waluta_francuska.h"

waluta_francuska::waluta_francuska()
{
	liwr = 1;
	solid = 0;
	denar = 0;
}

waluta_francuska::waluta_francuska(int a, int b, int c)
{
	if (a < 0 || b < 0 || c < 0)
	{
		liwr = solid = denar = 0;
		return;
	}
	liwr = a;
	solid = b;
	denar = c;
	ukladanie();
}

waluta_francuska::waluta_francuska(double a)
{
	if (a < 0)
	{
		liwr = solid = denar = 0;
		return;
	}
	liwr = solid = 0;
	denar = round(2.4*a*100);
	ukladanie();
}

void waluta_francuska::ukladanie()
{
	while (denar >= 12)
	{
		solid += 1;
		denar -= 12;
	}
	while (solid >= 20)
	{
		liwr += 1;
		solid -= 20;
	}
	while (solid > 0 && denar < 0)
	{
		solid -= 1;
		denar += 12;
	}
	while (liwr > 0 && solid < 0)
	{
		liwr -= 1;
		solid += 12;
	}
}

ostream& operator<<(ostream& out, const waluta_francuska& a)
{
	out << "L " << a.liwr<<"." << a.solid<<"." << a.denar << endl;
	return out;
}

istream& operator>>(istream& in, waluta_francuska& a)
{
	waluta_francuska b = waluta_francuska(0, 0, 0);
	double c;
	in >> c;
	b = waluta_francuska(c);
	a.liwr = b.liwr;
	a.solid = b.solid;
	a.denar = b.denar;
	return in;
}
waluta_francuska& waluta_francuska::operator=(const waluta_francuska& a)
{
	liwr = a.liwr;
	solid = a.solid;
	denar = a.denar;
	return *this;
}
waluta_francuska operator+(const waluta_francuska& a, const waluta_francuska& b)
{
	waluta_francuska c;
	c.liwr = a.liwr + b.liwr;
	c.solid = a.solid + b.solid;
	c.denar = a.denar + b.denar;
	return c;
}
waluta_francuska operator-(const waluta_francuska& a, const waluta_francuska& b)
{
	waluta_francuska c;
	c.liwr = a.liwr - b.liwr;
	c.solid = a.solid - b.solid;
	c.denar = a.denar - b.denar;
	c.ukladanie();
	if (c.liwr < 0 || c.solid < 0 || c.denar < 0) c.liwr = c.denar = c.solid = 0;
	return c;
}
waluta_francuska operator*(const waluta_francuska& a, const int b)
{
	waluta_francuska c;
	c.liwr = a.liwr * b;
	c.solid = a.solid * b;
	c.denar = a.denar * b;
	c.ukladanie();
	return c;
}
waluta_francuska operator*(const int b, const waluta_francuska& a)
{
	waluta_francuska c;
	c.liwr = a.liwr * b;
	c.solid = a.solid * b;
	c.denar = a.denar * b;
	c.ukladanie();
	return c;
}
waluta_francuska& operator+=(waluta_francuska& a, const waluta_francuska& b)
{
	a = a + b;
	a.ukladanie();
	return a;
}
waluta_francuska& operator--(waluta_francuska& a)
{
	a.denar = a.denar - 1;
	a.ukladanie();
	return a;
}
waluta_francuska operator--(waluta_francuska& a, int b)
{
	waluta_francuska old(a.liwr, a.solid, a.denar--);
	return old;
}
double waluta_francuska::operator()()
{
	double b;
	b = denar + solid * 12 + liwr * 12 * 20;
	b = b / 240;
	return b;
}
int waluta_francuska::operator==(const waluta_francuska& a)
{
	if (liwr == a.liwr&&solid == a.solid&&denar == a.denar) return 1;
	return 0;
}
int waluta_francuska::operator>(const waluta_francuska&a)
{
	if (liwr > a.liwr)return 1;
	if (liwr == a.liwr&&solid > a.solid)return 1;
	if (liwr == a.liwr&&solid == a.solid&&denar > a.denar)return 1;
	return 0;
}