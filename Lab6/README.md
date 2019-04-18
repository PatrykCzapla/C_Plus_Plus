ZADANIE 6b (6 pkt)
Celem zadania jest uproszczona obsługa bankowa klienta, który przychodzi do banku
załatwić sprawę. Ta sprawa to: założenie nowego konta, skasowanie konta, wpłata/wypłata
na rachunek bieżący oraz założenie lokaty lub jej skasowanie.
Zadanie jest podzielone na klasy ( wstępne szkielety klas zostały zaprojektowane ), które
będą ze sobą współpracować, oto one:
dane klasa, przechowuje tajne dane osobowe klienta (gotowa)
klient klient, który idzie załatwić w wybranym banku
bank zarządza kontami klientów i załatwia ich sprawy
konto to po prostu konto klienta w banku
lokata na koncie można założyć oprocentowaną lokatę (gotowa)
ETAP 1 – 1 pkt
Oczywiście utwórz projekt składający się z dostarczonych plików.
Obejrzyj klasę dane (tylko obejrzyj i nie modyfikuj – jest gotowa)
Przejdź do klasy klient i obejrzyj, jak będą tworzone i wypisywane obiekty tej klasy.
Skompiluj i uruchom aplikację. Powinni wyświetlić się klienci ze sprawami do załatwienia w
banku.
Odkomentuj w klasie klient metodę ide_do_banku , a w klasie bank – metody, które
ona wywołuje ( nowe_konto, itd. ), ponadto odkomentuj również zakomentowany fragment
funkcji main, który również odwołuje się do tej metody.
Zadbaj o odpowiednie zależności między klasami klient oraz bank (dodaj zapowiedzi klas,
zrealizuj odpowiednie zaprzyjaźnienia klas)
Skompiluj ponownie i uruchom aplikację.
ETAP 2 – 1 pkt
Przejdź do klasy konto.
Zaimplementuj jej konstruktor oraz destruktor.
W klasie bank zaimplementuj metodę nowe_konto.
Nadawanie kolejnych numerów kont kontroluje bank za pomocą swojego pola
nadaj_nr_konta ( od wartości podanej w konstruktorze banku, tutaj 1500 ), saldo ustaw
na 0, wskaźnik l na pusty.
Po przydzieleniu numeru konta, pole nadaj_nr_konta zwiększ o 1.
Zwraca true , gdy w banku poprawnie utworzono nowe konto, wpp false.
Uruchom aplikację, wykonaj 2 pierwszych klientów z kolejki (od 0 do 1)
ETAP 3 – 1 pkt
W poniższych 3 metodach wypisz również odpowiednie komunikaty.
· w klasie bank zaimplementuj metodę znajdz_konto o podanym numerze. Zwraca
indeks znalezionego konta lub -1 w przypadku jakiegokolwiek niepowodzenia.
· w klasie konto zaimplementuj metodę czy_wlasciciel_konta, która sprawdza, czy
podana osoba jest właścicielem konta.
· w klasie konto zaimplementuj metodę czy_lokata, która sprawdza, czy na koncie jest
założona lokata (tj. czy l jest pusty, czy nie).
cd ETAP 3
W klasie bank zaimplementuj metodę kasuj_konto – tylko właściciel może kasować
konto, na którym nie ma lokaty.
Wykorzystaj tutaj właśnie zdefiniowane metody i dopiero wtedy zabierz się za usuwanie.
Uruchom aplikację, obsłuż klientów z kolejki od 0 do 8.
ETAP 4 – 1 pkt
W klasie bank zaimplementuj metodę wplata_na_konto – wpłaty może dokonać każdy.
Znajdź konto w banku, a następnie wywołaj metodę wplata klasy konto. W metodzie
sprawdź, czy wpłacana kwota jest dodatnia i dopiero wtedy wpłacaj powiększając pole
saldo.
W klasie bank zaimplementuj metodę wyplata_z_konta – wypłaty może dokonać tylko
właściciel.
Znajdź konto w banku, sprawdź czy to właściciel, a następnie wywołaj metodę wyplata
klasy konto. W metodzie sprawdź, czy wypłacana kwota jest dodatnia oraz czy nie
przekracza pola saldo i dopiero wtedy wypłacaj pomniejszając pole saldo.
Uruchom aplikację, wykonaj sprawy z kolejki od 0 do 16.
ETAP 5 – 1 pkt
Obejrzyj klasę lokata ( gotowa )
W klasie bank zaimplementuj metodę wez_lokate – lokatę może założyć każdy pod
warunkiem, że jej aktualnie nie ma na koncie.
Znajdź konto w banku, sprawdź czy nie ma już lokaty, a następnie wywołaj metodę
wez_lokate klasy konto.
W metodzie utwórz dynamicznie odpowiedni obiekt lokata pod wskaźnik l.
Uruchom aplikację, wykonaj sprawy z kolejki od 0 do 19.
ETAP 6 – 1 pkt
W klasie bank zaimplementuj metodę kasuj_lokate – lokatę może rozwiązać tylko
właściciel pod warunkiem, że na koncie jest lokata.
Znajdź konto w banku, sprawdź czy to właściciel, sprawdź czy ma lokatę, a następnie
wywołaj metodę kasuj_lokate klasy konto.
W metodzie zwolnij wskaźnik l, a wartość lokaty (metoda wartosc_lokaty) wpłać na
bieżące saldo konta (metoda wplata).
Przykładowe wyniki w pliku: wyniki.pdf
