Zadanie 3b (6 punktów)
Celem zadania jest stworzenie klasy waluta_francuska reprezentującej dawny francuski system monetarny. Dawną walutą Francji był liwr, który historycznie był równoważny 20 solidom. Solid stanowił zaś równoważność 12 denarów. W 1795 nastąpiła tzw. decymalizacja liwra. Zastąpiono go frankiem, który od tego momentu stał się równoważny 100 centymom.
Zapis L 2.5.3 oznaczał zatem 2 liwry 5 solidów i 3 denary. 1 liwr odpowiadał 240 denarom (20 * 12). Łatwo zauważyć, że jeden nowy centym po decymalizacji to równowartość 2,4 starych denarów. Przykładowo obecne F 1,75 (1 frank i 75 centymów) to równoważność 420 dawnych denarów (175 * 2,4) czyli dawne L 1.15.0 (1 liwr 15 solidów i 0 denarów bo 420 denarów to równo 35 solidów, zaś 35 solidów to 1 liwr i 15 denarów).
Funkcja main została przygotowana w całości (patrz plik lab3b.cpp) i nie należy jej modyfikować, poza odkomentowywaniem kolejnych części zadania. Należ samodzielnie stworzyć plik nagłówkowy waluta_francuska.h oraz plik implementacyjny waluta_francuska.cpp. W każdym etapie należy uzupełniać klasę o elementy niezbędne do realizacji stosownych funkcjonalności, które wynikają z przykładowego użycia pokazanego w funkcji main.
Etap 1 – 1,5 pkt
• Klasa posiada 3 pola składowe typu int, reprezentujące odpowiednio liwry, solidy i denary.
• Konstruktor bezargumentowy powinien domyślnie tworzyć 1 liwra.
• Konstrukt z 3 argumentami przyjmuje odpowiednio określoną liczbę liwrów, solidów i denarów.
• Konstrukt jednoargumentowy przyjmuje walutę w postaci współczesnej (po decymacji, czyli np. 1 frank 75 centymów przekazane jako liczba double o wartości 1,75).
• Nie można poprawnie stworzyć obiektu, jeśli na którymś z pól znajdą się wartości ujemne – powinien wtedy powstać obiekt z wszystkimi polami o wartości 0.
• Zaprzyjaźniony operator wypisania wypisuje walutę w formacie L X.Y.Z, gdzie X to liwry, Y to solidy a Z to denary (L symbol liwra).
• Zaprzyjaźniony operator wczytania pobiera z klawiatury walutę w postaci współczesnej (po decymacji), jako liczbę typu double (np. 1,75).
• Waluta w obiekcie jest zawsze uporządkowana. Oznacza to, że jeśli do konstruktora przekazane zostanie 15 denarów, to jest to formalnie 1 solid i 3 denary. W polu denary przechowujemy więc 3 a liczbę solidów należy zwiększyć o jeden. Podobnie dzieje się w przypadku np. dodawania dwóch obiektów, jeśli suma denarów lub solidów przekracza odpowiednio 12 lub 20. Można stworzyć prywatną metodę, która porządkuje pola w obiekcie – może być ona przydatna w wielu etapach zadania.
Etap 2 – 1,5 pkt
Wszystkie niezbędne operatory powinny być zdefiniowane w taki sposób, aby ich działanie było zgodne z przykładowym wyjściem z programu zamieszczonym na końcu instrukcji.
Etap 3 – 1 pkt
Wszystkie niezbędne operatory powinny być zdefiniowane w taki sposób, aby ich działanie było
zgodne z przykładowym wyjściem z programu zamieszczonym na końcu instrukcji. W szczególności
operator wywołania funkcji (operator()) zwraca walutę po decymacji, czyli równoważność waluty
w postaci liczby (np. obiekt o zawartości L 1.15.0 w wyniku użycia operatora wywołania funkcji
powinien zwrócić liczbę 1,75). Operatory inkrementacji i dekrementacji odpowiednio zwiększają
i pomniejszają o jeden denar.
Etap 4 – 2 pkt
Wszystkie niezbędne operatory porównania powinny być zdefiniowane w taki sposób, aby ich
działanie było zgodne z przykładowym wyjściem z programu zamieszczonym na końcu instrukcji.
Funkcja sortująca powinna posortować kwoty (dowolnym algorytmem sortowania) według ich
wartości (malejąco).
Przykładowy efekt poprawnego wykonanie programu:
************************* Etap 1 (1,5 pkt) *************************
Podaj walute po decymacji (np. 1.67): 2.5
w0: L 1.0.0
w1: L 0.0.0
w2: L 1.10.10
w3: L 2.12.6
w4: L 0.0.0
w5: L 2.12.6
w6: L 1.10.10
w7: L 2.10.0
************************* Etap 2 (1,5 pkt) *************************
w1 = w3 - w2 - w1: L 1.1.8
w4 = w1 - w0: L 0.1.8
w4 += w3: L 2.14.2
2 * w6 * 2: L 6.3.4
************************* Etap 3 (1 pkt) *************************
w7 = w4--: L 2.14.2
--w4 (uzyte 2-krotnie): L 2.13.11
w4(): 2.69583
************************* Etap 4 (2 pkt) *************************
1.54167 jest rowne 1.54167
2.69583 jest wieksze od 1.54167
1.54167 nie jest mniejsze od 1.54167
Przed:
L 3.5.7
L 6.2.10
L 3.4.4
L 4.4.4
L 3.15.0
Po:
L 6.2.10
L 4.4.4
L 3.15.0
L 3.5.7
L 3.4.4
