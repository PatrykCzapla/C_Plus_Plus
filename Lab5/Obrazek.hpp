#ifndef OBRAZEK_HPP
#define OBRAZEK_HPP

#include <iostream>



class Obrazek
{
private:
	// Ilo�� wierszy obrazka
	int wiersze;
	// Ilo�� kolumn obrazka
	int kolumny;
	// Wska�nik na dwuwymiarow� tablic�
	char** dane;
	char** Init(int w, int k);

public:
	// Etap 1
	Obrazek();
	Obrazek(int a, int b);
	Obrazek(int a, int b, const char* s);
	~Obrazek();
	void UstawZnak(char a);
	friend std::ostream& operator<<(std::ostream& out, const Obrazek& a);

	// Etap 2


	// Etap 3


};

#endif // !OBRAZEK_HPP
