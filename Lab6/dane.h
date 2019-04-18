//-----------------------------------------------------------
// UWAGA: to GOTOWA klasa (nic tutaj nie zmieniamy) - obejrzyj
// 
// przechowuje tajne dane osobowe klientów banku
//-----------------------------------------------------------
#pragma once
   
#include <iostream>
using namespace std;

class dane 
{
	static const int M = 17;
	char imie[M];
	char nazwisko[M];
			
public:
	dane(const char* imie, const char* nazwisko);
	friend bool operator==(const dane& d1, const dane& d2);
	friend ostream& operator<<(ostream& out, const dane& d);	
};