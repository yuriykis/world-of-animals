#pragma once
#include <string>
#include <queue>
using namespace std;

class Organizmy;
class Info
{
private:
	queue<string> info;
	void dodaj_info(string);

public:
	void pisz_text();
	void wynik_walki(char, char);
	void wynik_rozmnazania(char);
	void spec_um(bool,bool);
	void zapis_gry();
	void odczyt_gry();
	string ustal_organizm(char);
	Info();
	~Info();
};

