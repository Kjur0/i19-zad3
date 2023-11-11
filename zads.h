#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>

using namespace std;

typedef struct {
	wstring Imie;
	wstring Nazwisko;
	wstring Klasa;
} Uczen;

void zad1() {
	Uczen u;
	int n;

	wcout << L"Ile uczniów chcesz wprowadziæ?";

	do {
		wcout << endl << L"Podaj liczbê wiêksz¹ od 0: ";
		wcin >> n;
	} while ( n < 1 );


	wofstream plik("uczniowie.txt");
	for ( int i = 0; i < n; i++ ) {
		wcout << L"Podaj imiê ucznia: ";
		wcin >> u.Imie;
		wcout << L"Podaj nazwisko ucznia: ";
		wcin >> u.Nazwisko;
		wcout << L"Podaj klase ucznia: ";
		wcin >> u.Klasa;
		plik << u.Imie << L" " << u.Nazwisko << L" " << u.Klasa << endl;
	}
	plik.close();
}

void zad2() {
	Uczen uczen;

	wofstream plik("uczniowie.csv", ios_base::app);

	wchar_t c;
	do {
		wcout << L"Podaj imie ucznia: ";
		wcin >> uczen.Imie;
		wcout << L"Podaj nazwisko ucznia: ";
		wcin >> uczen.Nazwisko;
		wcout << L"Podaj klase ucznia: ";
		wcin >> uczen.Klasa;
		plik << uczen.Imie << L"," << uczen.Nazwisko << L"," << uczen.Klasa << endl;

		wcout << L"Czy chcesz dodaæ kolejnego ucznia? (t/n): ";
		wcin >> c;
	} while ( c != 'n' );

	plik.close();
}

void zad3() {
	wifstream plik("uczniowie.csv");

	wstring tmp;
	wstring linia;
	
	wcout << L"Uczniowie:" << endl;
	
	while ( getline(plik, linia) ) {
		tmp = linia.substr(0, linia.find(','));
		wcout << L"\t" << tmp;

		linia = linia.substr(linia.find(',') + 1);
		tmp = linia.substr(0, linia.find(','));
		wcout << L" " << tmp;

		linia = linia.substr(linia.find(',') + 1);
		tmp = linia;
		wcout << endl << L"\t\tKlasa: " << tmp << endl;
	}
	plik.close();
}