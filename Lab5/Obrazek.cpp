#include "Obrazek.hpp"

char** Obrazek::Init(int w, int k)
{
	int i, j;
	wiersze = w;
	kolumny = k;
	if (w <= 0 || k <= 0)
	{
		wiersze = kolumny = 0;
		dane = nullptr;
		return nullptr;
	}
	char** a;
	a =new char*[w];
	if (!a)
	{
		wiersze = kolumny = 0;
		dane = nullptr;
		return nullptr;
	}
	for (i = 0; i < w; i++)
	{
		a[i] = new  char[k];
		if (!a[i])
		{
			for (j = 0; j < i; j++)
			{
				delete[] a[j];
				delete[] a;
			}
			wiersze = kolumny = 0;
			dane = nullptr;
			return nullptr;
		}
	}
	return a;
}

Obrazek::Obrazek()
{
	wiersze = kolumny = 0;
	dane = nullptr;
}
Obrazek::Obrazek(int a, int b)
{
	int i, j;
	wiersze = a;
	kolumny = b;
	char** s;
	s=Init(a, b);
	if (!s)
	{
		wiersze = kolumny = 0;
		dane = nullptr;
		return;
	}
	for (i = 0; i < wiersze; i++)
	{
		for (j = 0; j < kolumny; j++)
		{
			s[i][j] = ' ';
		}
	}
}
Obrazek::~Obrazek()
{
	int i;
	for (i = 0; i < wiersze; i++)
		delete[] dane[i];
	delete[] dane;		
}
Obrazek::Obrazek(int a, int b, const char* s)
{
	int size = strlen(s);
	int i, j, c=0;
	char**w = Init(a, b);
	if (!w)
	{
		wiersze = kolumny = 0;
		dane = nullptr;
		return;
	}
	if (size >= a + b)
	{
		wiersze = kolumny = 0;
		dane = nullptr;
		return;
	}
	wiersze = a;
	kolumny = b;
	for (i = 0; i < wiersze; i++)
	{
		for (j = 0; j < kolumny; j++)
		{
			w[i][j] = s[j + c];	
		}
		c += j;
	}
	dane = w;
}
void Obrazek::UstawZnak(char a)
{
	int i, j;
	for (i = 0; i < wiersze; i++)
	{
		for (j = 0; j < kolumny; j++)
		{
			dane[i][j] = a;
		}
	}
		
}
std::ostream& operator<<(std::ostream& out, const Obrazek& a)
{
	int i, j;
	for (i = 0; i < a.wiersze; i++)
	{
		for (j = 0; j < a.kolumny; j++)
		{
			out << a.dane[i][j];
		}
		out << std::endl;
	}
	return out;
}