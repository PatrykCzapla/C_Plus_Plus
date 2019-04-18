#pragma once
#include <iostream>
using namespace std;

class tab2d
{
	static const int M = 100;
	static const int N = 100;
	double tab[M][N];

public:
	tab2d();
	double& operator()(int i, int j);
	double maks() const;

	friend ostream& operator<<(ostream& out, const tab2d& t);
};





