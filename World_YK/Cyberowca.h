#pragma once
#include "Zwierze.h"
class Cyberowca :
	public Zwierze
{
private:
	void cyberakcja(int, bool);
protected:
	void kolizja(char, int, int) override;
public:
	void akcja(int, bool) override;
	Cyberowca(Swiat&, int, int, char, int, int);
	~Cyberowca();
};

