#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "Info.h"
#define STANDARD_X 20
#define STANDARD_Y 20
#define GRUB_SCIAN 2
#define SCIANA '.'
#define PUSTE ' '
#define LICZBA_ZWIERZ 20
#define LICZBA_ROSL 20
#define BRAK -1234
#define  WILK 'W'
#define LIS 'L'
#define OWCA 'O' 
#define ANTYLOPA 'A'
#define ZOLW 'Z'
#define CYBEROWCA 'C'
#define TRAWA 'T'
#define MLECZ 'M'
#define GUARANA 'G'
#define WILCZE_JAGODY 'J'
#define BARSZCZ 'B'
#define CZLOWIEK '@'


using namespace std;

struct miejsce {
	int x;
	int y;
};

class Swiat
{
private: 
	int rozmiar_X, rozmiar_Y;
	string* plansza;
	vector <Organizmy*> organizmy;
	vector <Organizmy*> organizmy_nowe;
	vector <Organizmy*> organizmy_usun;
	void utworzSwiat();
	void rysujSwiat();
	void dodajZwierze();
	void dodajRosline();
	void tura();
	void organizmy_akcja(int, bool);
	void dodajOrganizm(char, miejsce*);
	bool czy_czlowiek_zyje();
	void wlacz_umiejetnosc(bool*, int*, int*);
	void zapis_gry();
	void odczyt_gry();
	vector<Organizmy*>::iterator usuwanie(vector<Organizmy*>::iterator);

public:
	Swiat();
	Info info;
	int getSilaOrganizm(int,int);
	char getSymbolPole(int, int);
	bool zmiana_miejsca(int, int, int, int);
	void usunOrganizm(int, int);
	void dodajOrganizm_nowy(char, miejsce*);
	miejsce znajdz_puste(int,int);
	miejsce szukaj_barszcz();
	void start();
	
	~Swiat();
};

