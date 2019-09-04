#include "Swiat.h"
#include "Organizmy.h"
#include "Zwierze.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Cyberowca.h"
#include "Owca.h"
#include "Zolw.h"
#include "Lis.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcze_jagody.h"
#include "Barszcz_Sosnowskiego.h"
#include "Czlowiek.h"

#include <conio.h>
#include <fstream>
using namespace std;

Swiat::Swiat()
{
	
}

int Swiat::getSilaOrganizm(int x, int y)
{
	for (vector<Organizmy*>::iterator i = organizmy.begin(); i < organizmy.end(); i++) {
		if ((*i)->getX() == x && (*i)->getY() == y) {
			return (*i)->getSila();
		}
	}
	return BRAK;
}

char Swiat::getSymbolPole(int x, int y)
{
	return plansza[y][x];
}


void Swiat::start()
{
	cout << "Podaj rozmiar planszy (X, Y):" << endl;
	cin >> rozmiar_X >> rozmiar_Y;
	utworzSwiat();
	rysujSwiat();
	tura();
}

void Swiat::utworzSwiat()
{
	
	plansza = new string[rozmiar_Y + GRUB_SCIAN];
	for (int i = 0; i < rozmiar_Y + GRUB_SCIAN; i++) {
		plansza[i] = new char[rozmiar_X + GRUB_SCIAN];
		for (int j = 0; j < rozmiar_X + GRUB_SCIAN; j++) {
			if (i < GRUB_SCIAN || j < GRUB_SCIAN || i >= rozmiar_Y  || j >= rozmiar_X) {
				plansza[i][j] = SCIANA;
			}
			else plansza[i][j] = PUSTE;
		}
	}
	dodajZwierze();
	dodajRosline();
}


void Swiat::rysujSwiat()
{
	system("cls");
	for (int i = 0; i < rozmiar_Y + GRUB_SCIAN; i++) {
		for (int j = 0; j < rozmiar_X + GRUB_SCIAN; j++) {
			cout << plansza[i][j];
		} cout << endl;
	}
}

void Swiat::dodajZwierze()
{	
	srand(time(NULL));
	for (int i = 0; i < LICZBA_ZWIERZ + 1; i++) {
		int x = rand() % (rozmiar_X-GRUB_SCIAN) + GRUB_SCIAN;
		int y = rand() % (rozmiar_Y-GRUB_SCIAN) + GRUB_SCIAN;

		if (plansza[y][x] != PUSTE) {
			i--;
			continue;
		}

		if (i == LICZBA_ZWIERZ) {
			Czlowiek* cz = new Czlowiek(*this, 6, 10, CZLOWIEK, x, y);
			organizmy.push_back(cz);
			plansza[y][x] = cz->getSymbol();
		}
		else {
			int los = rand() % 6 + 1;
			char symbol;
			switch (los)
			{
			case 1:
				symbol = WILK;
				break;
			case 2:
				symbol = LIS;
				break;
			case 3:
				symbol = OWCA;
				break;
			case 4:
				symbol = ANTYLOPA;
				break;
			case 5: 
				symbol = ZOLW;
				break;
			case 6:
				symbol = CYBEROWCA;
				break;
			default:
				break;
			}
			miejsce* m = new miejsce;
			m->x = x;
			m->y = y;

			dodajOrganizm(symbol, m);

		}
	}

}

void Swiat::dodajRosline()
{
	for (int i = 0; i < LICZBA_ROSL; i++) {
		int x = rand() % (rozmiar_X - GRUB_SCIAN) + GRUB_SCIAN;
		int y = rand() % (rozmiar_Y - GRUB_SCIAN) + GRUB_SCIAN;
		if (plansza[y][x] != PUSTE) {
			i--;
			continue;
		}
		int los = rand() % 5 + 1;
		char symbol;
		switch (los)
		{
		case 1:
			symbol = TRAWA;
			break;
		case 2:
			symbol = MLECZ;
			break;
		case 3:
			symbol = GUARANA;
			break;
		case 4:
			symbol = WILCZE_JAGODY;
			break;
		case 5:
			symbol = BARSZCZ;
			break;
		default:
			break;
		}
		miejsce* m = new miejsce;
		m->x = x;
		m->y = y;

		dodajOrganizm(symbol, m);

	}

}


void Swiat::dodajOrganizm(char symbol, miejsce* m)
{
	Organizmy* z;
	switch (symbol)
	{
	case WILK:
		z = new Wilk(*this, 9, 5, WILK, m->x, m->y);
		break;
	case LIS:
		z = new Lis(*this, 3, 7, LIS, m->x, m->y);
		break;
	case OWCA:
		z = new Owca(*this, 4, 4, OWCA, m->x, m->y);
		break;
	case ANTYLOPA:
		z = new Antylopa(*this, 4, 4, ANTYLOPA, m->x, m->y);
		break;
	case ZOLW:
		z = new Zolw(*this, 2, 1, ZOLW, m->x, m->y);
		break;
	case CYBEROWCA:
		z = new Cyberowca(*this, 11, 4, CYBEROWCA, m->x, m->y);
		break;
	case TRAWA:
		z = new Guarana(*this, 0, 0, TRAWA, m->x, m->y);
		break;
	case MLECZ:
		z = new Mlecz(*this, 0, 0, MLECZ, m->x, m->y);
		break;
	case GUARANA:
		z = new Guarana(*this, 0, 0, GUARANA, m->x, m->y);
		break;
	case WILCZE_JAGODY:
		z = new Wilcze_jagody(*this, 99, 0, WILCZE_JAGODY, m->x, m->y);
		break;
	case BARSZCZ:
		z = new Barszcz_Sosnowskiego(*this, 100, 0, BARSZCZ, m->x, m->y);
		break;
	default:
		z = NULL;
		break;
	}
	
	if (z) {
		plansza[m->y][m->x] = z->getSymbol();
		organizmy.push_back(z);
	}
	else {
		throw "Error";
	}
}

void Swiat::usunOrganizm(int x, int y)
{
	for (vector<Organizmy*>::iterator i = organizmy.begin(); i < organizmy.end(); i++) {
		if ((*i)->getX() == x && (*i)->getY() == y) {
			organizmy_usun.push_back(*i);
			plansza[y][x] = PUSTE;
			return;
		}
	}
}


void Swiat::dodajOrganizm_nowy(char symbol, miejsce* m)
{
	Organizmy* z;
	switch (symbol)
	{
	case WILK:
		z = new Wilk(*this, 9, 5, WILK, m->x, m->y);
		break;
	case LIS:
		z = new Lis(*this, 3, 7, LIS, m->x, m->y);
		break;
	case OWCA:
		z = new Owca(*this, 4, 4, OWCA, m->x, m->y);
		break;
	case ANTYLOPA:
		z = new Antylopa(*this, 4, 4, ANTYLOPA, m->x, m->y);
		break;
	case ZOLW:
		z = new Zolw(*this, 2, 1, ZOLW, m->x, m->y);
		break;
	case CYBEROWCA:
		z = new Cyberowca(*this, 11, 4, CYBEROWCA, m->x, m->y);
		break;
	case TRAWA:
		z = new Guarana(*this, 0, 0, TRAWA, m->x, m->y);
		break;
	case MLECZ:
		z = new Mlecz(*this, 0, 0, MLECZ, m->x, m->y);
		break;
	case GUARANA:
		z = new Guarana(*this, 0, 0, GUARANA, m->x, m->y);
		break;
	case WILCZE_JAGODY:
		z = new Wilcze_jagody(*this, 99, 0, WILCZE_JAGODY, m->x, m->y);
		break;
	case BARSZCZ:
		z = new Barszcz_Sosnowskiego(*this, 10, 0, BARSZCZ, m->x, m->y);
		break;
	default:
		z = NULL;
		break;
	}

	if (z) {
		plansza[m->y][m->x] = z->getSymbol();
		organizmy_nowe.push_back(z);
	}
	else {
		throw "Error";
	}
}


miejsce Swiat::znajdz_puste(int x, int y)
{
	miejsce m;
	for (int i = -1; i < 2; i++, y++) {
		for (int j = -1; j < 2; j++, x++) {
			if (x < rozmiar_X && y < rozmiar_Y) {
				if (plansza[y][x] == PUSTE) {
					m.x = x;
					m.y = y;
					return m;
				}
				else continue;
			}
		}
	}
	m.x = BRAK;
	m.y = BRAK;
	return m;
}

miejsce Swiat::szukaj_barszcz()
{
	miejsce m;
	for (int i = GRUB_SCIAN; i < rozmiar_Y; i++) {
		for (int j = GRUB_SCIAN; j < rozmiar_X; j++) {
			if (plansza[i][j] == BARSZCZ) {
				m.x = j;
				m.y = i;
				return m;
			}
		}
	}
	m.x = BRAK;
	m.y = BRAK;
	return m;
}

bool Swiat::czy_czlowiek_zyje() {
	for (vector<Organizmy*>::iterator i = organizmy.begin(); i < organizmy.end(); i++) {
		if ((*i)->getSymbol() == CZLOWIEK) {
			return true;
		}
	}
	return false;
}


void Swiat::wlacz_umiejetnosc(bool* spec, int* licznik_true, int* licznik_false) {

	if (*spec) {
		if ((*licznik_true) == 5) {
			(*licznik_true) = 0;
			(*spec) = false;
			info.spec_um(false, true);
		}
		else
			(*licznik_true)++;
		(*licznik_false)++;
	}
	else {
		(*licznik_false)++;
	}
}

void Swiat::tura()
{

	int znak, licznik_true = 0, licznik_false = 10;
	bool spec = false;
	while (znak = _getch()) {

		if (znak == 224) {
			znak = _getch();
			if (znak == 0x48) {
				if (czy_czlowiek_zyje()) {
					wlacz_umiejetnosc(&spec, &licznik_true, &licznik_false);
				}
				organizmy_akcja(GORA, spec);
				rysujSwiat();
				info.pisz_text();
			}
			else if (znak == 0x50) {
				if (czy_czlowiek_zyje()) {
					wlacz_umiejetnosc(&spec, &licznik_true, &licznik_false);
				}
				organizmy_akcja(DOL, spec);
				rysujSwiat();
				info.pisz_text();
			}
			else if (znak == 0x4b) {
				if (czy_czlowiek_zyje()) {
					wlacz_umiejetnosc(&spec, &licznik_true, &licznik_false);
				}wlacz_umiejetnosc(&spec, &licznik_true, &licznik_false);
				organizmy_akcja(LEWO, spec);
				rysujSwiat();
				info.pisz_text();
			}
			else if (znak == 0x4d) {
				if (czy_czlowiek_zyje()) {
					wlacz_umiejetnosc(&spec, &licznik_true, &licznik_false);
				}
				organizmy_akcja(PRAWO, spec);
				rysujSwiat();
				info.pisz_text();
			}
			
		}
		else if (znak == 110) {
			if (czy_czlowiek_zyje()) {
				if (licznik_false < 5) {
					info.spec_um(true, true);
				}
				else
					if (licznik_false < 10) {
						info.spec_um(true, false);
					}
					else {
						spec = true;
						info.spec_um(true, true);
						licznik_false = 0;
					}

					info.pisz_text();

			}
			else
				continue;
		}
		else if (znak == 115) {
			zapis_gry();
			info.zapis_gry();
			info.pisz_text();
		}
		else if (znak == 108) {
			odczyt_gry();
			info.odczyt_gry();
			info.pisz_text();
		 }
		
		else if (znak == 27) {
			exit(0);
		}
	}

}

void Swiat::zapis_gry() {
	
	fstream plik;
	plik.open("plansza.txt", ios::out);

	if (plik.good()) {
		for (int i = 0; i < rozmiar_Y + GRUB_SCIAN; i++) {
			for (int j = 0; j < rozmiar_X + GRUB_SCIAN; j++) {
				plik << plansza[i][j];
			} plik << endl;
		}
	}
	else {
		throw "Nie udalo sie otworzyc plik";
	}
	plik.close();
}

void Swiat::odczyt_gry() {

	fstream plik;
	plik.open("plansza.txt", ios::in);
	if (plik.good()) {

		string line;
		rozmiar_Y = -2;
		while (getline(plik, line)) {
			rozmiar_Y++;
		}

		plik.clear();
		plik.seekg(0, ios::beg);

		plansza = new string[rozmiar_Y + GRUB_SCIAN];
		for (int i = 0; i < rozmiar_Y + GRUB_SCIAN; i++) {
					getline(plik, plansza[i]);
					if (i == 0) {
						rozmiar_X = plansza[i].length() - GRUB_SCIAN;
					}
		}

		organizmy.clear();
		for (int i = 0; i < rozmiar_Y + GRUB_SCIAN; i++) {
			for (int j = 0; j < rozmiar_X + GRUB_SCIAN; j++) {

				if (plansza[i][j] == CZLOWIEK) {
					Czlowiek* cz = new Czlowiek(*this, 6, 10, CZLOWIEK, j, i);
					organizmy.push_back(cz);
				} else
				if (plansza[i][j] != SCIANA && plansza[i][j] != PUSTE) {
					miejsce m;
					m.x = j;
					m.y = i;
					dodajOrganizm_nowy(plansza[i][j], &m);
				}
			}
		}
		rysujSwiat();
	}
	else {
		throw "Nie udalo sie otworzyc plik";
	}
	plik.close();
}

vector<Organizmy*>::iterator Swiat::usuwanie(vector<Organizmy*>::iterator i) {
	for (vector<Organizmy*>::iterator j = organizmy.begin(); j < organizmy.end(); j++) {
		if ((*j) == (*i)) {
			return j;
		}
	}
	return organizmy.end();
}

void Swiat::organizmy_akcja(int strona_czlowiek, bool spec_cz) {
	for (vector<Organizmy*>::iterator i = organizmy.begin(); i < organizmy.end(); i++) {
		if ((*i)->getSymbol() == CZLOWIEK) {
			(*i)->akcja(strona_czlowiek, spec_cz);
			plansza[(*i)->getY()][(*i)->getX()] = (*i)->getSymbol();
		}
		else {
			int strona = rand() % 4 + 1;
			(*i)->akcja(strona, true);
			int x = (*i)->getX();
			int y = (*i)->getY();
			plansza[y][x] = (*i)->getSymbol();
		}
	}
	if (!organizmy_nowe.empty()) {
		for (vector<Organizmy*>::iterator i = organizmy_nowe.begin(); i < organizmy_nowe.end(); i++) {
			organizmy.push_back(*i);
		}
		organizmy_nowe.clear();
	}

	if (!organizmy_usun.empty()) {
		for (vector<Organizmy*>::iterator i = organizmy_usun.begin(); i < organizmy_usun.end(); i++) {
			vector<Organizmy*>::iterator iter = usuwanie(i);
			if (iter != organizmy.end()) {
				plansza[(*iter)->getY()][(*iter)->getX()] = PUSTE;
				organizmy.erase(iter);
			}
			else continue;
		} organizmy_usun.clear();
	}

}

bool Swiat::zmiana_miejsca(int strona, int x, int y, int krok) {
	switch (strona)
	{
	case GORA:
		if (plansza[y - krok][x] == PUSTE) {
			plansza[y][x] = PUSTE;
			return true;
		}
		return false;
	case DOL:
		if (plansza[y + krok][x] == PUSTE) {
			plansza[y][x] = PUSTE;
			return true;
		}
		return false;
	case PRAWO:
		if (plansza[y][x + krok] == PUSTE) {
			plansza[y][x] = PUSTE;
			return true;
		}
		return false;
	case LEWO:
		if (plansza[y][x - krok] == PUSTE) {
			plansza[y][x] = PUSTE;
			return true;
		}
		return false;
	default:
		return false;
	}
}


Swiat::~Swiat()
{
	delete[] plansza;
}
