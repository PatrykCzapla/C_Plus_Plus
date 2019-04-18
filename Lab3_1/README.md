Dzisiejszym zadaniem jest implementacja jednego ze smart pointerów obecnych w C++: unique_ptr. 

Programiści używający nowych wersji C++(11 i nowsze) są mocno zachęcani do porzucenia standardowych wskaźników
i używania w ich miejsce smart pointerów. Pomagają one w automatycznym zarządzaniu pamięcią i są o wiele bezpieczniejsze.

Jednym ze smart pointerów jest właśnie unique_ptr. nie da się go skopiować, dzięki czemu w całym programie
jest dokładnie jeden wskaźnik który posiada obiekt znajdujący się na stercie. W momencie gdy unique_ptr jest zwalniany
(np był zmienną lokalną funkcji którą właśnie opuszczamy) zwalnia też on zasoby na które wskazuje.

UWAGA: implementacja powinna byc w pliku unique.h (i ewentualnie unique.cpp)

Etap 1 (1p)

Stwórz szablonową klasę unique. Jej zadaniem jest imitacja działania std::unique_ptr.
Powinno dać się go stworzyć przekazując do konstruktora zwykły wskaźnik, lub konstruktorem bezparametrowym (pusty wskaźnik). Zasoby na które wskazuje unique powinny być zwalniane gdy jest on niszczony.

Niech konstruktor wypisuje na konsolę: “Tworzenie obiektu unique”, a destruktor:
“Zwalnianie pamięci”. Oczywiście tylko wtedy gdy rzeczywiście jakaś pamięć jest zwalniana.

Etap 2 (2p)

Zastanów się nad tym, czy twoja klasa powinna mieć:
Operator przypisania, (jeśli tak to jaki?)
Konstruktor przyjmujący const & na unique
Konstruktor przenoszący

Stwórz te, które uznasz za prawidłowe, a pozostałe usuń (domyślne implementacje konstruktorów można usunąć tak:
	unique() = delete;

Pamiętaj, że niemożliwym musi być, aby dwa obiekty unique wskazywały na ten sam obszar pamięci.


Etap 3 (1p)

Zaimplementuj sposób dostępu do obiektu wskazywanego przez unique.
Wskazówka: operator->(), operator*(), oraz wersje const.
Przydatna może być funkcja analogiczna do std::unique_ptr::get().

Zaimplementuj:
Funkcję IsValid. Powinna ona sprawdzić, czy przekazany w parametrze unique wskazuje na prawidłowy obszar pamięci
i zwrócić wartość typu bool. Po wyjściu z funkcji obiekt przekazany w parametrze MUSI być dalej funkcjonalny.

Etap 4 (1p)
Napisz funkcję Bigger, która przyjmuje dwa obiekty unique. Jeśli jeden z nich jest większy od drugiego to jest on zwracany,
a drugi obiekt jest usuwany. Jeśli są one równe to żaden z obiektów nie jest usuwany, a zwracany jest pusty obiekt unique.
