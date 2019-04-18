Zadanie 8b (6 punktów)
Świat zaatakowały skorpiony. Jako dzielny kapłan musisz wyruszyć na ratunek i uratować świat!
W poniższym opisie zadania przyjęto następujące oznaczenia oraz zasady: Ogólnie w walce porównujemy całkowitą siłę ataku atakującego (sila_ataku) z całkowitym poziomem ochrony broniącego się (poziom_ochrony). Posiadanie w danym momencie walki większej siły ataku od poziomu ochrony (sila_ataku > poziom_ochrony) oznacza trafienie i zadanie obrażeń wynikających z rodzaju użytej broni (dla postaci) lub rodzaju wykonanego ataku (dla potworów).
W przypadku używania czarów zakładamy, że zaklęcie zawsze działa (automatyczne trafienie lub wykonanie zaklęcia), pod warunkiem że postać może go użyć. Zaklęcia dzielimy na ofensywne i defensywne. Zaklęcie ofensywne służy do ataku i skutkuje automatycznym zadaniem obrażeń przeciwnikowi (obrazenia). Zaklęcie defensywne służy do leczenia oraz poprawy kondycji postaci i skutkuje odzyskaniem przez postać określonej liczby punktów życia (odzyskane_punkty_zycia). Za wykonanie klasycznego ataku w klasach odpowiedzialna jest metoda int wykonaj_atak(int poziom_ochrony_przeciwnika) const, która jako argument przyjmuje poziom ochrony przeciwnika, zwyczajowo porównuje go z siłą ataku i w przypadku trafienia (czasem automatycznego bez porównywania) zwraca wartość zadanych obrażeń. Za przyjęcie ataku w klasach odpowiedzialna jest metoda void przyjmij_atak(int obrazenia), która jako argument przyjmuje ilość zadanych obrażeń i odejmuje je od aktualnych punktów życia postaci/potwora.
Wszelkie informacje o potworach/postaciach/przedmiotach powinny wypisywać się w sposób zgodny z przykładowym wyjściem z programu zamieszczonym na końcu instrukcji. Nie wolno modyfikować deklaracji klas bazowych. Dziedziczymy publicznie. Deklarujemy jedynie niezbędne elementy klas, a wszędzie, gdzie to możliwe w implementacji wykorzystujemy metody już dostępne w klasie bazowej (nie redefiniujemy kodu).
Etap 1 – 1,5 pkt
Klasa Skorpion reprezentuje abstrakcyjną klasę bazową pozwalającą na polimorficzne dziedziczenie różnych rodzajów skorpionów i jest już zaimplementowana. Zapoznaj się z tą klasą. Bazując na deklaracji klasy bazowej oraz przykładowym użyciu w main należy uzupełnić deklaracje i implementacje dla dwóch klas pochodnych: SkorpionOlbrzymi oraz JadowitySkorpionOlbrzymi. Czysto wirtualna metoda virtual int wykonaj_atak(int poziom_ochrony_przeciwnika) const odpowiedzialna jest za wywołanie w klasach pochodnych odpowiedniego rodzaju ataku (zgodnie z regułami opisanymi na początku).
W klasie pochodnej SkorpionOlbrzymi dostępny jest int atak_ostrym_odnozem() const, który zadaje 2 obrażenia. W klasie pochodnej JadowitySkorpionOlbrzymi (dziedziczonej po PajakOszczepnik) dodatkowo znajduje się specjalny rodzaj ataku int atak_jadowitym_kolcem() const, który zadaje 4-krotnie więcej obrażeń niż atak zwykłym odnóżem i zawsze dochodzi celu (automatyczne trafienie). Co drugi atak każdego jadowitego skorpiona olbrzymiego jest właśnie takim atakiem (należy kontrolować i wykorzystać zmienną statyczną ktory_atak). Skorpiony te są także
dodatkowo dwa razy potężniejsze od swoich pierwowzorów (posiadają dwa razy więcej punktów
życia, siły ataku oraz poziomu obrony).
Etap 2 – 1 pkt
Klasa Zaklecie reprezentuje abstrakcyjną klasę bazową pozwalającą na polimorficzne dziedziczenie
różnych rodzajów zaklęć i jest już zaimplementowana. Zapoznaj się z tą klasą. Bazując na deklaracji
klasy oraz przykładowym użyciu w main należy wydziedziczyć klasy pochodne: ZaklecieOfensywne
oraz ZaklecieDefensywne (obie dziedziczone z Zaklecie). Czysto wirtualna metoda virtual int
wypowiedz_zaklecie() odpowiedzialna jest w klasach pochodnych za wykonanie odpowiednich
skutków zaklęcia. Dla klasy ZaklecieOfensywne rzucenie czaru zwraca odpowiednią liczbę obrażeń
(obrazenia), zaś dla klasy ZaklecieDefensywne rzucenie czaru zwraca odzyskaną liczbę punktów
życia (odzyskane_punkty_zycia).
Etap 3 – 1 pkt
Klasa Przedmiot reprezentuje klasę bazową pozwalającą na polimorficzne dziedziczenie różnych
rodzajów przedmiotów i jest już zaimplementowana. Zapoznaj się z tą klasą. Bazując na deklaracji
klasy oraz przykładowym użyciu w main należy uzupełnić implementację klas pochodnych: Bron oraz
SymbolWiary.
W klasie Bron dodatkowe pole int obrazenia odpowiada za wartość obrażeń zadawanych przez
daną broń. Wartość zadawanych obrażeń powinna być zwracana przez metodę int atak_bronia()
const.
Klasa SymbolWiary posiada metodę bool uzyj() const. Metoda to pozwala na użycie przedmiotu
i wyproszenie łask od bóstwa – na ekranie powinien wypisać się tekst "Symbol wiary rozswietla
wszystko dookola - Bostwo slucha - Czas na modlitwe!", zaś wartością zwracaną jest zawsze
true.
Etap 4 – 1 pkt
Klasa Kaplan reprezentuje klasę postaci i jest częściowo zaimplementowana. Zapoznaj się z tą klasą.
Każda kapłan może trzymać w jednej ręce broń (bron_w_rece), w drugiej ręce symbol wiary
(symbol_w_rece) oraz posiadać cztery rzeczy w ekwipunku (tablica ekwipunek i stała
wielkosc_ekwipunku). Konstruktor klasy bazowej tworzy postać ze standardowym ekwipunkiem
(obejrzyj konstruktor). Każdy kapłan zna także pewną liczbę zaklęć – tablicę
(znane_zaklecia[ilosc_zaklec]) przetrzymującą cztery, z góry określone zaklęcia (a dokładnie
adresy zaklęć, patrz implementacja konstruktora). Należy uzupełnić implementację brakujących
metod. Kapłan może rzucić dziennie określoną liczbę zaklęć (zależy ona od jego mądrości) i jest
kontrolowana w polu ile_zaklec. Aby odnowić dzienny limit zaklęć kapłan musi się pomodlić. Należy
uzupełnić implementację brakujących metod.
Metoda int znajdz_zaklecie_ofensywne() const identyfikuje czy kapłan zna zaklęcie ofensywne
Szukamy tylko do pierwszego wystąpienia. Jeśli zna (występuje w tablicy znane_zaklecia), to
zwracany jest indeks zaklęcia. W przeciwnym przypadku zwracana jest wartość -1. Analogicznie działa
metoda int znajdz_zaklecie_defensywne() const z tym, że identyfikujemy zaklęcie defensywne.
W obu powyższych metodach wykorzystaj mechanizm RTTI. Obie metody powinny zwracać indeks
zaklęcia pod warunkiem, że kapłan nie wykorzystał jeszcze całego dziennego limitu zaklęć (pole
ile_zaklec > 0). W przeciwnym przypadku również zwracamy -1.
Etap 5 – 1,5 pkt
Metoda void przygotuj_postac() przygotowuje postać do ciężkiego dnia. Kapłan wstając rano musi
w ekwipunku znaleźć broń (pierwszą z brzegu) i przełożyć ją do ręki. Musi także znaleźć symbol wiary
i przełożyć go do drugiej ręki. Jednocześnie powinien się pomodlić, aby odnowić dzienny limit zaklęć.
Po przełożeniu przedmiotu do ręki jego miejsce w ekwipunku powinno zostać puste. Prywatna
metoda void modlitwa() realizuje modlitwę kapłana. Modlitwa się udaje (kapłan zostaje
wysłuchany), jeśli kapłan trzyma w ręku symbol wiary i go użyje. Udana modlitwa oznacza, że kapłan
zyskuje dzienny limit zaklęć (ile_zaklec), który jest równy jego mądrości.
Metoda int wykonaj_atak(int poziom_ochrony_przeciwnika) realizuje atak kapłana według
następujących reguł:
• W pierwszej kolejności dbamy o własne życie. Jeśli poziom punktów życia spadł nam już
poniżej 15 i kapłan zna zaklęcie defensywne, to je rzucamy. Nie zadajemy żadnych obrażeń
ale odzyskujemy punkty życia. Rzucenie zaklęcie zmniejsza o jeden liczbę możliwych do
rzucenia zaklęć.
• Jeśli mamy się całkiem nieźle fizycznie to próbujemy wykorzystywać magię do ataku, czyli
jeśli kapłan zna jakieś zaklęcie ofensywne, to je rzucamy (dla uproszczenia pierwsze z brzegu
bo takie jest zawsze znajdowane). Zadajemy tyle obrażeń ile zadaje zaklęcie, które właśnie
rzuciliśmy. Rzucenie zaklęcie zmniejsza o jeden liczbę możliwych do rzucenia zaklęć.
• Jeśli nie mamy już dostępnych zaklęć (limit dzienny wyczerpany a w czasie walki nie ma czasu
na modlitwę) to walimy bronią (według znanych już reguł, czyli trzeba mieć więcej
sila_ataku niż poziom_ochrony_przeciwnika przeciwnika żeby trafić i wykonać skuteczny
atak bronią). Zadajemy obrażenia zgodne z obrażeniami broni, którą uderzamy.
Jeśli wszystko się nie powiedzie to niestety zadajemy 0 obrażeń.
Jeśli wszystko zostało poprawnie zaimplementowane, to wywołanie funkcji void
spotkanie(Skorpion* skorpion, Kaplan* kaplan) realizuje spotkanie i walkę kapłana ze
skorpionem. Zobacz, czy kapłan uratował świat 😊
Przykładowy efekt poprawnego wykonanie programu:
------------- ETAP 1 (1,5 pkt) --------------
Skorpion Olbrzymi - poziom ochrony: 2 punkty zycia: 15
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 30
Atakuje Skorpion Olbrzymi - poziom ochrony: 2 punkty zycia: 15
- trafia i zadaje 2 obrazen
Atakuje Skorpion Olbrzymi - poziom ochrony: 2 punkty zycia: 15
- nie trafia i zadaje 0 obrazen
Broni sie Skorpion Olbrzymi - poziom ochrony: 2 punkty zycia: 15
- unika ataku !
Broni sie Skorpion Olbrzymi - poziom ochrony: 2 punkty zycia: 15
- trafiony za 20 obrazen!
Skorpion Olbrzymi - poziom ochrony: 2 punkty zycia: -5
- zabity!!! Huraaaa!!!
Atakuje Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 30
- trafia i zadaje 2 obrazen
Atakuje Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 30
- to 2 atak wiec zawsze trafia i zadaje 8 obrazen
Atakuje Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 30
- nie trafia i zadaje 0 obrazen
Broni sie Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 30
- trafiony za 20 obrazen!
Broni sie Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 10
- trafiony za 20 obrazen!
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: -10
- zabity!!! Huraaaa!!!
------------- ETAP 2 (1 pkt) --------------
Widmowe Ostrza ( poziom 1)
Obrazenia: 2
Leczniczy dotyk ( poziom 1)
Odzyskane punkty zycia: 4
------------- ETAP 3 (1 pkt) --------------
Miecz (klasyczny miecz jednoreczny) Obrazenia: 3
Atak mieczem - zadano 3 obrazenia
Pierscien z granitem (pierscien z symbolem zywiolu ziemi)
Symbol wiary rozswietla wszystko dookola - Bostwo slucha - Czas na modlitwe!
------------- ETAP 4 (1 pkt) --------------
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 30 liczba zaklec: 0
1. Miecz (klasyczny miecz jednoreczny) Obrazenia: 3
2. Pierscien z granitem (pierscien z symbolem zywiolu ziemi)
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Zaklecie ofensywne niedostepne
Zaklecie defensywne niedostepne
------------- ETAP 5 (1,5 pkt) --------------
Wezyr przygotowuje sie ... bierze ksiege do reki, medytuje, bierze swoj kij ...
Symbol wiary rozswietla wszystko dookola - Bostwo slucha - Czas na modlitwe!
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 30 liczba zaklec: 5
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Zaklecie ofensywne dostepne pod indeksem: 0
Zaklecie defensywne dostepne pod indeksem: 1
------------- Symulacja (na koniec) --------------
Witaj Czarodzieju! Musisz ocalic swiat przed atakiem Pajakow
********** RUNDA 1 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 30 liczba zaklec: 5
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 30
********** RUNDA 2 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 22 liczba zaklec: 4
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 25
********** RUNDA 3 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 22 liczba zaklec: 3
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 20
********** RUNDA 4 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 14 liczba zaklec: 2
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 15
********** RUNDA 5 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 18 liczba zaklec: 1
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 15
********** RUNDA 6 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 10 liczba zaklec: 0
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 10
********** RUNDA 7 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 10 liczba zaklec: 0
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 7
********** RUNDA 8 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 2 liczba zaklec: 0
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 4
********** RUNDA 9 **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 2 liczba zaklec: 0
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: 1
********** KONIEC WALKI **********
Asgaroth Tempus, Patriarcha Ziemi - calkowita sila ataku: 5 calkowity poziom ochrony: 5 punkty
zycia: 2 liczba zaklec: 0
1. pusto
2. pusto
3. Sztylet (sztylet krotki) Obrazenia: 1
4. pusto
Jadowity Skorpion Olbrzymi - poziom ochrony: 4 punkty zycia: -2
Zwyciezyles !!! Swiat uratowany
Press any key to continue . . .
