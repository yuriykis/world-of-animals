#include "Wilk.h"



Wilk::Wilk(Swiat& swiatRef, int sila, int inicjatywa, char symbol, int x, int y) :
	Zwierze(swiatRef, sila, inicjatywa, symbol, x, y)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol = symbol;
	this->polozenie.x = x;
	this->polozenie.y = y;
}


Wilk::~Wilk()
{
}
