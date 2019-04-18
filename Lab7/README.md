Laboratorium 7B (6pkt)
Klasy w zadaniu opisują kolekcję monet. Funkcja main jest już gotowa i nie wolno jej modyfikować.
Kolejne etapy zadania:
Etap 1 (2 pkt)
Klasa grading opisuje noty wystawiane przez różne firmy gradingowe. W typie wyliczeniowym mamy do dyspozycji cztery firmy o różnej renomie oraz możliwość wystawienia noty bez firmowej certyfikacji. Nota wystawiona przez Polskie_Centrum_Gradingu oraz Gliwickie_Centrum_Numizmatyczne zwiększa wartość ocenianej monety 1.25 razy (wsp_ceny = 1.25). Nota wystawiona przez Professional_Coin_Grading_Service oraz Numismatic_Guaranty_Corporation zwiększa wartość ocenianej monety 1.5 raza (wsp_ceny = 1.5). Nota bez certyfikacji nie zmienia wartości (wsp_ceny = 1).
Należy zaimplementować:
- konstruktor bezparametrowy – nota = 0, wsp_ceny = 1, centrum_gradingowe = nullptr.
- konstruktor przyjmujący notę i firmę gradingową ustawioną domyślnie na BRAK. Ustawia notę, w zależności od podanej firmy współczynnik ceny, oraz dynamicznie alokuje odpowiednią firmę.
- destruktor
- konstruktor kopiujący
- operator przypisania
- operator wyjścia << wypisujący na konsoli informację o gradingu w postaci: firma jeśli jest (skrót), stan, nota np.:
stan obiegowy, nota: 0 – dla not mniejszych niż 45
PCG, stan okolomenniczy AU 50 – dla not mniejszych niż 60
stan menniczy MS 66 – dla not mniejszych niż 70
PCGS, stan UNC 70 – dla not równych 70
Etap 2 (2,5 pkt)
Klasa moneta dziedzicząca po grading. Należy zaimplementować konstruktory, destruktor, operatory przypisania i wyjścia – należy wykorzystać operator z klasy bazowej (format wyświetlanej informacji w wynikach).
Nominał, cena, rok wybicia monety oraz grading podawane są w konstruktorach.
przewidywana_wartosc to tablica przechowująca przewidywaną wartość monety w kolejnych latach. Wyliczana jest w metodzie void oblicz_wartosc(int ile_lat = 0); Bieżąca wartość (ile_lat = 0) wyliczana jest na podstawie ceny pomnożonej przez wsp_ceny. W kolejnym roku wartość jest o 5% większa niż w poprzednim itd. Ilość wyliczanych lat podawane jest w parametrze metody. Przy konstrukcji obiektu wyliczana jest tylko bieżąca wartość. void wypisz_przewidywana_wartosc(); wyświetla tablicę z przewidywaną wartością monety w kolejnych latach (podając najpierw info o monecie) w postaci:
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Przewidywana wartosc w kolejnych 5 latach:
0: 3450
1: 3622.5
2: 3803.63
3: 3993.81
4: 4193.5
5: 4403.17
Etap 3 (1,5 pkt)
W tym etapie mamy tablicę monet. Należy przygotować funkcje pozwalające sortować tą tablicę według dwóch kryteriów: cmp_nota (wg noty gradingu), oraz cmp_wartosc (w pierwszej kolejności decyduje aktualna wartość, w drugiej nota).
W pliku wykonywalnym należy zaimplementować funkcję sortującą przyjmującą tablicę monet, ilość elementów tablicy, oraz kryterium sortowania, które będzie trzecim parametrem reprezentującym adres funkcji porównującej o nagłówku postaci: bool cmp(const moneta&, const moneta&)
Laboratorium 7B (6pkt)
Wyniki:
---------------ETAP 1 - test klasy grading--------------------
stan obiegowy, nota: 0
stan menniczy MS 66
PCGS, stan UNC 70
PCGS, stan UNC 70
PCG, stan okolomenniczy AU 50
--------------------------------------------------------------
---------------ETAP 2 - test klasy banknnot-------------------
Moneta o nominale nieznany, z roku 0, cena: 0 zl, wartosc: 0 zl, stan obiegowy, nota: 0
Moneta o nominale 1 zl, z roku 0, cena: 0 zl, wartosc: 0 zl, stan obiegowy, nota: 0
Moneta o nominale 6 gr - szostak koronny Jan Kazimierz Ag, z roku 1622, cena: 200 zl, wartosc: 200 zl, stan obiegowy, nota: 0
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Moneta o nominale 5 zl - Nike Ag, z roku 1928, cena: 900 zl, wartosc: 900 zl, stan okolomenniczy AU 53
Moneta o nominale 5 zl - Nike Ag, z roku 1930, cena: 1500 zl, wartosc: 2250 zl, NGC, stan menniczy MS 66
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Przewidywana wartosc w kolejnych 0 latach:
0: 3450
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Przewidywana wartosc w kolejnych 9 latach:
0: 3450
1: 3622.5
2: 3803.63
3: 3993.81
4: 4193.5
5: 4403.17
6: 4623.33
7: 4854.5
8: 5097.22
9: 5352.08
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Przewidywana wartosc w kolejnych 5 latach:
0: 3450
1: 3622.5
2: 3803.63
3: 3993.81
4: 4193.5
5: 4403.17
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Przewidywana wartosc w kolejnych 5 latach:
0: 3450
1: 3622.5
2: 3803.63
3: 3993.81
4: 4193.5
5: 4403.17
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2300 zl, wartosc: 3450 zl, PCGS, stan UNC 70
Przewidywana wartosc w kolejnych 5 latach:
0: 3450
1: 3622.5
2: 3803.63
3: 3993.81
4: 4193.5
5: 4403.17
--------------------------------------------------------------
---------------ETAP 3 - sortowanie----------------------------
Kolekcja monet:
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2200 zl, wartosc: 3300 zl, NGC, stan menniczy MS 62
Moneta o nominale 1,5 gr - poltorak litewski Jan Kazimierz Ag, z roku 1916, cena: 90 zl, wartosc: 90 zl, stan okolomenniczy AU 54
Moneta o nominale 3 gr - trojak koronny Jan III Sobieski Ag, z roku 1924, cena: 230 zl, wartosc: 230 zl, stan okolomenniczy AU 45
Moneta o nominale 5 talarow Au, z roku 1755, cena: 8000 zl, wartosc: 12000 zl, PCGS, stan obiegowy, nota: 44
Moneta o nominale 5 talarow Au, z roku 1755, cena: 9600 zl, wartosc: 12000 zl, PCG, stan okolomenniczy AU 51
Moneta o nominale szelag gdanski Kazimierz Jagiellonczyk Ag, z roku 1490, cena: 16000 zl, wartosc: 20000 zl, GCN, stan okolomenniczy AU 57
Moneta o nominale dukat wilenski Zygmunt II August Au, z roku 1563, cena: 75000 zl, wartosc: 112500 zl, NGC, stan okolomenniczy AU 53
Moneta o nominale 100 dukatow Zygmunt III Waza Ag, z roku 1621, cena: 7e+06 zl, wartosc: 8.75e+06 zl, PCG, stan menniczy MS 65
Moneta o nominale denar Boleslawa Chrobrego PRINCES POLONIE Ag, z roku 1000, cena: 74000 zl, wartosc: 111000 zl, PCGS, stan menniczy MS 67
Moneta o nominale 1/3 gr - szelag - boratynka Jana Kazimierza Cu, z roku 1658, cena: 22 zl, wartosc: 27.5 zl, GCN, stan menniczy MS 66
Kolekcja posortowana wg noty:
Moneta o nominale denar Boleslawa Chrobrego PRINCES POLONIE Ag, z roku 1000, cena: 74000 zl, wartosc: 111000 zl, PCGS, stan menniczy MS 67
Moneta o nominale 1/3 gr - szelag - boratynka Jana Kazimierza Cu, z roku 1658, cena: 22 zl, wartosc: 27.5 zl, GCN, stan menniczy MS 66
Moneta o nominale 100 dukatow Zygmunt III Waza Ag, z roku 1621, cena: 7e+06 zl, wartosc: 8.75e+06 zl, PCG, stan menniczy MS 65
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2200 zl, wartosc: 3300 zl, NGC, stan menniczy MS 62
Laboratorium 7B (6pkt)
Moneta o nominale szelag gdanski Kazimierz Jagiellonczyk Ag, z roku 1490, cena: 16000 zl, wartosc: 20000 zl, GCN, stan okolomenniczy AU 57
Moneta o nominale 1,5 gr - poltorak litewski Jan Kazimierz Ag, z roku 1916, cena: 90 zl, wartosc: 90 zl, stan okolomenniczy AU 54
Moneta o nominale dukat wilenski Zygmunt II August Au, z roku 1563, cena: 75000 zl, wartosc: 112500 zl, NGC, stan okolomenniczy AU 53
Moneta o nominale 5 talarow Au, z roku 1755, cena: 9600 zl, wartosc: 12000 zl, PCG, stan okolomenniczy AU 51
Moneta o nominale 3 gr - trojak koronny Jan III Sobieski Ag, z roku 1924, cena: 230 zl, wartosc: 230 zl, stan okolomenniczy AU 45
Moneta o nominale 5 talarow Au, z roku 1755, cena: 8000 zl, wartosc: 12000 zl, PCGS, stan obiegowy, nota: 44
Kolekcja posortowana wg wartosci:
Moneta o nominale 100 dukatow Zygmunt III Waza Ag, z roku 1621, cena: 7e+06 zl, wartosc: 8.75e+06 zl, PCG, stan menniczy MS 65
Moneta o nominale dukat wilenski Zygmunt II August Au, z roku 1563, cena: 75000 zl, wartosc: 112500 zl, NGC, stan okolomenniczy AU 53
Moneta o nominale denar Boleslawa Chrobrego PRINCES POLONIE Ag, z roku 1000, cena: 74000 zl, wartosc: 111000 zl, PCGS, stan menniczy MS 67
Moneta o nominale szelag gdanski Kazimierz Jagiellonczyk Ag, z roku 1490, cena: 16000 zl, wartosc: 20000 zl, GCN, stan okolomenniczy AU 57
Moneta o nominale 5 talarow Au, z roku 1755, cena: 9600 zl, wartosc: 12000 zl, PCG, stan okolomenniczy AU 51
Moneta o nominale 5 talarow Au, z roku 1755, cena: 8000 zl, wartosc: 12000 zl, PCGS, stan obiegowy, nota: 44
Moneta o nominale 20 zl - Chrobry Au, z roku 1925, cena: 2200 zl, wartosc: 3300 zl, NGC, stan menniczy MS 62
Moneta o nominale 3 gr - trojak koronny Jan III Sobieski Ag, z roku 1924, cena: 230 zl, wartosc: 230 zl, stan okolomenniczy AU 45
Moneta o nominale 1,5 gr - poltorak litewski Jan Kazimierz Ag, z roku 1916, cena: 90 zl, wartosc: 90 zl, stan okolomenniczy AU 54
Moneta o nominale 1/3 gr - szelag - boratynka Jana Kazimierza Cu, z roku 1658, cena: 22 zl, wartosc: 27.5 zl, GCN, stan menniczy MS 66
