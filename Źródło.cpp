#include "zads.h"

int main() {
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	int zad;
wyb:
	wcout << L"Podaj numer zadania: ";
	wcin >> zad;
	switch ( zad ) {
	case 1:
		zad1();
		break;
	case 2:
		zad2();
		break;
	case 3:
		zad3();
		break;
	default:
		wcout << L"Takie zadanie nie istnieje.";
		goto wyb;
		break;
	}

	wcout << endl << L"Aby zamkn¹æ program kliknij dowolny przycisk!";
	system("pause>nul");

	return 0;
}