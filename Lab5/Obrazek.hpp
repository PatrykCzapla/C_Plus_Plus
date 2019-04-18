#ifndef OBRAZEK_HPP
#define OBRAZEK_HPP

#include <iostream>



class Obrazek
{
private:
	// Iloœæ wierszy obrazka
	int wiersze;
	// Iloœæ kolumn obrazka
	int kolumny;
	// WskaŸnik na dwuwymiarow¹ tablicê
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
