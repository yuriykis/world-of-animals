#include "Organizmy.h"

void Organizmy::akcja(int, bool)
{

}

void Organizmy::kolizja(char znak, int x, int y)
{
}

void Organizmy::rysowanie()
{
}

int Organizmy::getSila()
{
	return sila;
}


char Organizmy::getSymbol()
{
	return symbol;
}

int Organizmy::getInicjatywa()
{
	return inicjatywa;
}


int Organizmy::getX()
{
	return polozenie.x;
}

int Organizmy::getY()
{
	return polozenie.y;
}

Organizmy::Organizmy(Swiat& swiatRef, int sila, int inicjatywa, char symbol, int x, int y) :
	swiat(swiatRef)
{
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->symbol = symbol;
	this->polozenie.x = x;
	this->polozenie.y = y;
}


Organizmy::~Organizmy()
{
}
