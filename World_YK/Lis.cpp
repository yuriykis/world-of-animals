#include "Lis.h"



Lis::Lis(Swiat& swiatRef, int sila, int inicjatywa, char symbol, int x, int y) :
	Zwierze(swiatRef, sila, inicjatywa, symbol, x, y)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol = symbol;
	this->polozenie.x = x;
	this->polozenie.y = y;
}
void Lis::akcja(int strona, bool)
{
	char znak;
	switch (strona)
	{
	case GORA:
		znak = swiat.getSymbolPole(polozenie.x, polozenie.y - 1);
		if (znak != PUSTE && znak != SCIANA) {
			if (swiat.getSilaOrganizm(polozenie.x, polozenie.y - 1) <= this->getSila()) {
				kolizja(znak, polozenie.x, polozenie.y - 1);
			} else 
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
			if (swiat.getSilaOrganizm(polozenie.x + 1, polozenie.y) <= this->getSila()) {
				kolizja(znak, polozenie.x, polozenie.y - 1);
			}
			else
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
			if (swiat.getSilaOrganizm(polozenie.x, polozenie.y + 1) <= this->getSila()) {
				kolizja(znak, polozenie.x, polozenie.y - 1);
			}
			else
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
			if (swiat.getSilaOrganizm(polozenie.x + 1, polozenie.y) <= this->getSila()) {
				kolizja(znak, polozenie.x, polozenie.y - 1);
			}
			else
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


Lis::~Lis()
{
}
