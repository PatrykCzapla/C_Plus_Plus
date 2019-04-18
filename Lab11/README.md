Zadanie 11b (8 punktów)
W trakcie wojny rzymsko-żydowskiej Józef Flawiusz został wraz z grupą żydowskich powstańców otoczony przez Rzymian w jaskini. Woląc samobójstwo od pojmania, powstańcy zdecydowali się utworzyć krąg i zabijać co trzecią osobę, aż nikt nie zostanie przy życiu. Flawiusz nie chciał się zdecydować na taką nonsensowną śmierć i szybko wyliczył gdzie on i jego przyjaciel powinni stanąć w kręgu, aby uniknąć śmierci.
Problem Józefa Flawiusza (permutacja Józefa Flawiusza) jako problem teoretyczny w matematyce i informatyce - w okręgu umieszczonych jest n obiektów, następnie eliminowany jest co n-ty obiekt, aż pozostanie tylko jeden. Problem polega na wskazaniu tego obiektu, który pozostanie.
Końcowym celem zadania jest utworzenie szablonu klasy cyklicznej list dwukierunkowej oraz wykorzystanie jej w rozwiązaniu tzw. problemu Józefa Flawiusza (wraz z obsługą odczytu/zapisu plikowego). Funkcja main została przygotowana w całości (patrz plik main.cpp) i nie należy jej modyfikować, poza odkomentowywaniem kolejnych części zadania.
Początkowa definicja klasy cyklicznej listy dwukierunkowej (LList) oraz klasy elementu listy (ListNode) znajduje się w plikach LList.h, LListNode.h, LList.cpp oraz LListNode.cpp. Wszystkie metody szablonów klas powinny być implementowane poza definicją klasy.
Etap1 (2,5 pkt)
W klasie listy należy dodać metodę void insertEnd(int _data) oraz metodę void insertSorted(int _data). Metoda insertEnd wstawia nowy element (tworzony na podstawie danych _data) na końcu listy. Metod insertSorted wstawia nowy element (tworzony na podstawie danych _data) na takiej pozycji, aby lista w każdym momencie była posortowana (rosnąco).
UWAGA! Początkowo możliwe jest realizowanie zadania w wersji alternatywnej (zmienną bool wersja_alternatywna na początku funkcji main() trzeba ustawić na true), która umożliwia pominiecie implementacji metody insertSorted (etap 1 jest wtedy za 1 pkt). W wersji tej wszystkie dane będą już automatycznie posortowane. Można kontynuować wykonywanie zadania realizując pozostałe etapy, zaś implantację pominiętej metody insertSorted wykonać na końcu zadania.
Etap2 (2 pkt)
UWAGA! Przed rozpoczęciem drugiego etapu zakomnetuj w funkcji main() Etap 0 oraz Etap 1. W drugim etapie zadania należy przekształcić klasę cyklicznej listy dwukierunkowej (LList) oraz klasę elementu listy (ListNode) do postaci szablonów (odpowiednio w plikach LList.h oraz ListNode.h).
Etap3 (0 pkt)
Należy dostosować klasę Buntownik do współpracy z szablonem listy (możliwość sortowania buntowników po indeksach). Tylko na tym etapie wolno dokonać modyfikacji w klasie Buntownik.
Etap4 (1 pkt)
Czwarty etap polega na rozszerzeniu szablonu listy o metodę void fromFile(string file_name), która realizuje dodawanie do listy elementów zapisanych w pliku tekstowym file_name (dodajemy w sposób posortowany).
Etap5 (1 pkt)
Należy rozszerzyć szablon listy o metodę void delete_evry_n(int n), która usuwa kolejno z listy co n-ty element (zaczynając odliczanie od pierwszego elementu listy). Usuwanie trwa do momentu, w którym w liście pozostanie jeden element (informacja o usuwanych elementach wypisywane są na ekran). Obecność takiej metody pozwoli na bezpośrednie rozwiązanie tzw. problemu Józefa Flawiusza.
Etap6 (1 pkt)
Szósty etap polega na rozszerzeniu szablonu listy o metodę void toFile(string file_name), która realizuje zapis do pliku tekstowego file_name zawartości listy (zapisuje w tej samej postaci, w jakiej zawartość listy wyświetlana jest na ekranie; jeśli plik istnieje jego zawartość jest nadpisywana).
Etap7 (0,5 pkt)
W ostatnim etapie należy wykonać specjalizację metody szablonu toFile dla typu Buntownik. Różnica w funkcjonalności polega na dopisywaniu zawartości listy na końcu istniejącego pliku. Zapis zawartości listy powinien być poprzedzony dodaniem linii z tekstem „Ocalal:”
Efekt poprawnego wykonania programu:
********************** Etap 0 (0 pkt) **********************
Lista jest pusta
Zawartosc listy:
54 15 81 41 18 45 42 32
********************** Etap 1 (2,5 pkt) **********************
Lista jest pusta
Zawartosc listy:
32 42 45 18 41 81 15 54
Lista jest pusta
Zawartosc listy:
15 18 32 41 42 45 54 81
********************** Etap 2 (2 pkt) **********************
Zawartosc listy:
21 32 45 81
Zawartosc listy:
Ala Ma kota pa
Zawartosc listy:
-3.21 0.7 2.5 3.333
********************** Etap 3 (0 pkt) **********************
Zawartosc listy:
Jan (idx: 1)
Filip (idx: 2)
Zenon (idx: 3)
Tomasz (idx: 4)
********************** Etap 4 (1 pkt) **********************
Zawartosc listy:
1 2 3 4 5 7 9
Zawartosc listy:
Jan (idx: 1)
Tomasz (idx: 2)
Karol (idx: 3)
Roman (idx: 4)
Gizon (idx: 5)
Edgard (idx: 6)
Robert (idx: 7)
Henryk (idx: 8)
Filip (idx: 9)
Teodor (idx: 10)
Maciej (idx: 11)
Mikolaj (idx: 12)
Pankracy (idx: 13)
Franciszek (idx: 14)
Bonifacy (idx: 15)
Zygmunt (idx: 16)
Adam (idx: 17)
Sebastian (idx: 18)
Lukasz (idx: 19)
Mateusz (idx: 20)
Antoni (idx: 21)
Kajtek (idx: 22)
Stanislaw (idx: 23)
Jozef (idx: 24)
Alan (idx: 25)
Marcel (idx: 26)
Jakub (idx: 27)
Rafal (idx: 28)
Marcin (idx: 29)
Krzysztof (idx: 30)
Andrzej (idx: 31)
Ksawery (idx: 32)
Igor (idx: 33)
Ignacy (idx: 34)
Pawel (idx: 35)
Tomasz (idx: 36)
Bonawentura (idx: 37)
Bogdan (idx: 38)
Czeslaw (idx: 39)
Dominik (idx: 40)
********************** Etap 5 (1 pkt) **********************
Niszczony jest: 2
Niszczony jest: 4
Niszczony jest: 7
Niszczony jest: 1
Niszczony jest: 5
Niszczony jest: 3
Zawartosc listy:
9
Niszczony jest: Robert (idx: 7)
Niszczony jest: Franciszek (idx: 14)
Niszczony jest: Antoni (idx: 21)
Niszczony jest: Rafal (idx: 28)
Niszczony jest: Pawel (idx: 35)
Niszczony jest: Tomasz (idx: 2)
Niszczony jest: Teodor (idx: 10)
Niszczony jest: Sebastian (idx: 18)
Niszczony jest: Marcel (idx: 26)
Niszczony jest: Ignacy (idx: 34)
Niszczony jest: Karol (idx: 3)
Niszczony jest: Mikolaj (idx: 12)
Niszczony jest: Kajtek (idx: 22)
Niszczony jest: Andrzej (idx: 31)
Niszczony jest: Dominik (idx: 40)
Niszczony jest: Maciej (idx: 11)
Niszczony jest: Stanislaw (idx: 23)
Niszczony jest: Igor (idx: 33)
Niszczony jest: Gizon (idx: 5)
Niszczony jest: Adam (idx: 17)
Niszczony jest: Krzysztof (idx: 30)
Niszczony jest: Roman (idx: 4)
Niszczony jest: Lukasz (idx: 19)
Niszczony jest: Tomasz (idx: 36)
Niszczony jest: Filip (idx: 9)
Niszczony jest: Jakub (idx: 27)
Niszczony jest: Edgard (idx: 6)
Niszczony jest: Alan (idx: 25)
Niszczony jest: Henryk (idx: 8)
Niszczony jest: Ksawery (idx: 32)
Niszczony jest: Zygmunt (idx: 16)
Niszczony jest: Jan (idx: 1)
Niszczony jest: Bogdan (idx: 38)
Niszczony jest: Bonawentura (idx: 37)
Niszczony jest: Czeslaw (idx: 39)
Niszczony jest: Bonifacy (idx: 15)
Niszczony jest: Marcin (idx: 29)
Niszczony jest: Pankracy (idx: 13)
Niszczony jest: Mateusz (idx: 20)
Zawartosc listy:
Jozef (idx: 24)
********************** Etap 6 (1 pkt) **********************
zapis do pliku: LiczbyPo.txt zakonczony!
zapis do pliku: BuntownicyPo.txt zakonczony!
********************** Etap 7 (0,5 pkt) **********************
Niszczony jest: Robert (idx: 7)
Niszczony jest: Franciszek (idx: 14)
Niszczony jest: Antoni (idx: 21)
Niszczony jest: Rafal (idx: 28)
Niszczony jest: Pawel (idx: 35)
Niszczony jest: Tomasz (idx: 2)
Niszczony jest: Teodor (idx: 10)
Niszczony jest: Sebastian (idx: 18)
Niszczony jest: Marcel (idx: 26)
Niszczony jest: Ignacy (idx: 34)
Niszczony jest: Karol (idx: 3)
Niszczony jest: Mikolaj (idx: 12)
Niszczony jest: Kajtek (idx: 22)
Niszczony jest: Andrzej (idx: 31)
Niszczony jest: Dominik (idx: 40)
Niszczony jest: Maciej (idx: 11)
Niszczony jest: Stanislaw (idx: 23)
Niszczony jest: Igor (idx: 33)
Niszczony jest: Gizon (idx: 5)
Niszczony jest: Adam (idx: 17)
Niszczony jest: Krzysztof (idx: 30)
Niszczony jest: Roman (idx: 4)
Niszczony jest: Lukasz (idx: 19)
Niszczony jest: Tomasz (idx: 36)
Niszczony jest: Filip (idx: 9)
Niszczony jest: Jakub (idx: 27)
Niszczony jest: Edgard (idx: 6)
Niszczony jest: Alan (idx: 25)
Niszczony jest: Henryk (idx: 8)
Niszczony jest: Ksawery (idx: 32)
Niszczony jest: Zygmunt (idx: 16)
Niszczony jest: Jan (idx: 1)
Niszczony jest: Bogdan (idx: 38)
Niszczony jest: Bonawentura (idx: 37)
Niszczony jest: Czeslaw (idx: 39)
Niszczony jest: Bonifacy (idx: 15)
Niszczony jest: Marcin (idx: 29)
Niszczony jest: Pankracy (idx: 13)
Niszczony jest: Mateusz (idx: 20)
zapis do pliku: Buntownicy.txt zakonczony!
Pliki LiczbyPo.txt oraz BuntownicyPo.txt
Zawartosc listy:
9
Ocalal:
Zawartosc listy:
Jozef (idx: 24)
Plik Buntownicy.txt po etapie 7
Jan 1
Teodor 10
Henryk 8
Krzysztof 24
Ignacy 34
Pawel 35
Dominik 40
Bonawentura 37
Bogdan 38
Czeslaw 39
Mateusz 20
Filip 9
Maciej 11
Tomasz 2
Karol 3
Roman 4
Antoni 21
Gizon 5
Edgard 6
Lukasz 19
Ksawery 32
Kajtek 22
Mikolaj 12
Stanislaw 23
Franciszek 14
Andrzej 31
Bonifacy 15
Tomasz 36
Zygmunt 16
Igor 33
Adam 17
Sebastian 18
Alan 25
Marcel 26
Robert 7
Rafal 28
Pankracy 13
Marcin 29
Jozef 30
Jakub 27
Ocalal:
Zawartosc listy:
Jozef (idx: 24)
