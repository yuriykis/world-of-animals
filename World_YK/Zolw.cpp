#include "Zolw.h"



void Zolw::kolizja(char znak, int x, int y)
{
	if (znak == this->getSymbol()) {
		miejsce m = swiat.znajdz_puste(x, y);
		if (m.x != BRAK && m.y != BRAK) {
			swiat.dodajOrganizm_nowy(znak, &m);
			swiat.info.wynik_rozmnazania(znak);
		}
	}
	else {
		if (swiat.getSilaOrganizm(x, y) < 5) {
			return;
		}
		else if (this->getSila() > swiat.getSilaOrganizm(x, y)) {
			swiat.info.wynik_walki(this->getSymbol(), swiat.getSymbolPole(x, y));
			swiat.usunOrganizm(x, y);
		}
		else {
			swiat.info.wynik_walki(swiat.getSymbolPole(x, y), this->getSymbol());
			swiat.usunOrganizm(this->getX(), this->getY());
		}
	}
}

void Zolw::akcja(int strona, bool)
{
	char znak;
	strona = rand() % 16 + 1;
	switch (strona)
	{
	case GORA:
		znak = swiat.getSymbolPole(polozenie.x, polozenie.y - 1);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x, polozenie.y - 1);
			break;
		}
		else if (znak == PUSTE) {
			swiat.zmiana_miejsca(GORA, polozenie.x, polozenie.y, 1);
			polozenie.y--;
			break;
		}
		break;
	case PRAWO:
		znak = swiat.getSymbolPole(polozenie.x + 1, polozenie.y);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x + 1, polozenie.y);
			break;
		}
		else if (znak == PUSTE) {
			swiat.zmiana_miejsca(PRAWO, polozenie.x, polozenie.y, 1);
			polozenie.x++;
			break;
		}
		break;
	case DOL:
		znak = swiat.getSymbolPole(polozenie.x, polozenie.y + 1);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x, polozenie.y + 1);
			break;
		}
		else if (znak == PUSTE) {
			swiat.zmiana_miejsca(DOL, polozenie.x, polozenie.y, 1);
			polozenie.y++;
			break;
		}
		break;
	case LEWO:
		znak = swiat.getSymbolPole(polozenie.x - 1, polozenie.y);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x - 1, polozenie.y);
			break;
		}
		else if (znak == PUSTE) {
			swiat.zmiana_miejsca(LEWO, polozenie.x, polozenie.y, 1);
			polozenie.x--;
			break;
		}
		break;
	default:
		break;
	}
}

Zolw::Zolw(Swiat& swiatRef, int sila, int inicjatywa, char symbol, int x, int y) :
	Zwierze(swiatRef, sila, inicjatywa, symbol, x, y)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol = symbol;
	this->polozenie.x = x;
	this->polozenie.y = y;
}



Zolw::~Zolw()
{
}
