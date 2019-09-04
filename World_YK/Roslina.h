#pragma once
#include "Organizmy.h"
#include <time.h>
#include <stdlib.h>
#define GORA 1
#define DOL 2
#define PRAWO 3
#define LEWO 4
class Roslina :
	public Organizmy
{

public:
	void akcja(int, bool) override;
	Roslina(Swiat&, int, int, char, int, int);
	~Roslina();
};

