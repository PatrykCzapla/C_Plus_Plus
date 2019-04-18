#include "TeamManager.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

const vector<char> characters = { '0','1','2','3','4','5','6','7','8','9',
'A','B','C','D','E','F', 'G','H','I','J','K', 'L','M','N','O','P',
'Q','R','S','T','U', 'V','W','X','Y','Z', 'a','b','c','d','e','f',
'g','h','i','j','k', 'l','m','n','o','p', 'q','r','s','t','u',
'v','w','x','y','z' };

void printPeople(std::ostream &stream, const vector<Employee>& people)
{
	std::ostream_iterator<Employee> it(stream, "\n");

	copy(people.begin(), people.end(), it);
	//wykorzystając powyższy iterator i funkcję copy, wypisz podany wektor na ekran.
}

pair<double, double> CalculateTotalAndAverageSalary(const vector<Employee>& wektor)
{
	double total = 0;
	int iter = 0;
	for_each(wektor.begin(), wektor.end(), [&total, &iter](const Employee& em) {iter++; total += em.GetSalary(); });
	pair<double, double> wynik(total, total / iter);
	return wynik;
}

string GenerateRandomString(int n)
{
	string s;
	s.resize(n);
	for_each(s.begin(), s.end(), [](char& a) {a = characters[rand() % (characters.size())]; });
	return s;
}


int main()
{
	srand(5555);

	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL
	//UWAGA: W całym zadaniu nie można jawnie nigdzie napisać żadnej pętli. Można wykorzystywać wyrażenia lambda i algorytmu z biblioteki STL

	cout << "---------------ETAP I------------------" << endl;

	//ETAP I
	//napisać metodę GenerateRandomString, która przyjmuje zadaną długość i na podstawie wektora characters zwraca losowo wygenerowanego stringa
	//podpowiedź wykorzystać generate_n
	cout << GenerateRandomString(10) << endl;
	cout << GenerateRandomString(7) << endl;
	cout << GenerateRandomString(5) << endl;
	cout << GenerateRandomString(3) << endl;
	cout << GenerateRandomString(1) << endl;


	cout << "---------------ETAP II------------------" << endl;

	//ETAP II
	//wektor people1 uzupełnić w następujący sposób
	//-imię pracownika jest losowe (wykorzystaj poprzedni punkt). Nieparzyste pozycje w wektorze mają długość imienia 5, parzyste 10 
	//wykorzystaj zmienną pomocniczą peopleCounter przekazując ją odpowiednio do wyrażenia lambda
	//-wiek pracownika jest równy 22
	//-pensja to zmienna losowa z przedziału [minSalary,maxSalary] 
	//podpowiedź wykorzystać generate
	//UWAGA: losowane wartości to liczby całkowite z rozkładem równomiernym
	//podpowiedź wykorzystać generate i odpowiednie wyrażenie lambda
	vector<Employee> people1(10);

	int peopleCounter = 0;

	const int minSalary = 5000;
	const int maxSalary = 15000;

	generate(people1.begin(), people1.end(), [&peopleCounter, minSalary, maxSalary]() {peopleCounter++;  return Employee(GenerateRandomString(peopleCounter % 2 ? 10 : 5), 22, minSalary + (rand() % (maxSalary - minSalary + 1))); });

	//Uzupełnij wnętrze metody printPeople, aby wypisać pracowników na ekran
	printPeople(cout, people1);

	//wektor people2 uzupełnić w następujący sposób
	//-imię pracownika jest losowe o długości 7
	//-wiek pracownika jest losowy z przedziału [minAge,maxAge]
	//-pensja pracownika jest losowa z przedziału [minSalary,maxSalary] 
	//UWAGA: losowane wartości to liczby całkowite z rozkładem równomiernym na zadanym przedziale

	vector<Employee> people2(10);
	const unsigned int minAge = 20;
	const unsigned int maxAge = 65;
	generate(people2.begin(), people2.end(), [minSalary, maxSalary,minAge,maxAge]() { return Employee(GenerateRandomString(7), minAge+(rand()%(maxAge-minAge+1)), minSalary + (rand() % (maxSalary - minSalary + 1))); });
	printPeople(cout, people2);


	cout << "---------------ETAP III------------------" << endl;

	//ETAP III
	//Do wektora people3 wstawić pracowników z wektora people1 podwyższając im pensję o salaryIncrease,
	//a z wektora people2 pracowników odmłodzonych o 10 lat, pod warunkiem że ich wiek nie zmniejszy się poniżej 20 lat.	
	//podpowiedź: wykorzystaj wartość zwróconą przez transform

	vector<Employee> people3(people1.size() + people2.size());
	const int salaryIncrease = 2000;
	const int ageDecrease = 10;
	auto it=transform(people1.begin(), people1.end(),people3.begin(), [salaryIncrease, people1](Employee em) {em.SetSalary(em.GetSalary() + salaryIncrease); return em; });
	transform(people2.begin(), people2.end(), it, [ageDecrease, people2](Employee em) {return Employee(em.GetName(),((em.GetAge()-10)<20)?em.GetAge():(em.GetAge()-10),em.GetSalary()); });
	printPeople(cout, people3);

	//Do wektora people4 na koniec wstawić pracowników z people1, którzy zarabiają mniej niż 10000 i są starsi niż 35 lat
	//oraz pracowników z people2, którzy zarabiają mniej niż 7000 i są starsi niż 25 lat
	//użyc tego samego wyrażenia lambda zapisanego do zmiennej, przekazując odpowiednie wartości.
	//podpowiedź: wykorzystaj wartość zwróconą przez copy_if
	//można wykorzystać std::back_inserter

	vector<Employee> people4;

	int salary = 10000;
	unsigned int age = 35;
	copy_if(people1.begin(), people1.end(),back_inserter(people4), [salary, age](Employee& em) {return((em.GetSalary() < salary)&&(em.GetAge() > age)) ; });

	//tutaj uzupełnić o kopiowanie z wektora people1

	salary = 7000;
	age = 25;
	copy_if(people2.begin(), people2.end(), back_inserter(people4), [salary, age](Employee& em) {return((em.GetSalary() < salary) && (em.GetAge() > age)); });
	//tutaj uzupełnić o kopiowanie z wektora people2

	printPeople(cout,people4);

	cout << "---------------ETAP IV------------------" << endl;

	//ETAP IV
	//Napisz funkcję CalculateTotalAndAverageSalary przyjmującą wektor pracowników i zwracającą dwie wartości:
	//całkowitą sumę zarobków w zespole oraz średnią zarobków.
	//Dla wektorów people1,people2,people3,people4 wywołać napisaną funkcję i wyświetlić wyniki

	double totalSalary = 0;
	double averageSalary = 0;

	pair<double, double> para;
	para = CalculateTotalAndAverageSalary(people1);
	//todo wywolanie funkcji dla people1
	cout << "1. Sum: " << para.first << " Average: " << para.second << endl;
	para = CalculateTotalAndAverageSalary(people2);
	//todo wywolanie funkcji dla people2
	cout << "2. Sum: " << para.first << " Average: " << para.second << endl;
	para = CalculateTotalAndAverageSalary(people3);
	//todo wywolanie funkcji dla people3
	cout << "3. Sum: " << para.first << " Average: " << para.second << endl;
	para = CalculateTotalAndAverageSalary(people4);
	//todo wywolanie funkcji dla people4
	cout << "4. Sum: " << para.first << " Average: " << para.second << endl;


	cout << "--------------SORTING----------------" << endl;

	//posortować wektor pracowników po imieniu. Uwaga wielkość litery nie powinna mieć znaczenia (podpowiedź: wykorzytaj tolower)
	


	
	
	sort(people1.begin(), people1.end(), operator>);
	sort(people2.begin(), people2.end(), operator>);
	sort(people3.begin(), people3.end(), operator>);
	sort(people4.begin(), people4.end(), operator>);

	printPeople(cout, people1);
	cout << endl;
	printPeople(cout, people2);
	cout << endl;
	printPeople(cout, people3);
	cout << endl;
	printPeople(cout, people4);
	cout << endl;
	cout << "--------------ETAP V----------------" << endl;

	//ETAP V
	//uzupełnić klasę TeamManager o publiczną metodę addTeam, która przyjmuje nazwę zadania oraz drużynę (wektor pracowników) odpowiedzialną za zadanie i tworzy odpowiedni wpis w kolekcji
	//w razie pomyślnego dodania wypisać "team for the task was added"
	//w razie istnienia już odpowiedzialnej drużyny dla danego zadania, wypisać na konsolę "team already exists for that task"

	TeamManager teamManager;


	//dodać metodę performLambdaOnTasksTeam do klasy TeamManager, przyjmującą nazwę zadania i wyrażenie lambda, 
	//które podniesie pensję pracowników o zadaną pensję i policzy liczbę pracowników starszych niż zadany wiek.
	//Ilość pracowników spełniających kryterium, ma być zapisana w zmiennej counter

	int counter = 0;
	unsigned int givenAge = 20;

	printPeople(cout,people1);
	
	//Tutaj wywołać funkcję performLambdaOnTasksTeam
	
	cout << "Number of people older than " << givenAge << ": " << counter << endl;

	printPeople(cout, teamManager.getTeam("Programming"));
	
	counter = 0;
	givenAge = 25;
	
	//Tutaj wywołać funkcję performLambdaOnTasksTeam
	
	cout << "Number of people older than " << givenAge << ": " << counter << endl;
	
	return 0;
}