#pragma once
#include "Zwierze.h"
class Zolw :
	public Zwierze
{
protected:
	void kolizja(char, int, int) override;
public:
	void akcja(int, bool) override;
	Zolw(Swiat&, int, int, char, int, int);
	~Zolw();
};

