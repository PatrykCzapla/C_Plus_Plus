#include <iostream>

#include "Silnik.hpp"
#include "Samolot.hpp"
#include "FabrykaSamolotow.hpp"

int main()
{
	std::cout << "===================== ETAP 1 =====================" << std::endl;

	{
		Silnik* silnik = new SilnikSpalinowy(300);

		const float waga1 = 1200.0f;
		const float oplywowosc1 = 0.5f;
		const float wspolczynnikMocy1 = 1.0f;

		const float waga2 = 900.0f;
		const float oplywowosc2 = 0.7f;
		const float wspolczynnikMocy2 = 0.9f;

		std::cout << "Pobieranie wagi: " << silnik->ZwrocWage() << std::endl;
		std::cout << "Pobieranie mocy: " << silnik->ZwrocMoc() << std::endl;
		std::cout << "Pobieranie kosztu produkcji: " << silnik->ZwrocKosztProdukcji() << std::endl;

		std::cout << std::endl;
		std::cout << "Przyspieszenie dla wagi " << waga1 << ", wsp. mocy " << wspolczynnikMocy1 << ": " << silnik->ObliczPrzyspieszenie(waga1, wspolczynnikMocy1) << std::endl;
		std::cout << "Predkosc maksymalna dla oplywowosci " << oplywowosc1 << ", wsp. mocy " << wspolczynnikMocy1 << ": " << silnik->ObliczPredkoscMaksymalna(oplywowosc1, wspolczynnikMocy1) << std::endl;

		std::cout << std::endl;
		std::cout << "Przyspieszenie dla wagi " << waga2 << ", wsp. mocy " << wspolczynnikMocy2 << ": " << silnik->ObliczPrzyspieszenie(waga2, wspolczynnikMocy2) << std::endl;
		std::cout << "Predkosc maksymalna dla oplywowosci " << oplywowosc2 << ", wsp. mocy " << wspolczynnikMocy2 << ": " << silnik->ObliczPredkoscMaksymalna(oplywowosc2, wspolczynnikMocy2) << std::endl;


		std::cout << std::endl;
		std::cout << "Wypisywanie calego silnika:" << std::endl;
		std::cout << *silnik << std::endl;

		delete silnik;
	}


	std::cout << "===================== ETAP 2 =====================" << std::endl;

	{
		Silnik* silniki[] = {
			new SilnikSpalinowy(300),
			new SilnikSpalinowy(400),
			new SilnikElektryczny(300),
			new SilnikElektryczny(80),
			new SilnikOdrzutowy(300),
			new SilnikOdrzutowy(1000),
		};

		const float waga = 1500.0f;
		const float oplywowosc = 0.5f;
		const float wspolczynnikMocy = 0.9f;

		for (int i = 0; i < sizeof(silniki) / sizeof(silniki[0]); ++i)
		{
			Silnik& silnik = *silniki[i];

			std::cout << "---- Silnik " << i + 1 << " ----" << std::endl;
			std::cout << silnik << std::endl;
			std::cout << "Przyspieszenie dla wagi " << waga << ", wsp. mocy " << wspolczynnikMocy << ": " << silnik.ObliczPrzyspieszenie(waga, wspolczynnikMocy) << std::endl;
			std::cout << "Predkosc maksymalna dla oplywowosci " << oplywowosc << ", wsp. mocy " << wspolczynnikMocy << ": " << silnik.ObliczPredkoscMaksymalna(oplywowosc, wspolczynnikMocy) << std::endl;
			std::cout << std::endl;

			delete &silnik;
		}
	}
	
	std::cout << "===================== ETAP 3 =====================" << std::endl;

	{
		Silnik* silniki[] = {
			new SilnikSpalinowy(300),
			new SilnikElektryczny(620),
			new SilnikOdrzutowy(3200),
		};

		for (int i = 0; i < sizeof(silniki) / sizeof(silniki[0]); ++i)
		{
			FabrykaSamolotow fabryka;

			Silnik& silnik = *silniki[i];

			std::cout << "---- Silnik " << i + 1 << " ----" << std::endl;


			// Oryginalny silnik
			std::cout << "-- Oryginalny silnik:" << std::endl;
			std::cout << silnik;
			std::cout << "  Koszt produkcji: " << silnik.ZwrocKosztProdukcji() << std::endl;
			std::cout << std::endl;


			// Niepoprawna proba produkcji
			std::cout << "---- 1. proba produkcji silnika:" << std::endl;
			fabryka.OdnowSrodki(silnik.ZwrocKosztProdukcji() / 2);
			std::cout << "Srodki fabryki: " << fabryka.ZwrocSrodki() << std::endl;
			try
			{
				Silnik* wyprodukowanySilnik = fabryka.Produkuj(silnik);

				std::cout << "Nieoczekiwany brak wyjatku!" << std::endl;
				delete wyprodukowanySilnik;
			}
			catch (const std::runtime_error& exc)
			{
				std::cout << "Wyjatek: " << exc.what() << std::endl;
			}
			catch (...)
			{
				std::cout << "Nieoczekiwany wyjatek!" << std::endl;
			}


			// Poprawna proba produkcji
			std::cout << std::endl;
			std::cout << "---- 2. proba produkcji silnika:" << std::endl;
			fabryka.OdnowSrodki(silnik.ZwrocKosztProdukcji() / 2 + 1);
			std::cout << "Srodki fabryki: " << fabryka.ZwrocSrodki() << std::endl;
			try
			{
				Silnik* wyprodukowanySilnik = fabryka.Produkuj(silnik);

				std::cout << "-- Wyprodukowany silnik:" << std::endl;
				std::cout << *wyprodukowanySilnik;
				std::cout << "  Koszt produkcji: " << wyprodukowanySilnik->ZwrocKosztProdukcji() << std::endl;
				std::cout << std::endl;

				delete wyprodukowanySilnik;
			}
			catch (const std::runtime_error& exc)
			{
				std::cout << "Nieoczekiwany wyjatek: " << exc.what() << std::endl;
			}
			catch (...)
			{
				std::cout << "Nieoczekiwany wyjatek!" << std::endl;
			}
			std::cout << std::endl;


			delete &silnik;
		}
	}
	
	std::cout << "===================== ETAP 4 =====================" << std::endl;

	{
		Samolot* samoloty[] =
		{
			new SamolotTransportowy(new SilnikSpalinowy(50), 3, 50000, 15000.0f, 0.5f),
			new SamolotTransportowy(new SilnikElektryczny(90), 3, 50000, 15000.0f, 0.5f),
			new SamolotTransportowy(new SilnikOdrzutowy(150), 3, 50000, 15000.0f, 0.5f),

			new SamolotWyczynowy(new SilnikSpalinowy(2000), 2, 500000, 1100.0f, 0.8f),
			new SamolotWyczynowy(new SilnikElektryczny(2300), 2, 1000000, 1100.0f, 0.8f),
			new SamolotWyczynowy(new SilnikOdrzutowy(4200), 2, 1500000, 1100.0f, 0.8f),

			new SamolotPasazerski(new SilnikSpalinowy(500), 20, 1000000, 15000.0f, 0.6f),
			new SamolotPasazerski(new SilnikElektryczny(900), 20, 1500000, 15000.0f, 0.6f),
			new SamolotPasazerski(new SilnikOdrzutowy(1500), 20, 2000000, 15000.0f, 0.6f),
		};

		for (int i = 0; i < sizeof(samoloty) / sizeof(samoloty[0]); ++i)
		{
			Samolot& samolot = *samoloty[i];
			SamolotTransportowy* transportowy;
			SamolotWyczynowy* wyczynowy;
			SamolotPasazerski* pasazerski;


			std::cout << "---- Samolot " << i + 1 << " ----" << std::endl;
			std::cout << "-- Przed testowaniem --" << std::endl;
			std::cout << samolot << std::endl;

			if ((transportowy = dynamic_cast<SamolotTransportowy*>(&samolot)) != nullptr)
				transportowy->UstawIloscTowaru(170);
			if ((wyczynowy = dynamic_cast<SamolotWyczynowy*>(&samolot)) != nullptr)
				wyczynowy->UstawCzyKlapyOtwarte(true);
			if ((pasazerski = dynamic_cast<SamolotPasazerski*>(&samolot)) != nullptr)
				pasazerski->UstawPodgrzewanieSiedzen(true);

			std::cout << "-- Po testowaniu --" << std::endl;
			std::cout << samolot << std::endl;
			std::cout << std::endl;


			delete &samolot;
		}
	}
	system("pause");

//	std::cout << "===================== ETAP 5 =====================" << std::endl;
//
//	{
//		Samolot* samoloty[] =
//		{
//			new SamolotTransportowy(new SilnikOdrzutowy(500), 7, 50000, 1500.0f, 0.5f),
//			new SamolotWyczynowy(new SilnikSpalinowy(820), 2, 1500000, 900.0f, 0.8f),
//			new SamolotPasazerski(new SilnikOdrzutowy(9000), 4, 15000000, 300000.0f, 0.6f),
//		};
//
//		for (int i = 0; i < sizeof(samoloty) / sizeof(samoloty[0]); ++i)
//		{
//			FabrykaSamolotow fabryka;
//
//			Samolot& samolot = *samoloty[i];
//
//			std::cout << "---- Samolot " << i + 1 << " ----" << std::endl;
//			std::cout << "-- Oryginalny samolot:" << std::endl;
//			std::cout << samolot << std::endl;
//
//
//
//			// Niepoprawna proba produkcji
//			std::cout << "---- 1. proba produkcji samolotu:" << std::endl;
//			std::cout << "Srodki fabryki: " << fabryka.ZwrocSrodki() << std::endl;
//			try
//			{
//				Samolot* wyprodukowanySamolot = fabryka.Produkuj(samolot);
//				std::cout << "Nieoczekiwany brak wyjatku!" << std::endl;
//				delete wyprodukowanySamolot;
//			}
//			catch (const std::runtime_error& exc)
//			{
//				std::cout << "Wyjatek przy produkcji: " << exc.what() << std::endl;
//			}
//			catch (...)
//			{
//				std::cout << "Nieoczekiwany wyjatek!" << std::endl;
//			}
//			std::cout << std::endl;
//
//
//
//
//			// Poprawna proba produkcji
//			fabryka.OdnowSrodki(10 * samolot.ZwrocCene());
//			std::cout << "---- 2. proba produkcji samolotu:" << std::endl;
//			std::cout << "Srodki fabryki: " << fabryka.ZwrocSrodki() << std::endl;
//			try
//			{
//				Samolot* wyprodukowanySamolot = fabryka.Produkuj(samolot);
//				std::cout << *wyprodukowanySamolot << std::endl;
//				delete wyprodukowanySamolot;
//			}
//			catch (const std::runtime_error& exc)
//			{
//				std::cout << "Nieoczekiwany wyjatek przy produkcji: " << exc.what() << std::endl;
//			}
//			catch (...)
//			{
//				std::cout << "Nieoczekiwany wyjatek!" << std::endl;
//			}
//
//
//
//
//
//			// Rozpocznij masowa produkcje samolotow
//			std::cout << "----Wdrozenie masowej produkcji samolotow..." << std::endl;
//
//			std::cout << "  Srodki fabryki: " << fabryka.ZwrocSrodki() << std::endl;
//
//			const int SamolotyDoWyprodukowania = 100;
//			Samolot* noweSamoloty[SamolotyDoWyprodukowania];
//
//			int samolotyOdWplaty = 0;
//			int wyprodukowaneSamoloty = 0;
//
//			while (wyprodukowaneSamoloty < SamolotyDoWyprodukowania)
//			{
//				// Produkuj samoloty dopoki fabryka ma srodki
//				try
//				{
//					noweSamoloty[wyprodukowaneSamoloty] = fabryka.Produkuj(samolot);
//
//					samolotyOdWplaty += 1;
//					wyprodukowaneSamoloty += 1;
//
//				}
//				// Przy braku srodkow wymagane jest uiszczenie oplaty od klienta za juz wyprodukowane samoloty
//				catch (std::exception& exc)
//				{
//					std::cout << "  Wyprodukowano " << samolotyOdWplaty << " samolotow przed koniem srodkow." << std::endl;
//
//					fabryka.OdnowSrodki(samolot.ZwrocCene() * samolotyOdWplaty);
//					std::cout << "    Srodki fabryki po wplacie od klienta: " << fabryka.ZwrocSrodki() << std::endl;
//
//					samolotyOdWplaty = 0;
//				}
//			}
//
//
//			fabryka.OdnowSrodki(samolot.ZwrocCene() * samolotyOdWplaty);
//			std::cout << std::endl;
//			std::cout << "Wyprodukowano " << wyprodukowaneSamoloty << " samolotow" << std::endl;
//			std::cout << "  Ostateczne srodki: " << fabryka.ZwrocSrodki() << std::endl;
//			std::cout << std::endl;
//			std::cout << std::endl;
//
//			for (int j = 0; j < SamolotyDoWyprodukowania; ++j)
//				delete noweSamoloty[j];
//
//			delete &samolot;
//		}
//	}



	return 0;
}