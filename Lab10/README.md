Zadanie 10b (8pkt) – wzorce funkcji / klas
Celem zadania jest wykonanie obliczeń numerycznych dla wielomianów, które definiujemy za
pomocą tablicy ich pierwiastków typu double lub complex.
Wielomian można „poskładać” z funkcji identycznościowej (klasa FIdent) oraz stałej (klasa
FConst) wykonując odpowiednie ich iloczyny (klasa FProd) oraz odejmowanie (klasa FSub).
Klasy te tworzą polimorficzną hierarchię, dla których Function jest abstrakcyjną klasą bazową.
Etap 1a (2 pkt)
W pliku function.h dana jest abstrakcyjna klasa bazowa Function
class Function
{
public:
virtual double value(double x) const =0; // wartość funkcji
virtual double prim(double x) const =0; // wartość pochodnej
virtual ~Function() { }
};
z której wyprowadź publiczne klasy pochodne: FConst, FIdent, FSub, FProd realizujące
odpowiednie działania narzucone w klasie bazowej, tj. wartość funkcji oraz wartość jej pochodnej.
· klasa FConst obsługuje funkcje stałe, np. f(x)=4.5
 konstruktor pobiera stałą, którą przechowuje w prywatnym polu klasy (typu double)
 metody value oraz prim obliczają odpowiednio wartość funkcji oraz jej pochodnej
· klasa FIdent obsługuje funkcję identycznościową f(x)=x
 klasa nie posiada żadnych pól
 metody value oraz prim obliczają odpowiednio wartość funkcji oraz jej pochodnej
· klasa FSub obsługuje różnicę dwóch funkcji
 konstruktor pobiera 2 wskaźniki klasy bazowej Function, które reprezentują
odejmowane 2 funkcje i wypełnia 2 prywatne pola wskaźnikowe klasy (pola typu
Function*)
 met. value oblicza wartość różnicy wykorzystując wywołania met. value dla jej
składników
 met. prim oblicza wartość pochodnej różnicy wykorzystując wywołania met. prim dla
jej składników
 destruktor zwalniający pola wskaźnikowe klasy
 klasa FProd obsługuje iloczyn dwóch funkcji;
 zaimplementuj w podobnej konwencji jak FSub
Obejrzyj zastosowanie w funkcji main.
Etap 1b (1 pkt)
Zakomentuj ETAP 1a i odkomentuj ETAP 1b.
„Przerób” klasy hierarchii Function na klasy szablonowe zależne od typu argumentu funkcji.
Zakładamy zastosowanie dla typu double (typ domyślny) oraz complex .
Etap 2 (1,5 pkt)
W pliku algorytmy.h napisz szablonową funkcję generuj_wielomian , która ( na podstawie
tablicy zer ) „składa” wielomian za pomocą klas FConst, FIdent, FSub, FProd.
Funkcja przyjmuje: tablicę zer oraz jej rozmiar (poprawne), zaś parametrem szablonowym jest typ
pierwiastków wielomianu.
Zwraca wskaźnik utworzonej funkcji wzorcowej (wielomianu):
 =  −  − 	⋯ − 	
Etap 3 (1,5 pkt)
W pliku algorytmy.h zaimplementuj szablon funkcji pierwiastek , realizującej algorytm
met. Newtona do rozwiązania równania f(x)=0
Parametrem szablonowym funkcji jest typ współczynników wielomianu ( dokładność obliczeń
EPS=1e-3 oraz liczba iteracji MAX_IT=100 są wewnętrznymi parametrami funkcji zainicjowane
podanymi wartościami).
Funkcja pierwiastek zwraca znalezione rozwiązanie (jeśli algorytm był zbieżny).
Parametry funkcji reprezentują: przekazana funkcja (wej), punkt startowy (wej), oraz wykonaną
liczbę iteracji (wyj).
Do obliczenia wartości bezwzględnej w algorytmie użyj funkcji abs.
Algorytm
Startujemy z x0 (wejściowy drugi parametr funkcji). Kolejne przybliżenia są dane wzorem:
( )
( ) k
k
k k f x
f x
x x
¢
= - +1
Wykonaj obliczenia ( maksymalnie MAX_IT=100 ) do momentu, gdy
· f (x ) EPS k £ , ( EPS=1e-3 )
· gdy przekroczono założoną liczbę iteracji MAX_ITER lub f ¢(xk ) < EPS , generuj
wyjątek rzucając komunikat „Brak zbieznosci”.
Etap 4 (2 pkt)
*** 1 pkt
Dana jest gotowa implementacja klasy tab2d, która dostarcza pewną podstawową funkcjonalność
tablicy 2-wymiarowej.
Należy „przerobić” klasę tab2d na klasę szablonową, której parametrami szablonowymi są: typ
elementów tablicy oraz dwa parametry „nie-typowe” określające wymiary tablicy ( liczba wierszy
oraz kolumn ). W definicji klasy szablonu pozostaw tylko prototypy, a resztę definiuj poza klasą.
Przewidujemy użycie szablonu tab2d dla typu element - to klasa, która przechowuje znak oraz
całkowitą wartość reprezentującą kolor znaku (w tym zadaniu, wartość koloru odpowiada liczbie
iteracji wykonanych przez funkcję pierwiastek).
*** 1 pkt
Metoda maks klasy tab2d powinna znajdować element o maksymalnej wartości koloru w tablicy
( w klasie element doimplementuj odpowiedni operator porównania )
Dla klasy element zaimplementuj brakujące składniki scale oraz get_color.
scale prezentuje skalę kolorów użytych w tablicy.
