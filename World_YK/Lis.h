#pragma once
#include "Zwierze.h"
class Lis :
	public Zwierze
{
private:
public:
	Lis(Swiat&, int, int, char, int, int);
	void akcja(int, bool) override;
	~Lis();
};

