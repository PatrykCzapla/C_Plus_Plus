#include "grupa.h"

ostream& operator<<(ostream& out, const Grupa_pilkarska& g)
{
	if (g.czyPusta())
		out << "Grupa " << g.nazwa << " pusta";
	else
	{
		out << "Grupa " << g.nazwa << " :" << endl << " ";
		for each (Druzyna d in g.druzyny)
		{
			cout << d << " ";
		}
		out << endl;
	}
	return out;
}

int Grupa_pilkarska::rozmiar() const
{
	return druzyny.size();
}

bool Grupa_pilkarska::czyPusta() const
{
	if (rozmiar() == 0)return true;
	else return false;
}

void Grupa_pilkarska::dodaj(Druzyna d)
{
	druzyny.insert(d);
}

void Grupa_pilkarska::usun(Druzyna d)
{
	auto it = druzyny.find(d);
	druzyny.erase(it);
}

bool Grupa_pilkarska::czy_jest_czescia(Grupa_pilkarska & gr) const
{
	auto it = search(druzyny.begin(), druzyny.end(), gr.druzyny.begin(), gr.druzyny.end(), [](Druzyna a, Druzyna b) {return a == b; });
	if (it == druzyny.end())return false;
	else return true;
}
