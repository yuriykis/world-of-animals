#pragma once
#include "Zwierze.h"
class Czlowiek :
	public Zwierze
{
private:
	void specjalna_umiejetnosc(bool);
public:
	void akcja(int, bool) override;
	Czlowiek(Swiat&, int, int, char, int, int);
	~Czlowiek();
};

