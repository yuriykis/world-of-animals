#pragma once
#include "Organizmy.h"
#include <time.h>
#include <stdlib.h>
#define GORA 1
#define DOL 2
#define PRAWO 3
#define LEWO 4
class Zwierze :
	public Organizmy
{

protected:
	void kolizja(char, int, int) override;

public:
	void akcja(int, bool) override;
	Zwierze(Swiat&, int, int, char, int, int);
	~Zwierze();
};

