#pragma once
#include <iostream>
#include<string>
using namespace std;

class Buntownik
{
	string imie;
	int idx;
public:
	Buntownik(string imie = "", int idx = 0) : imie(imie), idx(idx) {}
	friend ostream& operator<<(ostream& out, const Buntownik& b)
	{
		return out << b.imie << " (idx: " << b.idx << ")" << endl;
	}
	friend istream& operator>>(istream& in, Buntownik& b)
	{
		return in >> b.imie >> b.idx;
	}
	friend bool operator>(Buntownik a, Buntownik b)
	{
		if (a.idx > b.idx)return true;
		else return false;
	}
	friend bool operator<=(Buntownik a, Buntownik b)
	{
		if (a.idx <= b.idx)return true;
		else return false;
	}
};
