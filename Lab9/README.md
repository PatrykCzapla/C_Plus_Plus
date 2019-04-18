Zadanie 9B (8 pkt)
Zadanie polega na implementacji klas odpowiedzialnych za produkowanie samolotów na podstawie
istniejących wersji prototypowych. Każdy z 3 rodzajów samolotów (pasażerski, transportowy i
wyczynowy) zawiera jeden z 3 możliwych typów silników (spalinowy, elektryczny lub odrzutowy).
Osiągi samolotu zależą zarówno od parametrów silnika jak i samolotu.
Informacje wypisywane na konsole powinny zgadzać się z informacjami z przykładowego wyjścia
programu (plik Wyniki 9B.pdf).
Funkcja main zawarta w pliku lab9b.cpp jest już w pełni zaimplementowania i nie można jej
modyfikować z wyjątkiem odkomentowania kolejnych etapów zadania.
Etap 1 (1.5 pkt)
W pliku Silnik.hpp znajduje się szkielet abstrakcyjnej klasy bazowej silnika. Należy zaimplementować
konstruktor ustawiający wartości pól w klasie, operator strumienia << oraz wszystkie metody
pobierające wartości pól potrzebne do poprawnego działania pierwszego etapu w funkcji main.
 Metoda ObliczPrzyspieszenie powinna być abstrakcyjna, inna dla każdego rodzaju silnika.
Operuje ona na liczbach typu float, i przyjmuje parametry: waga oraz współczynnik mocy, i
zwraca obliczone przyspieszenie.
 Metoda ObliczPredkoscMaksymalna działa tak samo w każdej klasie pochodnej. Również
operuje na liczbach typu float, przyjmuje opływowość oraz współczynnik mocy, oraz zwraca
wartość obliczoną według wzoru:
0.1 ∗ 𝑜𝑝𝑙𝑦𝑤𝑜𝑤𝑜𝑠𝑐 ∗ 𝑚𝑜𝑐 ∗ 𝑤𝑠𝑝𝑜𝑙𝑐𝑧𝑦𝑛𝑛𝑖𝑘𝑀𝑜𝑐𝑦 + 300
 W operatorze << należy wykorzystać zaimplementowaną przez siebie metodę
ZwrocInformacje.
Należy również zaimplementować klasę SilnikSpalinowy dziedziczącą po klasie Silnik.
 Silnik spalinowy w konstruktorze przyjmuje moc, ma wagę równą 200 oraz koszt produkcji
równy 11 * moc.
 Przyspieszenie silnika wyliczane jest według wzoru:
0.05 ∗ 𝑤𝑎𝑔𝑎
􀶥𝑚𝑜𝑐 ∗ 𝑤𝑠𝑝𝑜𝑙𝑐𝑧𝑦𝑛𝑛𝑖𝑘𝑀𝑜𝑐𝑦
Etap 2 (1 pkt)
Należy zaimplementować pozostałe klasy silników używane w drugim etapie zadania. Wszystkie silniki
w konstruktorze przyjmują moc.
 SilnikElektryczny ma wagę 140, i koszt produkcji równy 14 * moc. Przyspieszenie wyraża
się wzorem:
0.5 ∗ waga
𝑚𝑜𝑐 ∗ 𝑤𝑠𝑝𝑜𝑙𝑐𝑧𝑦𝑛𝑛𝑖𝑘𝑀𝑜𝑐𝑦
 SilnikOdrzutowy ma wagę 1100, koszt produkcji równy 16 * moc, oraz przyspieszenie
wyznaczane według wzoru:
100 ∗ waga
(𝑚𝑜𝑐 ∗ 𝑤𝑠𝑝𝑜𝑙𝑐𝑧𝑦𝑛𝑛𝑖𝑘𝑀𝑜𝑐𝑦)􀬶
Etap 3 (1 pkt)
We wszystkich klasach silnika należy zaimplementować metodę Replikuj która dynamicznie utworzy
identyczną kopię obiektu takiego samego typu.
W pliku FabrykaSamolotow.hpp znajduje się definicja klasy odpowiedzialnej za produkcję samolotów.
Należy zaimplementować metodę Produkuj przyjmującą referencję na obiekt typu Silnik.
W pierwszej kolejności metoda powinna sprawdzić czy koszt produkcji silnika jest nie większy od ilości
dostępnych środków (pole srodkiDoProdukcji klasy FabrykaSamolotow). W przypadku
niewystarczających środków należy rzucić standardowym wyjątkiem std::runtime_error z
wiadomością "Niewystarczajace srodki do produkcji silnika".
W przeciwnym wypadku należy zmniejszyć środki o koszt produkcji oraz utworzyć kopię przekazanego
obiektu poprzez wywołanie metody Replikuj klasy Silnik.
Etap 4 (3 pkt, po 1 za każdą klasę)
W pliku Samolot.hpp znajduje się szkielet klasy bazowej wszystkich samolotów.
Należy zaimplementować brakujące elementy tej klasy:
 Destruktor.
 Konstruktor ustawiający wszystkie pola.
Dodatkowo należy zaimplementować wszystkie samoloty dziedziczące po tej klasie bazowej:
SamolotPasazerski:
 Klasa ta ma dodatkowo pole typu bool informujące o tym, czy włączone jest ogrzewanie foteli
(domyślnie wyłączone).
 Należy w metodzie ZwrocInformacje oprócz podstawowych informacji z klasy bazowej należy
wypisywać typ samolotu oraz informację o stanie podgrzewania (włączone, wyłączone),
zgodnie z przykładowym wyjściem programu.
 Dodać metodę UstawPodgrzewanieSiedzen przyjmującą wartość bool mówiącą czy
ogrzewanie jest włączone.
 Ogrzewanie wpływa na moc silnika: przy włączonym współczynnik mocy równy jest 0.9,
natomiast przy wyłączonym 1 (należy nadpisać odpowiednią metodę).
SamolotTransportowy:
 Dodatkowe pole typu float informujące o ilości towaru w luku (domyślnie 0).
 W metodzie ZwrocInformacje oprócz podstawowych informacji należy dodać typ samolotu
oraz zawartość luku (zgodnie z wyjściem).
 Dodać metodę UstawIloscTowaru ustawiającą pole dotyczące ilości towaru w luku.
 Dodatkowe obciążenie wpływa na wagę samolotu, więc należy nadpisać odpowiednią metodę
klasy bazowej.
SamolotWyczynowy:
 Posiada pole typu bool informujące o tym, czy otwarte są dodatkowe klapy zwiększające opór
są otwarte (domyślnie są zamknięte).
 W metodzie ZwrocInformacje podobnie jak w poprzednich klasach należy dodać informacje
o typie samolotu oraz stanie klap (zgodnie z wyjściem).
 Metoda UstawCzyKlapyOtwarte modyfikuje prywatne pole dotyczące stanu klap.
 Klapy wpływają na opływowość samolotu. Jeśli są złożone, to opływowość wynosi 0.9 bazowej
opływowości, natomiast w przeciwnym wypadku wartość ta nie jest zmieniona.
Etap 5 (1.5 pkt)
We wszystkich klasach samolotów należy nadpisać metodę Replikuj dynamicznie tworzącą kopię
obecnego obiektu.
Wewnątrz tej metody, w pierwszej kolejności należy utworzyć kopię silnika. W tym celu wystarczy
przekazać referencję na swój silnik do metody Produkuj otrzymanej jako parametr fabryki. Mając kopię
silnika wystarczy tak samo jak w jego przypadku ręcznie utworzyć nowy obiekt odpowiedniego typu
samolotu. Nowy obiekt powinien być utworzony na podstawie bazowych parametrów obiektu
(przykładowo kopia samolotu transportowego tworzona jest z wagą bez silnika oraz bez dodatkowego
obciążenia towarem w luku obecnego obiektu. Podobnie w samolocie wyczynowym należy przekazać
opływowość przy zamkniętych klapach).
Dodatkowo podobnie jak w przypadku klasy Silnik należy zaimplementować metodę Produkuj klasy
FabrykaSamolotow przyjmującą referencję na obiekt typu Samolot i utworzy jego kopię. Na początku
należy sprawdzić czy koszt tworzenia całego samolotu jest nie większy niż dostępne środki. W
przeciwnym wypadku należy rzucić standardowym wyjątkiem std::runtime_error z wiadomością
"Niewystarczajace srodki do produkcji samolotu".
Jeśli powyższy warunek zostanie spełniony, to należy odjąć od dostępnych środków koszt produkcji
samego samolotu (koszt produkcji silnika zostanie odjęty przy kopiowaniu silnika wewnątrz samolotu),
a następnie należy utworzyć i zwrócić kopię samolotu utworzoną poprzez wywołanie metody Replikuj
na otrzymanym obiekcie przekazując jej jako parametr referencję na obecny obiekt fabryki.
