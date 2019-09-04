#pragma once
#include "Zwierze.h"
class Antylopa :
	public Zwierze
{

	
public:
	void akcja(int, bool) override;
	Antylopa(Swiat&, int, int, char, int, int);
	~Antylopa();
};

