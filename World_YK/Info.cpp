#include "Info.h"
#include "Organizmy.h"
#include <iostream>
using namespace std;

void Info::dodaj_info(string text)
{
	this->info.push(text);
}

void Info::pisz_text()
{
	while (!info.empty()) {
		cout << info.front() << " ";
		this->info.pop();
	}

	while (!info.empty()) {
		info.pop();
	}
}

void Info::wynik_walki(char zwyciezca, char zabity)
{
	string text;
	text += ustal_organizm(zwyciezca);
	text += "zabil";
	text += ustal_organizm(zabity);
	text += "\n";
	this->dodaj_info(text);

}

void Info::wynik_rozmnazania(char org)
{
	string text;
	text += ustal_organizm(org);
	text += "rozmnozyl sie!\n";
	this->dodaj_info(text);
}

string Info::ustal_organizm(char znak) {

	string text;
	switch (znak)
	{
	case WILK:
		text = " zwierze Wilk ";
			break;
	case LIS:
		text = " zwierze Lis ";
			break;
	case OWCA:
		text = " zwierze Owca ";
		break;
	case ANTYLOPA:
		text = " zwierze Antylopa ";
		break;
	case ZOLW:
		text = " zwierze Zolw ";
		break;
	case CYBEROWCA:
		text = " zwierze Cyberowca ";
		break;
	case MLECZ:
		text = " Mlecz ";
		break;
	case TRAWA:
		text = "  Trawa ";
		break;
	case WILCZE_JAGODY:
		text = " Wilcze Jagody ";
		break;
	case BARSZCZ:
		text = " Barszcz ";
		break;
	case GUARANA:
		text = " Guarana ";
		break;
	case CZLOWIEK:
		text = " Czlowiek ";
	default:
		break;
	}
	return text;
}

void Info::spec_um(bool czy_wlaczona, bool czy_mozna_wlaczyc) {
	
	string text;
	if (czy_mozna_wlaczyc == false) {
		text += "Nie mozna wlaczyc specjalnej umiejetnosci\n";
	} else

	if (czy_wlaczona) {
		text += "Specjalna umiejetnosc jest wlaczona\n";
	}
	else  {
		text += "Specjalna umiejetnosc jest wylaczona\n";
	} 

	this->dodaj_info(text);
	
}
void Info::zapis_gry() {
	string text;
	text += "Gra zostala zapisana";
	this->dodaj_info(text);
}

void Info::odczyt_gry() {
	string text;
	text += "Gra zostala odczytana";
	this->dodaj_info(text);
}

Info::Info()
{
}


Info::~Info()
{
}
