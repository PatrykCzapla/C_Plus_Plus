Laboratorium 4A (6pkt)
W zadaniu operujemy na klasie Kolor. Poszczególne kolory opisane są w klasie za pomocą systemu CMY (cyan, magenta, yellow) w zakresie 0 - 255. Klasa zawiera też pola statyczne reprezentujące dostępną ilość każdego z kolorów (farby drukarskie w systemie CMYK). Funkcja main jest już gotowa i nie wolno jej modyfikować.
Kolejne etapy zadania:
Etap 1 (2 pkt)
- Pola statyczne ustawić na 0.
- Konstruktor przyjmujący trzy parametry w systemie RGB (zakres 0 - 255) i ustawiający pola w systemie CMY. Należy sprawdzić przekroczenie zakresu i wartości spoza zakresu ustawić na graniczne. Ustawić wartości domyślne na kolor biały. Konwersja: C = ZAKRES - R; M = ZAKRES - G; Y = ZAKRES - B;
- Konstruktor jednoparametrowy przyjmujący w argumencie kolor_zdefiniowany i ustawiający odpowiednie wartości CMY.
- Przeciążony operator[] przyjmujący kolor_ zdefiniowany RED, GREEN, lub BLUE i zwracający odpowiednią składową RGB.
- Operator wyjścia << wyświetlający składowe RGB w formacie (dla czerwonego):
RGB: 255, 0, 0
Należy użyć operatora indeksacji.
Etap 2 (2 pkt) - Operator wejścia >> wczytujący kolor do obiektu w postaci liczby szesnastkowej RGB np. ab33ff. Należy posłużyć się modyfikatorem hex, oraz operatorami bitowymi do wyodrębnienia koloru.
- Operator odejmowania działający jak filtr pochłaniający dany kolor, czyli odejmowanie składowych RGB dwóch kolorów. W wyniku powstaje kolor o zmniejszonych wartościach odpowiednich składowych.
- Operator -= działający tak jak poprzedni. Odejmuje składowe RGB.
Etap 3 (2 pkt)
- Metoda uzupelnij przyjmująca kolor_ zdefiniowany CYAN, MAGENTA, YELLOW lub BLACK i ustawiająca statyczne pole z ilością danego składnika w systemie CMYK na max wartość.
- Operator funkcji () przyjmujący kolor_ zdefiniowany i zwracający ilość dostępnego koloru z pól statycznych.
- Metoda maluj bezargumentowa, malująca kolorem, dla którego została wywołana. Malowanie polega na zużywaniu dostępnego koloru w takiej ilości ile wynoszą składowe CMY. Składowa czarna jest zużywana do malowania kolorami w odcieniach szarości, czyli gdy składowe CMY są takie same zamiast zużywać trzy składowe CMY zużywamy jedną składową czarną.
Metoda sprawdza, czy wystarczyło koloru do malowania i jeśli nie, zwraca informację np: Zabraklo koloru CYAN i ustawia odpowiednią wartość na 0. Jeśli koloru wystarczy wypisuje informację: Maluje kolorem RGB: 200, 44, 55.
Należy wykorzystać predefiniowany operator wyjścia.
Wyniki:
****************ETAP 1****************
Tworzenie kolorow
**************************************
W kolorze domyslnym jest:
255 czerwonego
255 zielonego
255 niebieskiego
Kolor fioletowy (184,3,255): RGB: 184, 3, 255
Predefiniowany: RGB: 255, 0, 0 - czerwony
Predefiniowany: RGB: 0, 255, 0 - zielony
Predefiniowany: RGB: 0, 0, 255 - niebieski
Predefiniowany: RGB: 0, 255, 255 - turkusowy
Predefiniowany: RGB: 255, 0, 255 - karmazynowy
Predefiniowany: RGB: 255, 255, 0 - zolty
Laboratorium 4A (6pkt)
****************ETAP 2****************
Mieszanie kolorow
**************************************
Podaj kolor RGB szesnastkowo (np: ab33ff): ab33ff
Kolor wczytany: RGB: 171, 51, 255
Odjecie od czerwonego koloru zielonego pozostawia czerwony: RGB: 255, 0, 0
Odjecie podstawowego koloru od dopelniajacego daje podstawowy:
Cyan - Zielony: RGB: 0, 0, 255 (niebieski)
Kolor bialy k1: RGB: 255, 255, 255
zminiamy w czarny k1: RGB: 0, 0, 0
****************ETAP 3****************
Rysowanie
**************************************
Napelnienie farby...
Cyan: 1000, magenta: 1000, yellow: 1000
Rysowanie...
Kolorem zielonym
Maluje kolorem RGB: 0, 255, 0
Zostalo:
Cyan: 745, magenta: 1000, yellow: 745, black: 1000
Kolorem zielonym
Maluje kolorem RGB: 0, 255, 0
Zostalo:
Cyan: 490, magenta: 1000, yellow: 490, black: 1000
Kolorem szarym
Maluje kolorem RGB: 200, 200, 200
Zostalo:
Cyan: 490, magenta: 1000, yellow: 490, black: 945
Innymi kolorami
Maluje kolorem RGB: 184, 3, 255
Maluje kolorem RGB: 234, 125, 44
Maluje kolorem RGB: 255, 255, 0
Zostalo:
Cyan: 398, magenta: 618, yellow: 24, black: 945
I jeszcze jedna kreska
Zabraklo koloru YELLOW
Zostalo:
Cyan: 343, magenta: 463, yellow: 0, black: 945
Press any key to continue . . .
