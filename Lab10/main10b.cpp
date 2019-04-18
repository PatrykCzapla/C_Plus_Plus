
#include <iostream>
using namespace std;
#include <complex>
#include <ctime>
#include "function.h"
#include "algorytmy.h"
#include "tab2d.h"
#include "element.h"


int main()
{
	

	//cout << "  ---------------  ETAP 1a ---------------------------------------" << endl;
	//
	//double x = 2;

	////f(x)=4;
	//Function* f = new FConst(4.);
	//cout << "funkcja f(x)=4  :   f(x)=" << f->value(x) << " f'(x)=" << f->prim(x) << endl;

	//delete f;

	////h(x)=x;
	//Function* h = new FIdent();
	//cout << "funkcja h(x)=x  :   h(x)=" << h->value(x) << " h'(x)=" << h->prim(x) << endl;

	//delete h;

	////g(x)=x*x-3
	//Function* g = new FSub(new FProd(new FIdent(), new FIdent()), new FConst(3.));
	//	
	//
	//cout << "funkcja g(x)=x*x-3  :   g(x)=" << g->value(x) << " g'(x)=" << g->prim(x) << endl;
	//
	//delete g;
	//
	//system("pause");
	cout << "  ---------------  ETAP 1b ---------------------------------------" << endl;
	
	
	double x = 2;

	//f(x)=4;
	Function<>* f = new FConst<>(4.);
	cout << "funkcja f(x)=4  :   f(x)=" << f->value(x) << " f'(x)=" << f->prim(x) << endl;

	delete f;

	//h(x)=x;
	Function<double>* h = new FIdent<double>();
	cout << "funkcja h(x)=x  :   h(x)=" << h->value(x) << " h'(x)=" << h->prim(x) << endl;

	delete h;

	//g(x)=x*x-3
	Function<double>* g = new FSub<double>(new FProd<double>(new FIdent<double>(), new FIdent<double>()), new FConst<double>(3.));


	cout << "funkcja g(x)=x*x-3  :   g(x)=" << g->value(x) << " g'(x)=" << g->prim(x) << endl;

	delete g;
	
	

	cout << "  ---------------  ETAP 2 ---------------------------------------" << endl;

	
	double zera[] = { 3.,0.,1. };
	Function<double>* g1 = generuj_wielomian(zera, 3);		//g1(x)= (x-3)*x*(x-1)
	
	cout << "funkcja g1(x)=(x-3)*x*(x-1)  :   g1(x)=" << g1->value(x) << " g1'(x)=" << g1->prim(x) << endl;
	delete g1;
	
	//----------------------------------------------
	double zera2[] = { 6.,-5.,1.,7. };
	Function<>* g2 = generuj_wielomian(zera2, 4);			//g2(x) = (x-6)*(x-(-5))*(x-1)*(x-7)

	cout << "funkcja g2(x)= (x-6)*(x-(-5))*(x-1)*(x-7)  :   g2(x)=" << g2->value(x) << " g2'(x)=" << g2->prim(x) << endl;
	delete g2;

	//--------------------------------------------------

	complex<double> zera3[] = { complex<double>(1,2), complex<double>(3,4), complex<double>(5,6) };
	Function<complex<double>>* g3 = generuj_wielomian(zera3, 3);
	complex<double> x3 = complex<double>(3, -7);
	
	cout << "funkcja g3(x)   :   g3(x3)=" << g3->value(x3) << " g3'(x3)=" << g3->prim(x3) << endl;

	delete g3;
	system("pause");

	cout << "  ---------------  ETAP 3 ---------------------------------------" << endl;

	/*
	double zera5[] = { 6.,-5.,1.,7.,2 };
	Function<>* g5 = generuj_wielomian(zera5, 5);		
	
	int it;
	try
	{
		double z = pierwiastek(g5, 0.,it);
		cout << "pierwiastek z=" << z << endl;
		cout << "liczba iteacji it=" << it << endl;
	}
	catch (...)
	{
		cout << "nie znaleziono pierwiastka" << endl;
	}

	delete g5;
	//--------------------------------------------------------------
	
	complex<double> zera6[] = { complex<double>(1,2), complex<double>(3,4), complex<double>(5,6), complex<double>(7,8) };
	Function<complex<double>>* g6 = generuj_wielomian(zera6, 4);
	
	try
	{
		complex<double> z6 = pierwiastek(g6, complex<double>(0),it);
		cout << "pierwiastek z6=" << z6 << endl;
		cout << "liczba iteacji it=" << it << endl;
	}
	catch (...)
	{
		cout << "nie znaleziono pierwiastka" << endl;
	}

	
	delete g6;
	*/
	
	cout << "  ---------------  ETAP 4 ---------------------------------------" << endl;
	
	/*
	srand((unsigned)time(0));
	
	const int K = 8;
	complex<double> zera8[K];
	for (int i = 0; i < K; i++)
	{
		zera8[i] = complex<double>(-5 + rand() % 100, -5 + rand() % 100);
	}

	Function<complex<double>>* g8 = generuj_wielomian(zera8, K);
	
	const int N=50;
	//double q = -N/2+rand() % N;		//LOSOWY punkt startowy kwadratowego obszaru
	double q = -20;						//USTALONY punkt startowy kwadratowego obszaru

	tab2d<element, N, N> statystyka;
		
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++)
		{
			try
			{
				pierwiastek(g8, complex<double>(q + i, q + j), it);
				
			}
			catch (...)
			{
				// nawet jeœli brak zbie¿noœci interesuje nas liczba wykonanych iteracji				
			}
			statystyka(i, j) = element(it);
		}

	cout << "FRAKTAL NEWTONA:" << endl;
	cout << statystyka << endl;
	
	// skala kolorow u¿ytych w statystyce
	element::scale(statystyka.maks().get_color());

	delete g8;
	*/
}
