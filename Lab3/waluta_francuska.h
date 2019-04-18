#pragma once
#include <iostream>
using namespace std;

class waluta_francuska
{
	int liwr;
	int solid;
	int denar;
	void ukladanie();
public:
	waluta_francuska();
	explicit waluta_francuska(int a, int b, int c);
	explicit waluta_francuska(double a);
	waluta_francuska& operator=(const waluta_francuska& a);
	double operator()();
	int operator==(const waluta_francuska& a);
	int operator>(const waluta_francuska&a);
	friend ostream& operator<<(ostream& out, const waluta_francuska& a);
	friend istream& operator>>(istream& in, waluta_francuska& a);
	friend waluta_francuska operator+(const waluta_francuska& a, const waluta_francuska& b);
	friend waluta_francuska& operator+=(waluta_francuska& a, const waluta_francuska& b);
	friend waluta_francuska operator-(const waluta_francuska& a, const waluta_francuska& b);
	friend waluta_francuska operator*(const waluta_francuska& a, const int b);
	friend waluta_francuska operator*(const int b, const waluta_francuska& a);
	friend waluta_francuska& operator--(waluta_francuska& a);
	friend waluta_francuska operator--(waluta_francuska& a, int b);
	
	
};