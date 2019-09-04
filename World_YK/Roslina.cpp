#include "Roslina.h"



void Roslina::akcja(int strona, bool)
{
	char znak;
	strona = rand() % 100 + 1;
	if (strona == GORA) {
		znak = swiat.getSymbolPole(polozenie.x, polozenie.y - 1);
		if (znak == PUSTE) {
			miejsce m;
			m.x = polozenie.x;
			m.y = polozenie.y - 1;
			swiat.dodajOrganizm_nowy(this->getSymbol(), &m);
			swiat.info.wynik_rozmnazania(this->getSymbol());
		}
	} else if (strona == DOL) {
		znak = swiat.getSymbolPole(polozenie.x, polozenie.y + 1);
		if (znak == PUSTE) {
			miejsce m;
			m.x = polozenie.x;
			m.y = polozenie.y + 1;
			swiat.dodajOrganizm_nowy(this->getSymbol(), &m);
			swiat.info.wynik_rozmnazania(this->getSymbol());
		}
	}
	else if (strona == PRAWO) {
		znak = swiat.getSymbolPole(polozenie.x + 1, polozenie.y);
		if (znak == PUSTE) {
			miejsce m;
			m.x = polozenie.x + 1;
			m.y = polozenie.y;
			swiat.dodajOrganizm_nowy(this->getSymbol(), &m);
			swiat.info.wynik_rozmnazania(this->getSymbol());
		}
	}
	else if (strona == LEWO) {
		znak = swiat.getSymbolPole(polozenie.x - 1, polozenie.y);
		if (znak == PUSTE) {
			miejsce m;
			m.x = polozenie.x - 1;
			m.y = polozenie.y;
			swiat.dodajOrganizm_nowy(this->getSymbol(), &m);
			swiat.info.wynik_rozmnazania(this->getSymbol());
		}
	}
	else {
		return;
	}
}

Roslina::Roslina(Swiat& swiatRef, int sila, int inicjatywa, char symbol, int x, int y):
	Organizmy(swiatRef, sila, inicjatywa, symbol, x, y)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol = symbol;
	this->polozenie.x = x;
	this->polozenie.y = y;
}


Roslina::~Roslina()
{
}
