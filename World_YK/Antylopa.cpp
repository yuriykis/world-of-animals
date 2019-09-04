#include "Antylopa.h"



void Antylopa::akcja(int strona, bool)
{
	char znak;
	switch (strona)
	{
	case GORA:
		znak = swiat.getSymbolPole(polozenie.x, polozenie.y - 2);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x, polozenie.y - 2);
			break;
		}
		else if (znak == PUSTE) {
			if (swiat.zmiana_miejsca(GORA, polozenie.x, polozenie.y, 2)) {
				polozenie.y -= 2;
			}
			break;
		}
		else if (znak == SCIANA) {
			break;
		}
		else break;
	case PRAWO:
		znak = swiat.getSymbolPole(polozenie.x + 2, polozenie.y);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x + 2, polozenie.y);
			break;
		}
		else if (znak == PUSTE) {
			if (swiat.zmiana_miejsca(PRAWO, polozenie.x, polozenie.y, 2)) {
				polozenie.x += 2;
			}
			break;
		}
		else if (znak == SCIANA) {
			break;
		}
		else break;
	case DOL:
		znak = swiat.getSymbolPole(polozenie.x, polozenie.y + 2);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x, polozenie.y + 2);
			break;
		}
		else if (znak == PUSTE) {
			if (swiat.zmiana_miejsca(DOL, polozenie.x, polozenie.y, 2)) {
				polozenie.y+=2;
			}
			break;
		}
		else if (znak == SCIANA) {
			break;
		}
		else break;
	case LEWO:
		znak = swiat.getSymbolPole(polozenie.x - 2, polozenie.y);
		if (znak != PUSTE && znak != SCIANA) {
			kolizja(znak, polozenie.x - 2, polozenie.y);
			break;
		}
		else if (znak == PUSTE) {
			if (swiat.zmiana_miejsca(LEWO, polozenie.x, polozenie.y, 2)) {
				polozenie.x-=2;
			}
			break;
		}
		else if (znak == SCIANA) {
			break;
		}
		else break;
	default:
		break;
	}
}

Antylopa::Antylopa(Swiat& swiatRef, int sila, int inicjatywa, char symbol, int x, int y):
	Zwierze(swiatRef, sila, inicjatywa, symbol, x, y)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol = symbol;
	this->polozenie.x = x;
	this->polozenie.y = y;
}


Antylopa::~Antylopa()
{
}
