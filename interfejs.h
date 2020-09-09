#include <iostream>
#include <string>

using namespace std;

class Historie;

class Menu
{
public:

    char wyb_menu;
    bool op_prog;

    void intro();
    void start();
    void nowa_gra();
    void wczytaj_gre();
    void opcje();
    void o_grze();
    void samouczek();

    friend int main();
    friend void menu(Menu *wskaznik_menu);

    Menu(char='x', bool=0);
};

class Wioska
{
protected:

    string imie;
    int dni;
    int dre;
    int kam;
    int zel;
    int warz;
    int mie;
    int bro;
    int lud;
    int woj;
    int rol;
    int atk;
    int obr;
    int b_mur;
    int b_kopalnia;
    int b_lowczy;
    int b_chata;
    int b_drwal;
    int b_koszary;
    int b_jaskinia;
    int b_pola;
    int b_uleczyciel;
    int b_domy;
    int p_kilof;
    int p_siekiera;
    int p_motyka;
    int p_luki;
    int ranni;
    short odl_ranni;
    short jedzenie_na_minusie;

    char wyb_wioska;

    bool wioska_op_prog;

public:

    void surki_interfejs();
    void wioska_menu();
    void wioska_mur();
    void wioska_kopalnia();
    void wioska_lowczy();
    void wioska_chata();
    void wioska_drwal();
    void wioska_koszary();
    void wioska_jaskinia();
    void wioska_pola();
    void wioska_uleczyciel();
    void wioska_domy();

    friend int main();
    friend void Menu::wczytaj_gre();
    friend void menu_gry(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie);
    friend void koniec_walki(short koniec_ranni, short koniec_zabici, Wioska *wskaznik_wioska);
    friend void funkcja_wioska(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie);

    Wioska(string="-", int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, int=0, short=0, short=0, bool=0);
};

