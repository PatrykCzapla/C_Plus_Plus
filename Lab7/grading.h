#pragma once

#include <iostream>
#include <string>
using namespace std;

enum firma {
	BRAK, Gliwickie_Centrum_Numizmatyczne, Polskie_Centrum_Gradingu,
	Numismatic_Guaranty_Corporation, Professional_Coin_Grading_Service
};

class grading
{
protected:
	int nota;
	firma* firma_gradingowe;
	double wsp_ceny;

public:
	grading();
	grading(int nota, firma centrum = firma::BRAK);
	grading(const grading& gr);

	~grading();

	grading& operator = (const grading& gr);

	friend ostream& operator<<(ostream& out, const grading& gr);
};