#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;
#include "druzyna.h"

ostream& operator<<(ostream& out, const Druzyna& d)
{
	out << "Reprezentacja: " << setw(12) << d.reprezentacja_kraju << ",";
	out << " pozycja: " << setw(3) << d.pozycja_w_rankingu << ",";
	out << " punkty: " << setw(4) << d.aktualna_liczna_punktow() << ",";
	out << " Z: " << setw(2) << d.zwyciestwa() << ",";
	out << " R: " << setw(2) << d.remisy() << ",";
	out << " P: " << setw(2) << d.przegrane() << ",";
	out << " Bramki: " << setw(2) << d.bramki().first << " : " << d.bramki().second;
	out << endl;
	return out;
}

bool operator<(const Druzyna & a, const Druzyna & b)
{
	return a.ilosc_punktow < b.ilosc_punktow;
}

bool operator>(const Druzyna & a, const Druzyna & b)
{
	return a.ilosc_punktow > b.ilosc_punktow;
}

bool operator==(const Druzyna & a, const Druzyna & b)
{
	return a.reprezentacja_kraju == b.reprezentacja_kraju;
}

int Druzyna::zwyciestwa() const
{
	return count_if(wyniki_meczow.begin(), wyniki_meczow.end(), [](pair<int, int> a) {return a.first > a.second; });
}

int Druzyna::remisy() const
{
	return count_if(wyniki_meczow.begin(), wyniki_meczow.end(), [](pair<int, int> a) {return a.first == a.second; });
}

int Druzyna::przegrane() const
{
	return count_if(wyniki_meczow.begin(), wyniki_meczow.end(), [](pair<int, int> a) {return a.first < a.second; });
}

pair<int, int> Druzyna::bramki() const
{
	int first = accumulate(wyniki_meczow.begin(), wyniki_meczow.end(), 0, [](int a, pair<int, int> b) {return a + b.first; });
	int second = accumulate(wyniki_meczow.begin(), wyniki_meczow.end(), 0, [](int a, pair<int, int> b) {return a + b.second; });
	return make_pair(first, second);
}

int Druzyna::aktualna_liczna_punktow() const
{
	vector<int> wk;
	auto it = back_inserter(wk);
	transform(wyniki_meczow.begin(), wyniki_meczow.end(), it, [](pair<int, int> a) {if (a.first > a.second)return 3; else if (a.first == a.second)return 1; else return 0; });
	vector<int>wk2;
	auto it2 = back_inserter(wk2);
	transform(rozegrane_mecze.begin(), rozegrane_mecze.end(), it2, [](pair<Druzyna, Rodzaj_meczu> a) {return (21 - a.first.pozycja_w_rankingu)*a.second; });
	int pk = inner_product(wk.begin(), wk.end(), wk2.begin(), 0);
	int w = zwyciestwa() + remisy() + przegrane();
	if (w == 0)return ilosc_punktow;
	return ilosc_punktow + pk / w;
}
