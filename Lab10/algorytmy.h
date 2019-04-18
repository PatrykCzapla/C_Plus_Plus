#pragma once

#include <iostream>
using namespace std;
#include <cmath>


//------------------------------------------------

// zaimplementuj generuj_wielomian - ETAP 2
template<class T=double>
Function<T>* generuj_wielomian(T* a, int rozmiar)
{
	Function<T>* funkcja;	
	funkcja = new FProd<T>;
	if (funkcja == nullptr)return nullptr;
	FIdent<T> x;
	*funkcja = FProd<T>(&FSub<T>(&x, &FConst<T>(a[0])), &FSub<T>(&x, &FConst<T>(a[1])));
	for (int i = 2; i < rozmiar; i++)
	{
		*funkcja = FProd<T>(&FSub<T>(&x,&FConst<T>(a[i])), funkcja);
	}
	return funkcja;
}
// zaimplementuj pierwiastek - ETAP 3






