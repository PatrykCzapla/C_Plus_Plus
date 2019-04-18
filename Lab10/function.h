#pragma once

// klasa bazowa dla: FIdent, FConst, FSub, FProd
template<class T=double>
class Function
{
public:
	virtual T value(T x) const =0;
	virtual T prim(T x) const =0;
	virtual ~Function() { /*cout << "Usuwam funkcje" << endl;*/ }
};


// tutaj uzupe³nij definicje klas pochodnych: FIdent, FConst, FSub, FProd - ETAP 1

template<class T=double>
class FConst :public Function<T>
{
	T stala=0;
public:
	FConst(T x) :stala(x) {};
	virtual T value(T x) const { return stala; }
	virtual T prim(T x) const {return 0;}
};

template<class T=double>
class FIdent :public Function<T>
{
public:
	virtual T value(T x) const { return x; }
	virtual T prim(T x) const { return 1.0; }
};

template<class T=double>
class FSub :public Function<T>
{
	Function<T>* a;
	Function<T>* b;
public:
	FSub(Function<T>* a=nullptr, Function<T>* b=nullptr) :a(a), b(b) {};
	virtual T value(T x) const {return a->value(x) - b->value(x); }
	virtual T prim(T x) const { return a->prim(x) - b->prim(x); }
};

template<class T=double>
class FProd :public Function<T>
{
	Function<T>* a;
	Function<T>* b;
public:
	FProd(Function<T>* a=nullptr, Function<T>* b=nullptr) :a(a), b(b) {};
	virtual T value(T x) const { return a->value(x) * b->value(x); }
	virtual T prim(T x) const { return a->prim(x)*b->value(x) + a->value(x)*b->prim(x); }
};






