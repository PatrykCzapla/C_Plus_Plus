#pragma once
#include <iostream> 
#include <string>
using namespace std;

class Przedmiot
{
protected:
	string nazwa;
	string opis;
public:
	Przedmiot(string _nazwa, string _opis);
	virtual ~Przedmiot() {};
	virtual void info(ostream&) const;
	friend ostream& operator<<(ostream&, const Przedmiot&);
};
