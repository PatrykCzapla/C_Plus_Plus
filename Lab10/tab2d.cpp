
#include "tab2d.h"



tab2d::tab2d()
{
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) tab[i][j] = 0;
}

double& tab2d::operator()(int i, int j)
{
	return tab[i][j];
}

double tab2d::maks() const
{
	double m = tab[0][0];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (tab[i][j] > m) m = tab[i][j];

	return m;
}

ostream& operator<<(ostream& out, const tab2d& t)
{
	for (int i = 0; i < t.M; i++)
	{
		for (int j = 0; j < t.N; j++) 	out << t.tab[i][j];
		cout << endl;
	}
	return out;
}

