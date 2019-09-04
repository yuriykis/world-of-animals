#pragma once
#include "Swiat.h"
  class Organizmy
{

protected: 
	int sila;
	int inicjatywa;
	struct Polozenie {
		int x;
		int y;
	}polozenie;

	char symbol;
	Swiat& swiat;

	virtual void kolizja(char, int, int);
	virtual void rysowanie();

public:
	virtual void akcja(int, bool);
	int getX();
	int getY();
	int getSila();
	char getSymbol();
	int getInicjatywa();

	Organizmy(Swiat&, int, int, char, int, int);
	~Organizmy();
};

