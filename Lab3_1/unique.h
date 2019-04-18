#pragma once

#include <iostream>
using namespace std;

template <class T>
class unique
{
	T* dane = nullptr;
public:
	unique(T* w)
	{
		cout << "Tworzenie obiektu unique" << endl;
		dane = w;
	}
	unique(){}
	~unique()
	{
		if (dane != nullptr)
		{
			cout << "Zwalnianie pamieci" << endl;
			delete dane;
		}
	}
	unique(const T&) = delete;
	unique& operator=(const T&) = delete;
	unique(unique&& w)
	{
		dane = w.dane;
		w.dane = nullptr;
	}
	unique& operator=(unique&& w)
	{
		if (this != &w)
		{
			delete dane;
			cout << "Zwalnianie pamieci" << endl;
			dane = w.dane;
			w.dane = nullptr;
		}
		return *this;
	}
	T* get() const
	{
		return dane;
	}
	T& operator*()
	{
		return *dane;
	}
	T* operator->()
	{
		return dane;
	}
};