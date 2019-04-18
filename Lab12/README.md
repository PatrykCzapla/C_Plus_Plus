Laboratorium 12B (8pkt) STL
__________________________________________________________________________________
Tłem programu jest nowo powstający sklep z alkoholem realizowany za pomocą kontenera list. W
implementacji trzeba posługiwać się odpowiednimi iteratorami oraz funkcjami dostępnymi dla
kontenera.
Pliki nagłówkowe są przygotowane. Plik główny Main.cpp przygotowany jest w całości.
Etap 1 (1 pkt)
Należy przygotować klasę Alkohol oraz dziedziczące po niej Wino i Piwo.
Dla win zakładamy, że zawartość alkoholu zawsze wynosi 14 %.
Operator porównania zwraca true, gdy zgadza się nazwa i rodzaj trunku.
Metody pobierz_rodzaj() i pobierz_opakowanie() zwracają odpowiednie łańcuchy znakowe, np.
"wytrawne", "jasne", lub "butelkowe".
Operator wyjścia wraz z metodą wyprowadz_na_ekran() realizuje wypisanie odpowiedniej informacji
na konsolę, zgodnie z przykładowym wywołaniem przedstawionym niżej.
Etap 2 (1,5 pkt)
Drugi etap to klasa Zapasy, za pomocą której obsługiwany jest sklep. Wszystkie trunki
przechowywane są w liście wskaźników list<Alkohol*>. (Dlaczego wskaźniki a nie obiekty?)
Należy zaimplementować funkcję void dodaj_do_zapasow(Alkohol*) dodającą nowy trunek na
koniec listy.
operator<< wypisuje na ekran cały towar ze sklepu, jeśli lista jest pusta to wypisuje o tym informację.
Metoda double wartość_zapasow() zwraca wartość całego towaru.
Metoda Alkohol* sprzedaj() zwraca losowy trunek ze sklepu, jednocześnie usuwając go z
kontenera.
Etap 3 (1,5 pkt)
Tu trzeba wczytać dostawę win do sklepu z pliku binarnego o nazwie wina.bin. W pliku kolejno
zapisane są: nazwa na 100 bajtach, cena (double), rok (int) i rodzaj(int). Rodzaj w pliku zapisany jest
za pomocą wartości liczbowej odpowiedniego enum-a.
Metoda powinna dodać do towaru wszystkie wina z pliku.
Etap 4 (2 pkt)
Metoda list<Alkohol*> usun_duplikaty() zwraca listę zawierającą duplikaty trunków w sklepie. Ze
sklepu należy usunąć wszystkie duplikaty i przenieść je do zwracanej listy. Trunki porównujemy za
pomocą operatora porównania z pkt 1. Uwaga: nie możemy porównywać wina z piwem ☺.
Etap 5 (2 pkt)
Należy przygotować funktor: Drogie – określa, czy trunek jest wystarczająco drogi, przyjmując w
konstruktorze określoną cenę.
Funktor wykorzystujemy w przeciążonej metodzie list<Alkohol*> sprzedaj(double cena),
w której usuwamy z towaru trunki odpowiednio drogie za pomocą metody remove_if, natomiast
metoda zwraca listę, zawierającą drogie trunki.
Przykładowe wywołanie:
*********************** ETAP 1 (1 pkt) ***********************
nr. 1: Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2013, cena 42.9 zl
nr. 2: Wino Tavernello Rosso Amabile, polslodkie, rocznik 2015, cena 23.9 zl
nr. 3: Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2000, cena 66.99 zl
Wina 1 i 3 sa takie same
nr. 1: Piwo Oud Beersel, jasne, 5% , butelkowe, cena 35 zl
nr. 2: Piwo Deer Bear, niefiltrowane, 9% , butelkowe, cena 21 zl
nr. 3: Piwo Oud Beersel, jasne, 5% , w puszce, cena 35 zl
Piwa 1 i 3 sa takie same
*********************** ETAP 2 (1.5 pkt) ***********************
Laboratorium 12B (8pkt) STL
__________________________________________________________________________________
Brak towaru
Pierwsza dostawa towaru:
1. Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2013, cena 42.9 zl
2. Piwo Oud Beersel, jasne, 5% , butelkowe, cena 35 zl
3. Piwo Deer Bear, niefiltrowane, 9% , butelkowe, cena 21 zl
4. Wino Tavernello Rosso Amabile, polslodkie, rocznik 2015, cena 23.9 zl
5. Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2000, cena 66.99 zl
6. Piwo Oud Beersel, jasne, 5% , w puszce, cena 35 zl
Wartosc towaru w sklepie: 224.79 zl
Losowo wybrana bytelka do wzniesienia toastu na otwarcie sklepu:
Piwo Deer Bear, niefiltrowane, 9% , butelkowe, cena 21 zl
W sklepie pozostalo:
1. Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2013, cena 42.9 zl
2. Piwo Oud Beersel, jasne, 5% , butelkowe, cena 35 zl
3. Wino Tavernello Rosso Amabile, polslodkie, rocznik 2015, cena 23.9 zl
4. Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2000, cena 66.99 zl
5. Piwo Oud Beersel, jasne, 5% , w puszce, cena 35 zl
Wartosc towaru: 203.79 zl
*********************** ETAP 3 (1,5 pkt) ***********************
Dostawa win do sklepu:
1. Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2013, cena 42.9 zl
2. Piwo Oud Beersel, jasne, 5% , butelkowe, cena 35 zl
3. Wino Tavernello Rosso Amabile, polslodkie, rocznik 2015, cena 23.9 zl
4. Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2000, cena 66.99 zl
5. Piwo Oud Beersel, jasne, 5% , w puszce, cena 35 zl
6. Wino Carlos Serres Crianza DOC Rioja, slodkie, rocznik 1999, cena 50.5 zl
7. Wino Tavernello Rosso Amabile, polwytrawne, rocznik 2008, cena 24.6 zl
8. Wino Elegido Tempranillo, polslodkie, rocznik 1997, cena 33.2 zl
9. Wino Plum Red Sweet, wytrawne, rocznik 2018, cena 33.7 zl
10. Wino Sensas Sauvignon Blanc, polwytrawne, rocznik 1972, cena 17.3 zl
11. Wino Sensas Sauvignon Blanc, slodkie, rocznik 2007, cena 22.5 zl
12. Wino Haut Marin Gros Manseng Blanc, wytrawne, rocznik 1980, cena 34.9 zl
13. Wino Sancerre Domaine Curot, wytrawne, rocznik 2016, cena 50.6 zl
14. Wino Sancerre Domaine Curot, slodkie, rocznik 1993, cena 51.5 zl
15. Wino Feudo Principi di Butera Nero dAvola, slodkie, rocznik 2006, cena 26.6 zl
16. Wino Vinho Verde Adega Braga Loureiro, polwytrawne, rocznik 1985, cena 38 zl
17. Wino Sancerre Domaine Curot, wytrawne, rocznik 2005, cena 48.1 zl
18. Wino Sancerre Domaine Curot, slodkie, rocznik 1981, cena 49.5 zl
19. Wino Dinastia Vivanco Crianza, wytrawne, rocznik 2014, cena 62.8 zl
20. Wino Feudo Principi di Butera Nero dAvola, polwytrawne, rocznik 2001, cena 15.4 zl
21. Wino Dinastia Vivanco Crianza, polslodkie, rocznik 1987, cena 20.2 zl
22. Wino Vinho Verde Adega Braga Loureiro, slodkie, rocznik 2000, cena 26.1 zl
23. Wino Carlos Serres Crianza DOC Rioja, polslodkie, rocznik 1997, cena 34.6 zl
24. Wino Carlos Serres Crianza DOC Rioja, slodkie, rocznik 2000, cena 66.99 zl
25. Wino Feudo Principi di Butera Nero dAvola, slodkie, rocznik 2006, cena 26.6 zl
26. Wino Vinho Verde Adega Braga Loureiro, polwytrawne, rocznik 1985, cena 38 zl
Wartosc towaru: 975.48 zl
*********************** ETAP 4 (2.0 pkt) ***********************
Wlasciciel otwiera filie swojego sklepu i przenosi tam wszystkie duplikaty trunkow.
Duplikaty:
Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2000, cena 66.99 zl
Piwo Oud Beersel, jasne, 5% , w puszce, cena 35 zl
Wino Carlos Serres Crianza DOC Rioja, slodkie, rocznik 2000, cena 66.99 zl
Wino Sancerre Domaine Curot, wytrawne, rocznik 2005, cena 48.1 zl
Wino Sancerre Domaine Curot, slodkie, rocznik 1981, cena 49.5 zl
Wino Feudo Principi di Butera Nero dAvola, slodkie, rocznik 2006, cena 26.6 zl
Wino Vinho Verde Adega Braga Loureiro, polwytrawne, rocznik 1985, cena 38 zl
Pozostaly towar:
1. Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2013, cena 42.9 zl
2. Piwo Oud Beersel, jasne, 5% , butelkowe, cena 35 zl
3. Wino Tavernello Rosso Amabile, polslodkie, rocznik 2015, cena 23.9 zl
4. Wino Carlos Serres Crianza DOC Rioja, slodkie, rocznik 1999, cena 50.5 zl
5. Wino Tavernello Rosso Amabile, polwytrawne, rocznik 2008, cena 24.6 zl
6. Wino Elegido Tempranillo, polslodkie, rocznik 1997, cena 33.2 zl
7. Wino Plum Red Sweet, wytrawne, rocznik 2018, cena 33.7 zl
8. Wino Sensas Sauvignon Blanc, polwytrawne, rocznik 1972, cena 17.3 zl
9. Wino Sensas Sauvignon Blanc, slodkie, rocznik 2007, cena 22.5 zl
10. Wino Haut Marin Gros Manseng Blanc, wytrawne, rocznik 1980, cena 34.9 zl
11. Wino Sancerre Domaine Curot, wytrawne, rocznik 2016, cena 50.6 zl
12. Wino Sancerre Domaine Curot, slodkie, rocznik 1993, cena 51.5 zl
13. Wino Feudo Principi di Butera Nero dAvola, slodkie, rocznik 2006, cena 26.6 zl
14. Wino Vinho Verde Adega Braga Loureiro, polwytrawne, rocznik 1985, cena 38 zl
15. Wino Dinastia Vivanco Crianza, wytrawne, rocznik 2014, cena 62.8 zl
16. Wino Feudo Principi di Butera Nero dAvola, polwytrawne, rocznik 2001, cena 15.4 zl
17. Wino Dinastia Vivanco Crianza, polslodkie, rocznik 1987, cena 20.2 zl
18. Wino Vinho Verde Adega Braga Loureiro, slodkie, rocznik 2000, cena 26.1 zl
19. Wino Carlos Serres Crianza DOC Rioja, polslodkie, rocznik 1997, cena 34.6 zl
Laboratorium 12B (8pkt) STL
__________________________________________________________________________________
Wartosc towaru po usunieciu duplikatow: 644.3 zl
*********************** ETAP 5 (2.0 pkt) ***********************
Pierwszy klient i od razu kupuje to co najlepsze.
Towar po sprzedazy najdrozszych:
1. Wino Tavernello Rosso Amabile, polslodkie, rocznik 2015, cena 23.9 zl
2. Wino Tavernello Rosso Amabile, polwytrawne, rocznik 2008, cena 24.6 zl
3. Wino Sensas Sauvignon Blanc, polwytrawne, rocznik 1972, cena 17.3 zl
4. Wino Sensas Sauvignon Blanc, slodkie, rocznik 2007, cena 22.5 zl
5. Wino Feudo Principi di Butera Nero dAvola, slodkie, rocznik 2006, cena 26.6 zl
6. Wino Feudo Principi di Butera Nero dAvola, polwytrawne, rocznik 2001, cena 15.4 zl
7. Wino Dinastia Vivanco Crianza, polslodkie, rocznik 1987, cena 20.2 zl
8. Wino Vinho Verde Adega Braga Loureiro, slodkie, rocznik 2000, cena 26.1 zl
Wartosc towaru: 176.6 zl
Lista sprzedanego towaru:
Wino Carlos Serres Crianza DOC Rioja, polslodkie, rocznik 1997, cena 34.6 zl
Wino Dinastia Vivanco Crianza, wytrawne, rocznik 2014, cena 62.8 zl
Wino Vinho Verde Adega Braga Loureiro, polwytrawne, rocznik 1985, cena 38 zl
Wino Sancerre Domaine Curot, slodkie, rocznik 1993, cena 51.5 zl
Wino Sancerre Domaine Curot, wytrawne, rocznik 2016, cena 50.6 zl
Wino Haut Marin Gros Manseng Blanc, wytrawne, rocznik 1980, cena 34.9 zl
Wino Plum Red Sweet, wytrawne, rocznik 2018, cena 33.7 zl
Wino Elegido Tempranillo, polslodkie, rocznik 1997, cena 33.2 zl
Wino Carlos Serres Crianza DOC Rioja, slodkie, rocznik 1999, cena 50.5 zl
Piwo Oud Beersel, jasne, 5% , butelkowe, cena 35 zl
Wino Carlos Serres Crianza DOC Rioja, wytrawne, rocznik 2013, cena 42.9 zl
Press any key to continue . . .
