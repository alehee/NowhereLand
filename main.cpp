#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "interfejs.h"
#include "historie.h"

using namespace std;
string ver = "2.0";

void banner_main()
{
    cout << "     *** Nowhere Land ***" << endl;
    cout << "  Competitive Edition v. " << ver << endl;
}

void koniec_walki(short koniec_ranni, short koniec_zabici, Wioska *wskaznik_wioska)
{
    short ilosc_mozliwych_osob_uleczyciel = wskaznik_wioska->b_domy*10 - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - wskaznik_wioska->ranni;
    short roznica_uleczyciela = 0;

    if(koniec_ranni==0 && koniec_zabici==0)
    {
        cout << endl;
        cout << "   # Gratulacje! W tej walce nikt nie ucierpial" << endl;
        cout << "   # Oprocz przeciwnika..." << endl;
    }

    else if((koniec_ranni+koniec_zabici)>0&&ilosc_mozliwych_osob_uleczyciel==0)
    {
        cout << endl;
        cout << "   # U Twojego uleczyciela nie ma miejsca!" << endl;
        cout << "   # Wszyscy Twoi ranni w tej walce ludzie umieraja!" << endl;
        cout << "   # Bylo ich az " << koniec_ranni + koniec_zabici << endl;
    }

    else if((koniec_ranni+koniec_zabici)>0&&ilosc_mozliwych_osob_uleczyciel!=0&&ilosc_mozliwych_osob_uleczyciel>=koniec_ranni&&wskaznik_wioska->b_uleczyciel!=0)
    {
        while(ilosc_mozliwych_osob_uleczyciel!=0 && koniec_ranni!=0)
        {
            koniec_ranni--;
            ilosc_mozliwych_osob_uleczyciel--;
            wskaznik_wioska->ranni++;
            roznica_uleczyciela++;
        }
        cout << endl;
        cout << "   # Twoi ranni (" << roznica_uleczyciela << ") trafili do uleczyciela!" << endl;
        cout << "   # Natomiast zginelo tylko " << koniec_zabici << endl;
        cout << "   # Masz szczescie!" << endl;
    }

    else if((koniec_ranni+koniec_zabici)>0&&ilosc_mozliwych_osob_uleczyciel!=0&&ilosc_mozliwych_osob_uleczyciel<koniec_ranni&&wskaznik_wioska->b_uleczyciel!=0)
    {
        while(ilosc_mozliwych_osob_uleczyciel!=0 && koniec_ranni!=0)
        {
            koniec_ranni--;
            ilosc_mozliwych_osob_uleczyciel--;
            wskaznik_wioska->ranni++;
            roznica_uleczyciela++;
        }
        cout << " # Twoi ranni (" << roznica_uleczyciela << ") trafili do uleczyciela!" << endl;
        cout << " # A dla " << koniec_ranni << " nie bylo miejsca i zgineli na pobojowisku!" << endl;
        cout << " # Natomiast zginelo tylko " << koniec_zabici << endl;
    }

    if(wskaznik_wioska->lud==0 && wskaznik_wioska->woj==0 && wskaznik_wioska->rol==0 && wskaznik_wioska->b_jaskinia>0)
    {
        float licznik;
        int przekaznik;

        cout << endl;
        cout << "   # Twoja wioska upadla, jednak w Twojej jaskini uchowalo sie troche surowcow" << endl;
        licznik = (wskaznik_wioska->dre)*(wskaznik_wioska->b_jaskinia*3)/100;
        przekaznik = licznik;
        wskaznik_wioska->dre = przekaznik;
        licznik = (wskaznik_wioska->kam)*(wskaznik_wioska->b_jaskinia*3)/100;
        przekaznik = licznik;
        wskaznik_wioska->kam = przekaznik;
        wskaznik_wioska->zel = 0;
        licznik = (wskaznik_wioska->warz)*(wskaznik_wioska->b_jaskinia*3)/100;
        przekaznik = licznik;
        wskaznik_wioska->warz = przekaznik;
        licznik = (wskaznik_wioska->mie)*(wskaznik_wioska->b_jaskinia*3)/100;
        przekaznik = licznik;
        wskaznik_wioska->mie = przekaznik;
        wskaznik_wioska->lud = 2;
    }
}

char slot_zapisu=0;
bool glowny=true;
void menu_gry(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie);
void funkcja_wioska(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie);

int main()
{
    system("color f");

    srand(time(NULL));
    Menu *menu = new Menu;
    Wioska *wioska = new Wioska;
    Historie *historie = new Historie;

    menu->intro();

    do{
    menu_gry(menu, wioska, historie);

    if(wioska->imie != "-" && wioska->dni != 0)
        funkcja_wioska(menu, wioska, historie);

    }while(glowny==true);

    delete menu;
    delete wioska;
    delete historie;

    return 0;
}

void menu_gry(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie)
{
    bool bool_menu=true;

    while(bool_menu==true)
    {
        wskaznik_menu->start();

        switch(wskaznik_menu->wyb_menu)
        {
            case 'a':{
                wskaznik_menu->nowa_gra();

                bool nowagra_czynapewno=true;
                fstream plik_nowagra;
                string bufor_nowagra1, bufor_nowagra2;

                slot_zapisu = wskaznik_menu->wyb_menu;

                if(slot_zapisu!='1' && slot_zapisu!='2' && slot_zapisu!='3')
                    bool_menu=false;

                if(slot_zapisu == '1')
                    plik_nowagra.open("save1.txt", ios::in | ios::out);

                if(slot_zapisu == '2')
                    plik_nowagra.open("save2.txt", ios::in | ios::out);

                if(slot_zapisu == '3')
                    plik_nowagra.open("save3.txt", ios::in | ios::out);

                    getline(plik_nowagra, bufor_nowagra1);
                    getline(plik_nowagra, bufor_nowagra2);

                plik_nowagra.close();
                wskaznik_menu->wyb_menu = 't';

                if(bufor_nowagra1!= "-" && bufor_nowagra2!= "0" && slot_zapisu == '1' || slot_zapisu == '2' || slot_zapisu == '3')
                {
                    while(nowagra_czynapewno==true)
                    {
                    system("cls");

                    banner_main();
                    cout << "             Nowa gra" << endl << endl;

                    cout << "  Ten slot jest juz zajety przez inny zapis" << endl;
                    cout << "  Czy na pewno chcesz go zastapic?" << endl << endl;

                    cout << "  Tak(t) / Nie(n)";
                    wskaznik_menu->wyb_menu = getch();

                    nowagra_czynapewno=false;
                    }
                }

                if(wskaznik_menu->wyb_menu == 't' && slot_zapisu == '1' || slot_zapisu == '2' || slot_zapisu == '3')
                {
                system("cls");

                banner_main();
                cout << "             Nowa gra" << endl << endl;

                cout << "  Podaj swoje imie: " << endl;
                cout << "  "; getline(cin, bufor_nowagra1);

                ofstream plik_autozapis;

                if(slot_zapisu == '1')
                    plik_autozapis.open("save1.txt");

                if(slot_zapisu == '2')
                    plik_autozapis.open("save2.txt");

                if(slot_zapisu == '3')
                    plik_autozapis.open("save3.txt");

                system("cls");
                cout << endl << "   Tworzenie "; Sleep(200);

                plik_autozapis << bufor_nowagra1 << endl;
                plik_autozapis << "1" << endl;
                plik_autozapis << "5" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "40" << endl;
                plik_autozapis << "30" << endl;
                plik_autozapis << "1" << endl;
                plik_autozapis << "5" << endl;
                plik_autozapis << "0" << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "1" << endl;
                plik_autozapis << "1" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "1" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "-15" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "0" << endl;
                plik_autozapis << "-1" << endl;

                cout << ". "; Sleep(200);

                plik_autozapis.close();

                string bufor_wczytywania;
                int bufor_int;
                fstream plik_wczytywania;
                short bufor_short;

                if(slot_zapisu == '1')
                    plik_wczytywania.open("save1.txt", ios::in | ios::out);

                if(slot_zapisu == '2')
                    plik_wczytywania.open("save2.txt", ios::in | ios::out);

                if(slot_zapisu == '3')
                    plik_wczytywania.open("save3.txt", ios::in | ios::out);

                if(plik_wczytywania.good() == true)
                {
                    getline(plik_wczytywania, bufor_wczytywania);
                    wskaznik_wioska->imie = bufor_wczytywania;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->dni = bufor_int;

                    if(wskaznik_wioska->imie=="-" && wskaznik_wioska->dni==0)
                    {
                        system("cls");
                        cout << "Brak zapisu w tym miejscu";
                        Sleep(2000);
                        break;
                    }

                    system("cls");
                    cout << endl << "   Wczytywanie ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->dre = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->kam = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->zel = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->warz = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->mie = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->bro = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->lud = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->woj = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->rol = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->atk = bufor_int;

                    system("cls");
                    cout << endl << "   Wczytywanie ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->obr = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_mur = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_kopalnia = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_lowczy = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_chata = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_drwal = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_koszary = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_jaskinia = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_pola = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_uleczyciel = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_domy = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_kilof = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_siekiera = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_motyka = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_luki = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_short = atoi(bufor_wczytywania.c_str());
                    wskaznik_historie->historia = bufor_short;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_short = atoi(bufor_wczytywania.c_str());
                    wskaznik_historie->odliczanie = bufor_short;
                }

                Sleep(500);

                plik_wczytywania.close();

                system("cls");
                cout << endl << "   ### Dzien 1 ###"; Sleep(1000);
                bool_menu=false;
                }

            } break;

            case 'b':{
                wskaznik_menu->wczytaj_gre();

                string bufor_wczytywania;
                int bufor_int;
                fstream plik_wczytywania;
                short bufor_short;

                slot_zapisu = wskaznik_menu->wyb_menu;

                if(slot_zapisu == '1')
                    plik_wczytywania.open("save1.txt", ios::in | ios::out);

                if(slot_zapisu == '2')
                    plik_wczytywania.open("save2.txt", ios::in | ios::out);

                if(slot_zapisu == '3')
                    plik_wczytywania.open("save3.txt", ios::in | ios::out);

                if(plik_wczytywania.good() == true && slot_zapisu == '1' || slot_zapisu == '2' || slot_zapisu == '3')
                {
                    getline(plik_wczytywania, bufor_wczytywania);
                    wskaznik_wioska->imie = bufor_wczytywania;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->dni = bufor_int;

                    if(wskaznik_wioska->imie=="-" && wskaznik_wioska->dni==0)
                    {
                        system("cls");
                        cout << endl;
                        cout << "   Brak zapisu w tym miejscu";
                        Sleep(2000);
                        break;
                    }

                    system("cls");
                    cout << endl;
                    cout << "   Wczytywanie ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->dre = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->kam = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->zel = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->warz = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->mie = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->bro = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->lud = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->woj = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->rol = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->atk = bufor_int;

                    system("cls");
                    cout << endl;
                    cout << "   Wczytywanie ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->obr = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_mur = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_kopalnia = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_lowczy = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_chata = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_drwal = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_koszary = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_jaskinia = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_pola = bufor_int;

                    cout << ". ";
                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_uleczyciel = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->b_domy = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_kilof = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_siekiera = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_motyka = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->p_luki = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_short = atoi(bufor_wczytywania.c_str());
                    wskaznik_historie->historia = bufor_short;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_short = atoi(bufor_wczytywania.c_str());
                    wskaznik_historie->odliczanie = bufor_short;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_int = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->ranni = bufor_int;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_short = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->odl_ranni = bufor_short;

                    getline(plik_wczytywania, bufor_wczytywania);
                    bufor_short = atoi(bufor_wczytywania.c_str());
                    wskaznik_wioska->jedzenie_na_minusie = bufor_short;

                    bool_menu=false;
                }

                Sleep(500);

                plik_wczytywania.close();
            } break;

            case 'c':{

                wskaznik_menu->opcje();

            } break;

            case 'd':{
                wskaznik_menu->o_grze();
            } break;

            case 'e':{
                wskaznik_menu->samouczek();
            } break;

            default:{
                do{
                system("cls");

                banner_main();
                cout << endl;
                cout << "  Czy na pewno chcesz wyjsc?" << endl << endl;

                cout << "  Tak(t) / Nie(n)";
                wskaznik_menu->wyb_menu = getch();

                if(wskaznik_menu->wyb_menu == 't')
                {
                    bool_menu=false;
                    glowny=false;
                }

                }while(wskaznik_menu->wyb_menu != 'n' && bool_menu == true);
            }
        }
    }
}

void funkcja_wioska(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie)
{
    bool bool_wioska=true;
    bool przeczytane=false;

    /* OPCJE */
    wskaznik_wioska->wioska_op_prog=wskaznik_menu->op_prog;

    do{
        if(wskaznik_wioska->odl_ranni==0&&wskaznik_wioska->ranni!=0)
        {
            if(wskaznik_wioska->b_uleczyciel<7)
                wskaznik_wioska->odl_ranni=5;
            if(wskaznik_wioska->b_uleczyciel>6&&wskaznik_wioska->b_uleczyciel<13)
                wskaznik_wioska->odl_ranni=4;
            if(wskaznik_wioska->b_uleczyciel>12&&wskaznik_wioska->b_uleczyciel<19)
                wskaznik_wioska->odl_ranni=3;
            if(wskaznik_wioska->b_uleczyciel>18&&wskaznik_wioska->b_uleczyciel<25)
                wskaznik_wioska->odl_ranni=2;
            if(wskaznik_wioska->b_uleczyciel>24)
                wskaznik_wioska->odl_ranni=1;
        }

        if(przeczytane==false)
        {
            system("cls");
            wskaznik_historie->czytanie=false;
            cout << endl << "   ### Dzien " << wskaznik_wioska->dni << " ###"; Sleep(1000);

            if(wskaznik_wioska->jedzenie_na_minusie>0)
            {
            wskaznik_historie->czytanie=true;
            cout << endl << endl;
            cout << "   # Twoi ludzie umieraja z glodu!" << endl;
            cout << "   # Kolejny czlowiek umrze za " << wskaznik_wioska->jedzenie_na_minusie << " tur jedzeniowych" << endl;
            cout << "   # (tura jedzeniowa to deficyt jednego z surowcow)" << endl;
            cout << "   # (deficyt warzywa = 1 tura jedzeniowa , deficyt miesa = 1 tura jedzeniowa , deficyt obu = 2 tury jedzeniowe)" << endl;
            }

            wskaznik_historie->wywolywacz();
            switch(wskaznik_historie->historia)
            {
                case 1:{ //ZO_choroba1
                    if(wskaznik_historie->odliczanie==5)
                    {
                        srand(time(NULL));
                        float *liczba_losowa = new float;
                        int *ucierpieli = new int;
                        float *ofiary = new float;
                        int *ratowanie = new int;

                        *ratowanie = 0;
                        *ucierpieli = 0;
                        *liczba_losowa = (std::rand() % 100)+1;
                        *ofiary = *liczba_losowa / 100;

                        if(*liczba_losowa<70-wskaznik_wioska->b_uleczyciel*2)
                        {
                            *ucierpieli = wskaznik_wioska->lud * *ofiary;
                            for(int i=*ucierpieli; i>0; i--)
                            {
                                *liczba_losowa = (std::rand() % 100) +1;
                                if(*liczba_losowa<=wskaznik_wioska->b_uleczyciel*3)
                                    (*ratowanie)+=1;
                            }
                            *ucierpieli -= (*ratowanie);
                        }

                        *liczba_losowa = *ofiary * 10;
                        cout << endl << endl;
                        cout << "   # W wyniku zarazy ucierpialo: " << *ucierpieli + *ratowanie << endl;
                        cout << "   # Jednak Twoj lekarz uleczyl: " << *ratowanie << endl;
                        cout << endl;
                        cout << "   # W sumie poniosles straty: " << *ucierpieli << ", niezle!";

                        wskaznik_wioska->lud -= *ucierpieli;

                        delete ratowanie;
                        delete ofiary;
                        delete liczba_losowa;
                        delete ucierpieli;
                    }
                } break;

                case 2:{ //ZM_wilki
                    if(wskaznik_historie->odliczanie==5)
                        {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));

                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 3;
                            short przeciwnicy_obrona = 1;

                            cout << endl;

                            if(liczba_losowa>50)
                                liczba_losowa -= 50;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Ich ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   WILKI: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   WILKI: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;
                            /*cout << "   # ZGINELO " << zabici << " Twoich ludzi, a " << ranni << " zraniono!" << endl;

                            cout << "   # DOPOKI NIE OGARNALEM ULECZYCIELA TWOI RANNI STAJA SIE NATYCHMIASTOWO LUDZMI!" << endl;
                            wskaznik_wioska->lud += ranni;*/
                            koniec_walki(ranni,zabici,wskaznik_wioska);
                        }
                } break;

                case 3:{ //ZM_umarlacy
                    if(wskaznik_historie->odliczanie==5)
                    {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));

                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 2;
                            short przeciwnicy_obrona = 2;

                            cout << endl;
                            // cout << " max_liczba_przeciwnikow = " << max_liczba_przeciwnikow << endl;
                            // cout << " liczba_losowa = " << liczba_losowa << endl;

                            if(liczba_losowa>40)
                                liczba_losowa -= 40;

                            //cout << " liczba_losowa przerobiona = " << liczba_losowa << endl;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Ich ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   ZOMBIE: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   ZOMBIE: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;

                            koniec_walki(ranni,zabici,wskaznik_wioska);
                    }
                } break;

                case 4:{ //ZO_choroba2
                    if(wskaznik_historie->odliczanie==7)
                    {
                        srand(time(NULL));
                        float *liczba_losowa = new float;
                        int *ucierpieli = new int;
                        float *ofiary = new float;
                        int *ratowanie = new int;

                        *ratowanie = 0;
                        *ucierpieli = 0;
                        *liczba_losowa = (std::rand() % 100)+1;
                        *ofiary = *liczba_losowa / 100;

                        if(*liczba_losowa<60-wskaznik_wioska->b_uleczyciel*2)
                        {
                            *ucierpieli = wskaznik_wioska->lud * *ofiary;
                            for(int i=*ucierpieli; i>0; i--)
                            {
                                *liczba_losowa = (std::rand() % 100) +1;
                                if(*liczba_losowa<=wskaznik_wioska->b_uleczyciel*3)
                                    (*ratowanie)+=1;
                            }
                            *ucierpieli -= (*ratowanie);
                        }

                        *liczba_losowa = *ofiary * 10;
                        cout << endl << endl;
                        cout << "   # W wyniku zarazy ucierpialo: " << *ucierpieli + *ratowanie << endl;
                        cout << "   # Jednak Twoj lekarz uleczyl: " << *ratowanie << endl;
                        cout << endl;
                        cout << "   # W sumie poniosles straty: " << *ucierpieli << ", niezle!";

                        wskaznik_wioska->lud -= *ucierpieli;

                        delete ratowanie;
                        delete ofiary;
                        delete liczba_losowa;
                        delete ucierpieli;
                    }
                } break;

                case 5:{ //ZM_smuga
                    if(wskaznik_historie->odliczanie==7)
                    {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));
                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 2;
                            short przeciwnicy_obrona = 2;

                            cout << endl;
                            // cout << " max_liczba_przeciwnikow = " << max_liczba_przeciwnikow << endl;
                            // cout << " liczba_losowa = " << liczba_losowa << endl;

                            if(liczba_losowa>40)
                                liczba_losowa -= 40;

                            //cout << " liczba_losowa przerobiona = " << liczba_losowa << endl;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Zycie przeciwnika: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Jego ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   PRZECIWNIK: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   PRZECIWNIK: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;

                            koniec_walki(ranni,zabici,wskaznik_wioska);
                    }
                } break;

                case 6:{ //ZM_gwiazda
                    if(wskaznik_historie->odliczanie==5)
                        {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));

                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 2;
                            short przeciwnicy_obrona = 1;

                            cout << endl;

                            if(liczba_losowa>50)
                                liczba_losowa -= 50;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Ich ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   CZERWONI: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   CZERWONI: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;
                            /*cout << "   # ZGINELO " << zabici << " Twoich ludzi, a " << ranni << " zraniono!" << endl;

                            cout << "   # DOPOKI NIE OGARNALEM ULECZYCIELA TWOI RANNI STAJA SIE NATYCHMIASTOWO LUDZMI!" << endl;
                            wskaznik_wioska->lud += ranni;*/
                            koniec_walki(ranni,zabici,wskaznik_wioska);
                        }
                } break;

                case 7:{ //ZO_mrozy
                    if(wskaznik_historie->odliczanie==5)
                    {
                        short *straty = new short;
                        *straty = wskaznik_wioska->b_drwal*1.5;

                        cout << endl << endl;
                        cout << "   # W wyniku mrozu straciles: " << *straty << " drewna!";

                        wskaznik_wioska->dre -= *straty;
                        if(wskaznik_wioska->dre<0)
                            wskaznik_wioska->dre=0;

                        delete straty;
                    }
                } break;

                case 8:{ //ZM_ufo
                    if(wskaznik_historie->odliczanie==7)
                    {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));
                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 2;
                            short przeciwnicy_obrona = 2;

                            cout << endl;
                            // cout << " max_liczba_przeciwnikow = " << max_liczba_przeciwnikow << endl;
                            // cout << " liczba_losowa = " << liczba_losowa << endl;

                            if(liczba_losowa>40)
                                liczba_losowa -= 40;

                            //cout << " liczba_losowa przerobiona = " << liczba_losowa << endl;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Jego ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   PRZECIWNIK: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   PRZECIWNIK: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;

                            koniec_walki(ranni,zabici,wskaznik_wioska);
                    }
                } break;

                case 9:{ //ZO_swieto
                    if(wskaznik_historie->odliczanie==4)
                    {
                        short *strata_zel = new short;
                        short *strata_dre = new short;
                        short *strata_kam = new short;

                        if(wskaznik_wioska->b_kopalnia>=3)
                            *strata_zel = wskaznik_wioska->b_kopalnia + wskaznik_wioska->p_kilof;
                        else
                            *strata_zel = 0;
                        *strata_dre = wskaznik_wioska->b_drwal*2 + wskaznik_wioska->p_siekiera*2;
                        *strata_kam = wskaznik_wioska->b_kopalnia*2 + wskaznik_wioska->p_kilof*2;

                        cout << endl << endl;
                        cout << "   # Strata surowcow - DRE:" << wskaznik_wioska->b_drwal*2 + wskaznik_wioska->p_siekiera*2 << " KAM:" << wskaznik_wioska->b_kopalnia*2 + wskaznik_wioska->p_kilof*2;
                        if(wskaznik_wioska->b_kopalnia>=3)
                            cout << " ZEL:" << wskaznik_wioska->b_kopalnia + wskaznik_wioska->p_kilof;

                        wskaznik_wioska->zel -= *strata_zel;
                        wskaznik_wioska->kam -= *strata_kam;
                        wskaznik_wioska->dre -= *strata_dre;

                        delete strata_zel;
                        delete strata_dre;
                        delete strata_kam;
                    }
                } break;

                case 10:{ //ZO_manna
                    if(wskaznik_historie->odliczanie==4)
                    {
                        short ilosc;

                        ilosc = (wskaznik_wioska->lud + wskaznik_wioska->rol + wskaznik_wioska->woj)*2;
                        wskaznik_wioska->warz += ilosc;
                        wskaznik_wioska->mie += ilosc;

                        cout << endl << endl;
                        cout << "   # Zyskales " << ilosc << " MIEsa i " << ilosc << " WARZyw!";
                    }
                } break;

                case 11:{ // ZM_rosliny_atakuja
                    if(wskaznik_historie->odliczanie==5)
                    {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));

                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 3;
                            short przeciwnicy_obrona = 1;

                            cout << endl;

                            if(liczba_losowa>50)
                                liczba_losowa -= 50;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Ich ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   ROSLINY: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   ROSLINY: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;
                            koniec_walki(ranni,zabici,wskaznik_wioska);
                    }
                } break;

                case 12:{ // ZM_pijany_stroz
                    if(wskaznik_historie->odliczanie==5)
                    {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));

                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 3;
                            short przeciwnicy_obrona = 1;

                            cout << endl;

                            if(liczba_losowa>50)
                                liczba_losowa -= 50;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Ich ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   WOJSKO: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   WOJSKO: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;
                            koniec_walki(ranni,zabici,wskaznik_wioska);
                    }
                } break;

                case 13:{ // ZM_staruszek_za_murem
                    if(wskaznik_historie->odliczanie==4)
                    {
                            cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));

                            float max_liczba_przeciwnikow = wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 3;
                            short przeciwnicy_obrona = 1;

                            cout << endl;

                            if(liczba_losowa>50)
                                liczba_losowa -= 50;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Ich ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   STARUSZKOWIE: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   STARUSZKOWIE: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }
                            cout << endl << endl;
                            cout << "   # To byla ciezka walka!!!" << endl;
                            koniec_walki(ranni,zabici,wskaznik_wioska);
                    }
                } break;

                case 14:{ // ZO_plaga
                    if(wskaznik_historie->odliczanie==5)
                    {
                        srand(time(NULL));
                        float *liczba_losowa = new float;
                        int *ucierpieli = new int;
                        float *ofiary = new float;
                        int *ratowanie = new int;

                        *ratowanie = 0;
                        *ucierpieli = 0;
                        *liczba_losowa = (std::rand() % 100)+1;
                        *ofiary = *liczba_losowa / 100;

                        if(*liczba_losowa<60-wskaznik_wioska->b_uleczyciel*2)
                        {
                            *ucierpieli = wskaznik_wioska->lud * *ofiary;
                            for(int i=*ucierpieli; i>0; i--)
                            {
                                *liczba_losowa = (std::rand() % 100) +1;
                                if(*liczba_losowa<=wskaznik_wioska->b_uleczyciel*3)
                                    (*ratowanie)+=1;
                            }
                            *ucierpieli -= (*ratowanie);
                        }

                        wskaznik_wioska->warz -= (wskaznik_wioska->b_pola*3) + (wskaznik_wioska->p_motyka*2);
                        wskaznik_wioska->mie -= wskaznik_wioska->lud;
                        if(wskaznik_wioska->mie<0)
                            wskaznik_wioska->mie=0;
                        *liczba_losowa = *ofiary * 10;
                        cout << endl << endl;
                        cout << "   # Straciles " << wskaznik_wioska->lud << " MIEsa i nie dostales dzis WARZyw!" << endl;
                        cout << "   # W wyniku zarazy ucierpialo: " << *ucierpieli + *ratowanie << endl;
                        cout << "   # Jednak Twoj lekarz uleczyl: " << *ratowanie << endl;
                        cout << endl;
                        cout << "   # W sumie poniosles straty: " << *ucierpieli << ", niezle!";

                        wskaznik_wioska->lud -= *ucierpieli;

                        delete ratowanie;
                        delete ofiary;
                        delete liczba_losowa;
                        delete ucierpieli;
                    }
                } break;

                case 15:{ // ZO_bunt
                    if(wskaznik_historie->odliczanie==7)
                    {
                        cout << endl << endl;
                            cout << "   ### WALKA ###";

                            srand(time(NULL));

                            float max_liczba_przeciwnikow = wskaznik_wioska->lud;
                            float liczba_losowa = (std::rand() % 100)+1;
                            float liczba_przeciwnikow;
                            short ranni = 0;
                            short zabici = 0;
                            int walka_atk;
                            int walka_obr;
                            short przeciwnicy_atak = 3;
                            short przeciwnicy_obrona = 1;

                            cout << endl;

                            if(liczba_losowa>50)
                                liczba_losowa -= 50;

                            liczba_przeciwnikow = liczba_losowa / 100 * max_liczba_przeciwnikow;
                            liczba_przeciwnikow = (int)liczba_przeciwnikow + 2;

                            cout << endl;
                            cout << "   Liczba przeciwnikow: " << liczba_przeciwnikow << endl;
                            cout << "   Twoje wojsko:        LUD: " << wskaznik_wioska->lud - liczba_przeciwnikow << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << endl;
                            cout << endl;
                            cout << "   Ich ATK " << liczba_przeciwnikow*przeciwnicy_atak << " / OBR " << liczba_przeciwnikow*przeciwnicy_obrona << endl;
                            cout << "   Twoj ATK " << wskaznik_wioska->atk << " / OBR " << wskaznik_wioska->obr << endl;

                            cout << endl;
                            short runda=1;
                            while((wskaznik_wioska->lud - liczba_przeciwnikow + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            walka_atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud - liczba_przeciwnikow + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2;
                            walka_obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud - liczba_przeciwnikow + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4;

                            cout << endl << endl;
                            cout << "   |### RUNDA " << runda << " ###|" << endl;
                            cout << endl;

                            //walka obrona

                            liczba_losowa = (std::rand()%10)+1;
                            if(walka_obr>(liczba_przeciwnikow*przeciwnicy_atak+10))
                            {
                                if(liczba_losowa<10)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa==10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                   else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr>=(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_obr<(liczba_przeciwnikow*przeciwnicy_atak))
                            {
                                if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud - liczba_przeciwnikow << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   BUNTOWNICY: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici;

                            //walka atak

                            if((wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)!=0 && liczba_przeciwnikow!=0)
                            {
                            liczba_losowa = (std::rand()&10)+1;
                            if(walka_atk>(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                if(liczba_losowa<7)
                                    liczba_przeciwnikow--;
                                if(liczba_losowa>6 && liczba_losowa<10)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                            }

                            else if(walka_atk<(liczba_przeciwnikow*przeciwnicy_obrona))
                            {
                                 if(liczba_losowa<8)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                    ranni++;
                                }
                                else if(liczba_losowa>7 && liczba_losowa<9)
                                {
                                    liczba_losowa = (std::rand()%3)+1;
                                    if(liczba_losowa==1 && wskaznik_wioska->lud>0)
                                        wskaznik_wioska->lud--;
                                    else if(liczba_losowa==2 && wskaznik_wioska->woj>0)
                                        wskaznik_wioska->woj--;
                                    else if(liczba_losowa==3 && wskaznik_wioska->rol>0)
                                        wskaznik_wioska->rol--;
                                    else
                                        wskaznik_wioska->lud--;
                                }
                                else if(liczba_losowa==9)
                                    liczba_przeciwnikow--;
                            }

                            cout << endl;
                            cout << "----------------------------------------------------" << endl;
                            cout << "   LUD: " << wskaznik_wioska->lud - liczba_przeciwnikow << "   WOJ: " << wskaznik_wioska->woj << "   ROL: " << wskaznik_wioska->rol << "   vs.   BUNTOWNICY: " << liczba_przeciwnikow << endl;
                            zabici = max_liczba_przeciwnikow - wskaznik_wioska->lud - wskaznik_wioska->woj - wskaznik_wioska->rol - ranni;
                            cout << "   RANNI: " << ranni << "   ZABICI: " << zabici << endl;
                            cout << "----------------------------------------------------";

                            runda++;
                            }
                            Sleep(1000);
                            }

                            if(liczba_przeciwnikow>(wskaznik_wioska->lud - liczba_przeciwnikow + wskaznik_wioska->woj + wskaznik_wioska->rol))
                            {
                                wskaznik_wioska->lud -= liczba_przeciwnikow;
                                cout << endl << endl;
                                cout << "   # To byla ciezka walka!!!" << endl;
                                cout << "   # Buntownicy ucielki, a Twoja wioska upadla" << endl;
                            }
                            else
                            {
                                cout << endl << endl;
                                cout << "   # To byla ciezka walka!!!" << endl;
                                cout << "   # Buntownicy lizac rany wrocili do Twojej wioski" << endl;
                                cout << "   # Niech im bedzie, kazdy przyda sie w tych ciezkich czasach!" << endl;
                            }
                            koniec_walki(ranni,zabici,wskaznik_wioska);
                    }
                } break;
            }

            if(wskaznik_historie->czytanie==true)
            {
                cout << endl;
                cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                wskaznik_wioska->wyb_wioska = getch();
            }
            przeczytane=true;
        }

        wskaznik_wioska->atk = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*4 + wskaznik_wioska->rol*2 + wskaznik_wioska->b_koszary*2;
        wskaznik_wioska->obr = wskaznik_wioska->bro*2 + wskaznik_wioska->lud + wskaznik_wioska->woj*2 + wskaznik_wioska->rol*4 + wskaznik_wioska->b_mur*2;

        wskaznik_wioska->wioska_menu();

        switch(wskaznik_wioska->wyb_wioska)
        {
            case 'a':{
                wskaznik_wioska->wioska_mur();

                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    system("cls");

                    cout << endl;
                    cout << " # Podchodzisz do swojego muru i rozgladasz sie na lewo i prawo i widzisz:" << endl << endl;

                    switch(wskaznik_historie->historia)
                    {
                        case 2:{
                            if(wskaznik_historie->odliczanie==7)
                            {
                                cout << "    Spogladasz daleko za drzewa, ktore lekko kolysza sie na wietrze," << endl;
                                cout << "    ale nie zauwazasz nic niezwyklego. Jedyne co mozesz zauwazyc to samotny wilk." << endl;
                                cout << "    Siedzi na skraju drzew i przypatruje sie Twojej wiosce. To pewnie nic takiego!" << endl << endl;
                            }
                            else if(wskaznik_historie->odliczanie==6)
                            {
                                cout << "    To cale stado wilkow okraza Twoje bramy i czyha na choc jeden blad." << endl;
                                cout << "    Wystarczy jeden nieuwazny mieszkaniec a cale stado wejdzie do wioski!" << endl;
                                cout << "    DO BRONI!" << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        case 3:{
                            if(wskaznik_historie->odliczanie==7)
                            {
                                cout << "    Niby nic takiego, las, samotne skaly i daleki kraniec puszczy gdzies tam hen daleko." << endl;
                                cout << "    Nie ma co marnowac czasu. Jedynie samotny podroznik obok skaly..." << endl;
                                cout << "    Siedzi albo lezy? Jest za daleko zeby okreslic." << endl << endl;
                            }
                            else if(wskaznik_historie->odliczanie==6)
                            {
                                cout << "    Przy skalach mozna zauwazyc.. krew." << endl;
                                cout << "    Smrod na murze mozna odczuc jeszcze bardziej." << endl;
                                cout << "    Czy to ludzka konczyna na ziemi?!" << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        case 5:{
                            if(wskaznik_historie->odliczanie==9)
                            {
                                cout << "    Gdzies w oddali widzisz czerwony punkt na niebie." << endl;
                                cout << "    Wydaje sie on krwisty i posuwa sie w Twoja strone!" << endl;
                                cout << "    Czy to czas na zbrojenie?!" << endl << endl;
                            }
                            else if(wskaznik_historie->odliczanie==8)
                            {
                                cout << "    Krwista smuga jest juz prawie nad Twoja wioska!" << endl;
                                cout << "    Wiatr wieje mocniej niz zwykle, a w powietrzu czuc siarke." << endl;
                                cout << "    Cos zlego nastapi niebawem..." << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        case 6:{
                            if(wskaznik_historie->odliczanie==7)
                            {
                                cout << "    Czerwona gwiazda swieci mocno na niebie!" << endl;
                                cout << "    Pojawila sie znikad i czuc od niej mrok." << endl;
                                cout << "    To nie wyglada dobrze..." << endl << endl;
                            }
                            else if(wskaznik_historie->odliczanie==6)
                            {
                                cout << "    Na murze czujesz ze jest coraz cieplej." << endl;
                                cout << "    Z kolei gwiazda jest coraz nizej" << endl;
                                cout << "    Lepiej sie przygotowac..." << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        case 8:{
                            if(wskaznik_historie->odliczanie==9)
                            {
                                cout << "   Dzien jest jakby ciemniejszy." << endl;
                                cout << "   Na niebie widac blyski..." << endl;
                                cout << "   Burza?" << endl << endl;
                            }
                            else if(wskaznik_historie->odliczanie==8)
                            {
                                cout << "   W chmurach widac okradly ksztalt, ktory jakby lewituje." << endl;
                                cout << "   To na pewno nie burza..." << endl;
                                cout << "   Meteor?" << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        case 11:{
                            if(wskaznik_historie->odliczanie==7)
                            {
                                cout << "   Trawa rosnie nisko..." << endl;
                                cout << "   Znaczy chyba, bo teraz jest troche wieksza niz wczoraj!" << endl << endl;
                            }
                            else if(wskaznik_historie->odliczanie==6)
                            {
                                cout << "   Trawa rosnie wysoko!" << endl;
                                cout << "   Czy to rosiczka? NA SRODKU LAKI?!" << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        case 12:{
                            if(wskaznik_historie->odliczanie==7)
                            {
                                cout << "   Czy Twoj straznik chodzi pijany?" << endl;
                                cout << "   Pozniej bede musial go wywalic..." << endl;
                                cout << "   *hicks*" << endl << endl;
                            }
                            else if(wskaznik_historie->odliczanie==6)
                            {
                                cout << "   To jest niebezpieczne." << endl;
                                cout << "   Dlaczego ten pijany straznik znow ma warte?" << endl;
                                cout << "   Wywale go, ale... Czy nie zapomnialem zgasic ogniska?" << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        case 13:{
                            if(wskaznik_historie->odliczanie==5)
                            {
                                cout << "   Staruszek siedzi sobie za murem." << endl;
                                cout << "   Nic w tym dziwnego przeciez." << endl;
                                cout << "   Myslisz ze zawsze jak cos tu pisze to jestes zagrozony?" << endl << endl;
                            }
                            else
                                cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;

                        default:{
                            cout << "    Nic. Nie tym razem ziomek!" << endl << endl;
                        } break;
                    }

                    cout << " Nacisnij cokolwiek, aby kontynuowac...";
                    wskaznik_wioska->wyb_wioska = getch();
                }
            } break;

            case 'b':{
                wskaznik_wioska->wioska_kopalnia();

                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    system("cls");
                    cout << endl;
                    cout << " # Ulepszanie kilofa" << endl << endl;

                    if(wskaznik_wioska->p_kilof==0)
                    {
                        cout << " # Kilof poziom 0          DRE:10 KAM:10 ZEL:10";
                    }

                    if(wskaznik_wioska->p_kilof>0)
                    {
                        cout << " # Kilof poziom " << wskaznik_wioska->p_kilof << "          DRE:" << wskaznik_wioska->p_kilof*20 << " KAM:" << wskaznik_wioska->p_kilof*20 << " ZEL:" << wskaznik_wioska->p_kilof*20;
                    }

                    cout << endl << endl << "   Aby ulepszyc kilof nacisnij 'a'..." << endl;
                    cout << "   Aby wyjsc nacisnij cokolwiek innego...";
                    wskaznik_wioska->wyb_wioska = getch();

                    if(wskaznik_wioska->wyb_wioska == 'a')
                    {
                        if(wskaznik_wioska->p_kilof>0)
                        {
                            if(wskaznik_wioska->dre>=wskaznik_wioska->p_kilof*20 && wskaznik_wioska->kam>=wskaznik_wioska->p_kilof*20 && wskaznik_wioska->zel>=wskaznik_wioska->p_kilof*20)
                            {
                                wskaznik_wioska->dre-=wskaznik_wioska->p_kilof*20;
                                wskaznik_wioska->kam-=wskaznik_wioska->p_kilof*20;
                                wskaznik_wioska->zel-=wskaznik_wioska->p_kilof*20;
                                wskaznik_wioska->p_kilof++;
                                system("cls");
                                cout << endl << " Kilof usprawniony do " << wskaznik_wioska->p_kilof << " poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }

                        if(wskaznik_wioska->p_kilof==0)
                        {
                            if(wskaznik_wioska->dre>=10 && wskaznik_wioska->kam>=10 && wskaznik_wioska->zel>=10)
                            {
                                wskaznik_wioska->dre-=10;
                                wskaznik_wioska->kam-=10;
                                wskaznik_wioska->zel-=10;
                                wskaznik_wioska->p_kilof++;
                                system("cls");
                                cout << endl << " Kilof usprawniony do " << wskaznik_wioska->p_kilof << " poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }
                    }
                }
            } break;

            case 'c':{
                wskaznik_wioska->wioska_lowczy();

                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    system("cls");
                    cout << endl;
                    cout << " # Ulepszanie lukow" << endl << endl;

                    if(wskaznik_wioska->p_luki==0)
                        cout << " # Luki poziom 0           DRE:10 KAM:10 ZEL:10";

                    if(wskaznik_wioska->p_luki>0)
                        cout << " # Luki poziom " << wskaznik_wioska->p_luki << "           DRE:" << wskaznik_wioska->p_luki*20 << " KAM:" << wskaznik_wioska->p_luki*20 << " ZEL:" << wskaznik_wioska->p_luki*20;

                    cout << endl << endl << "   Aby ulepszyc luki nacisnij 'a'..." << endl;
                    cout << "   Aby wyjsc nacisnij cokolwiek innego...";
                    wskaznik_wioska->wyb_wioska = getch();

                    if(wskaznik_wioska->wyb_wioska == 'a')
                    {
                        if(wskaznik_wioska->p_luki>0)
                        {
                            if(wskaznik_wioska->dre>=wskaznik_wioska->p_luki*20 && wskaznik_wioska->kam>=wskaznik_wioska->p_luki*20 && wskaznik_wioska->zel>=wskaznik_wioska->p_luki*20)
                            {
                                wskaznik_wioska->dre-=wskaznik_wioska->p_luki*20;
                                wskaznik_wioska->kam-=wskaznik_wioska->p_luki*20;
                                wskaznik_wioska->zel-=wskaznik_wioska->p_luki*20;
                                wskaznik_wioska->p_luki++;
                                system("cls");
                                cout << endl << " Luki usprawnione do " << wskaznik_wioska->p_luki << " poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }

                        if(wskaznik_wioska->p_luki==0)
                        {
                            if(wskaznik_wioska->dre>=10 && wskaznik_wioska->kam>=10 && wskaznik_wioska->zel>=10)
                            {
                                wskaznik_wioska->dre-=10;
                                wskaznik_wioska->kam-=10;
                                wskaznik_wioska->zel-=10;
                                wskaznik_wioska->p_luki++;
                                system("cls");
                                cout << endl << " Luki usprawnione do " << wskaznik_wioska->p_luki << " poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }
                    }
                }

                if(wskaznik_wioska->wyb_wioska=='b')
                {
                        bool *wybor = new bool[5];
                        *wybor = false;
                        *(wybor+1) = false;
                        *(wybor+2) = false;
                        *(wybor+3) = false;
                        *(wybor+4) = false;

                        system("cls");
                        cout << endl << " # Podchodzisz do staruszka i pytasz kim tak na prawde jest" << endl << endl;

                        cout << "  - Nazywam sie Gerald, jestem lowca zwierzyny w twojej wiosce." << endl;
                do{
                        if(wskaznik_wioska->wyb_wioska=='a' || wskaznik_wioska->wyb_wioska=='b')
                        {
                        cout << "    Dlaczego rujnujesz moj spokoj?" << endl << endl;

                        cout << "      a. \"Skad pochodzisz?\"" << endl;
                        cout << "      b. \"A dlaczego masz takie siwe wlosy?\"" << endl;
                        }
                        wskaznik_wioska->wyb_wioska = getch();

                        cout << endl << endl << endl;
                        if(wskaznik_wioska->wyb_wioska=='a')
                            *wybor=true;

                        if(wskaznik_wioska->wyb_wioska=='b')
                        {
                            cout << "  - A dlaczego masz takie siwe wlosy?" << endl << endl;

                            cout << "  - Bo jestem stary nie widzisz? Co za glupie pytanie." << endl;
                            cout << "    Denerwujesz mnie" << endl;
                        }
                } while (*wybor==false);
                cout << "  - Skad pochodzisz?" << endl << endl;

                cout << "  - Jakbys nie wiedzial, nie jestem stad. Nie jestem nawet z tego kontynentu." << endl;
                cout << "    Przybylem tutaj, bo moja historia sie skonczyla i potrzebowalem przygody." << endl;
                do{
                        if(wskaznik_wioska->wyb_wioska=='a' || wskaznik_wioska->wyb_wioska=='b')
                        {
                        cout << "    Jeszcze cos?" << endl << endl;

                        cout << "      a. \"A dlaczego masz kocie oczy?\"" << endl;
                        cout << "      b. \"Opowiedz mi o swojej przygodzie\"" << endl;
                        }
                        wskaznik_wioska->wyb_wioska = getch();

                        cout << endl << endl << endl;
                        if(wskaznik_wioska->wyb_wioska=='a')
                            {
                                cout << "  - A dlaczego masz kocie oczy?" << endl << endl;

                                cout << "  - Taki sie stalem po mojej przemianie... ale to bardzo dluga historia." << endl;
                            }

                        if(wskaznik_wioska->wyb_wioska=='b')
                            *(wybor+1)=true;
                } while (*(wybor+1)==false);
                cout << "  - Opowiedz mi o swojej przygodzie" << endl << endl;

                cout << "  - Coz by tu duzo opowiadac, podrozowalem po swiecie," << endl;
                cout << "    Zabijalem potwory zagrazajace ludziom ale i ludzi o charakterze potworow" << endl;
                cout << "    Nic szczegolnego jak na moja profesje." << endl;
                do{
                        if(wskaznik_wioska->wyb_wioska=='a' || wskaznik_wioska->wyb_wioska=='b')
                        {
                        cout << "    Cos jeszcze?" << endl << endl;

                        cout << "      a. \"Byles jakby zabojca do wynajecia?\"" << endl;
                        cout << "      b. \"Jaka profesje?\"" << endl;
                        }
                        wskaznik_wioska->wyb_wioska = getch();

                        cout << endl << endl << endl;
                        if(wskaznik_wioska->wyb_wioska=='a')
                            {
                                cout << "  - Byles jakby zabojca do wynajecia?" << endl << endl;

                                cout << "  - No wlasnie o tym mowie... Czego nie rozumiesz?" << endl;
                                cout << "    Dobrze ze przynajmniej przyzwoicie placisz..." << endl;
                            }

                        if(wskaznik_wioska->wyb_wioska=='b')
                            *(wybor+2)=true;
                } while (*(wybor+2)==false);
                cout << "  - Jaka profesje?" << endl << endl;

                cout << "  - Jestem... Bylem wiesminem." << endl;
                cout << "    Jak juz mowilem zajmowalem sie zabijaniem stworow zagrazajacym ludziom." << endl;
                cout << "    Oczywiscie za drobna op³ata." << endl;
                do{
                        if(wskaznik_wioska->wyb_wioska=='a' || wskaznik_wioska->wyb_wioska=='b' || wskaznik_wioska->wyb_wioska=='c')
                        {
                        cout << "    Takie zycie..." << endl << endl;

                        cout << "      a. \"Jak tu trafiles?\"" << endl;
                        cout << "      b. \"Kim sa wiesmini?\"" << endl;
                        cout << "      c. \"Kijowo...\"" << endl;
                        }
                        wskaznik_wioska->wyb_wioska = getch();

                        cout << endl << endl << endl;
                        if(wskaznik_wioska->wyb_wioska=='a')
                            *(wybor+3)=true;

                        if(wskaznik_wioska->wyb_wioska=='b')
                            {
                                cout << "  - Kim sa wiesmini?" << endl << endl;

                                cout << "  - To dobrze wyszkolona grupa specjalistow od zabijania" << endl;
                                cout << "    Albo szukania swoich corek... Prawie corek..." << endl;
                            }

                        if(wskaznik_wioska->wyb_wioska=='c')
                            {
                                cout << "  - Kijowo..." << endl << endl;

                                cout << "  - Coz mam Ci odpowiedziec... " << endl;
                                cout << "    Bylem tym co zastal moj ojciec po powrocie, a czego sie nie spodziewal." << endl;
                            }
                } while (*(wybor+3)==false);
                cout << "  - Jak tu trafiles?" << endl << endl;

                cout << "  - To jest skomplikowana historia na inny czas." << endl;
                cout << "    Osiadlem w Tussam wraz z moimi przyjaciolmi," << endl;
                cout << "    Lecz cos pokusilo mnie po wielu latach aby wyruszyc w ostatnia podroz morzem na polnoc." << endl;
                cout << "    Moj statek rozbil sie na skalach tej ziemi i znalazlem te wioske. Szukales mysliwego a ja nim jestem." << endl;
                do{
                        if(wskaznik_wioska->wyb_wioska=='a' || wskaznik_wioska->wyb_wioska=='b')
                        {
                        cout << "    Ehh..." << endl << endl;

                        cout << "      a. \"Dokad plynales?\"" << endl;
                        cout << "      b. \"Musimy sie lepiej poznac!\"" << endl;
                        }
                        wskaznik_wioska->wyb_wioska = getch();

                        cout << endl << endl << endl;
                        if(wskaznik_wioska->wyb_wioska=='a')
                            {
                                cout << "  - Dokad plynales?." << endl << endl;

                                cout << "  - Do dalekich krain za tym kontynentem." << endl;
                                cout << "    Moze kiedys uda sie tam wybrac." << endl;
                            }

                        if(wskaznik_wioska->wyb_wioska=='b')
                            *(wybor+4)=true;
                } while (*(wybor+4)==false);
                cout << "  - Musimy sie lepiej poznac!" << endl << endl;

                cout << "  - Moze kiedys przezyjemy razem jakies wspolne przygody jeszcze." << endl;
                cout << "    Stary juz jestem, trzy czesci gry mnie wymeczyly ale jakiejs malej robotki moge zawsze sie chwycic." << endl;
                do{
                        if(wskaznik_wioska->wyb_wioska=='a' || wskaznik_wioska->wyb_wioska=='b')
                        {
                        cout << "    Moze juz niedlugo!" << endl << endl;

                        cout << "      a. \"Gdy tylko bede mial cos w planach na pewno Ci powiem. Do zobaczenia!\"" << endl;
                        cout << "      b. \"Gdzie marzy Ci sie wyruszyc?\"" << endl;
                        }
                        wskaznik_wioska->wyb_wioska = getch();

                        cout << endl << endl << endl;
                        if(wskaznik_wioska->wyb_wioska=='a')
                            *(wybor+5)=true;

                        if(wskaznik_wioska->wyb_wioska=='b')
                            {
                                cout << "  - Gdzie marzy Ci sie wyruszyc?" << endl << endl;

                                cout << "  - Przed chwila mowilem Ci gdzie plynalem" << endl;
                                cout << "    Musze tam wyruszyc" << endl;
                            }
                } while (*(wybor+5)==false);
                cout << "  - Do zobaczenia " << wskaznik_wioska->imie << "!" << endl << endl;

                cout << "   Nacisnij cokolwiek, aby kontynuowac...";
                wskaznik_wioska->wyb_wioska = getch();

                    delete [] wybor;
                }
            } break;

            case 'd':{
                wskaznik_wioska->wioska_chata();
            } break;

            case 'e':{
                wskaznik_wioska->wioska_drwal();

                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    system("cls");
                    cout << endl;
                    cout << " # Ulepszanie siekiery" << endl << endl;

                    if(wskaznik_wioska->p_siekiera==0)
                        cout << " # Siekiera poziom 0       DRE:10 KAM:10 ZEL:10";

                    if(wskaznik_wioska->p_siekiera>0)
                        cout << " # Siekiera poziom " << wskaznik_wioska->p_siekiera << "       DRE:" << wskaznik_wioska->p_siekiera*20 << " KAM:" << wskaznik_wioska->p_siekiera*20 << " ZEL:" << wskaznik_wioska->p_siekiera*20;

                    cout << endl << endl << "   Aby ulepszyc siekiere nacisnij 'a'..." << endl;
                    cout << "   Aby wyjsc nacisnij cokolwiek innego...";
                    wskaznik_wioska->wyb_wioska = getch();

                    if(wskaznik_wioska->wyb_wioska == 'a')
                    {
                        if(wskaznik_wioska->p_siekiera>0)
                        {
                            if(wskaznik_wioska->dre>=wskaznik_wioska->p_siekiera*20 && wskaznik_wioska->kam>=wskaznik_wioska->p_siekiera*20 && wskaznik_wioska->zel>=wskaznik_wioska->p_siekiera*20)
                            {
                                wskaznik_wioska->dre-=wskaznik_wioska->p_siekiera*20;
                                wskaznik_wioska->kam-=wskaznik_wioska->p_siekiera*20;
                                wskaznik_wioska->zel-=wskaznik_wioska->p_siekiera*20;
                                wskaznik_wioska->p_siekiera++;
                                system("cls");
                                cout << endl << " Siekiera usprawniona do " << wskaznik_wioska->p_siekiera << " poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }

                        if(wskaznik_wioska->p_siekiera==0)
                        {
                            if(wskaznik_wioska->dre>=10 && wskaznik_wioska->kam>=10 && wskaznik_wioska->zel>=10)
                            {
                                wskaznik_wioska->dre-=10;
                                wskaznik_wioska->kam-=10;
                                wskaznik_wioska->zel-=10;
                                wskaznik_wioska->p_siekiera++;
                                system("cls");
                                cout << endl << " Siekiera usprawniona do " << wskaznik_wioska->p_siekiera << " poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }
                    }
                }
            } break;

            case 'f':{
                wskaznik_wioska->wioska_koszary();

                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    system("cls");
                    cout << endl;
                    cout << " # Wykuwanie BROni" << endl << endl;

                    cout << " # Aktualnie posiadasz " << wskaznik_wioska->bro << " BROni" << endl << endl;

                    cout << " # Koszt BROni to   DRE:5 ZEL:3" << endl;

                    cout << endl << endl << "   Aby wykuc BROn nacisnij 'a'..." << endl;
                    cout << "   Aby wyjsc nacisnij cokolwiek innego...";
                    wskaznik_wioska->wyb_wioska = getch();

                    if(wskaznik_wioska->wyb_wioska == 'a')
                    {

                        if(wskaznik_wioska->dre>=5 && wskaznik_wioska->zel>=3)
                        {
                            wskaznik_wioska->dre-=5;
                            wskaznik_wioska->zel-=3;
                            wskaznik_wioska->bro++;
                            system("cls");
                            cout << endl << " Masz juz " << wskaznik_wioska->bro << " BROni!";
                            Sleep(1000);
                        }

                        else
                        {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                        }
                    }
                }

                if(wskaznik_wioska->wyb_wioska=='b')
                {
                    system("cls");
                    cout << endl;
                    cout << " # Tworz WOJownikow" << endl << endl;

                    cout << " # Aktualnie masz pod wodza " << wskaznik_wioska->woj << " WOJownikow" << endl << endl;

                    cout << " # Kolejny WOJownik to   ZEL:5 BRO:1 LUD:1" << endl;
                    cout << " # WOJownik zjada na ture   WARZ:1 MIE:2" << endl;

                    cout << endl << endl << "   Aby zrekrutowac WOJa nacisnij 'a'..." << endl;
                    cout << "   Aby wyjsc nacisnij cokolwiek innego...";
                    wskaznik_wioska->wyb_wioska = getch();

                    if(wskaznik_wioska->wyb_wioska == 'a')
                    {

                        if(wskaznik_wioska->zel>=5 && wskaznik_wioska->bro>=1 && wskaznik_wioska->lud>=1)
                        {
                            wskaznik_wioska->zel-=5;
                            wskaznik_wioska->bro--;
                            wskaznik_wioska->lud--;
                            wskaznik_wioska->woj++;
                            system("cls");
                            cout << endl << " Masz juz " << wskaznik_wioska->woj << " WOJownikow!";
                            Sleep(1000);
                        }

                        else
                        {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                        }
                    }
                }
            } break;

            case 'g':{
                wskaznik_wioska->wioska_jaskinia();
            } break;

            case 'h':{
                wskaznik_wioska->wioska_pola();

                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    system("cls");
                    cout << endl;
                    cout << " # Szkolenie ROLnika" << endl << endl;

                    cout << " # Aktualnie masz wyszkolonych " << wskaznik_wioska->rol << " ROLnikow" << endl << endl;

                    cout << " # Kolejny ROLnik to   ZEL:5 BRO:1 LUD:1" << endl;
                    cout << " # ROLnik zjada co ture   WARZ:2 MIE:1" << endl;

                    cout << endl << endl << "   Aby wyszkolic ROLnika nacisnij 'a'..." << endl;
                    cout << "   Aby wyjsc nacisnij cokolwiek innego...";
                    wskaznik_wioska->wyb_wioska = getch();

                    if(wskaznik_wioska->wyb_wioska == 'a')
                    {

                        if(wskaznik_wioska->zel>=5 && wskaznik_wioska->bro>=1 && wskaznik_wioska->lud>=1)
                        {
                            wskaznik_wioska->zel-=5;
                            wskaznik_wioska->bro--;
                            wskaznik_wioska->lud--;
                            wskaznik_wioska->rol++;
                            system("cls");
                            cout << endl << " Masz juz " << wskaznik_wioska->rol << " ROLnikow!";
                            Sleep(1000);
                        }

                        else
                        {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                        }
                    }
                }

                if(wskaznik_wioska->wyb_wioska=='b')
                {
                    system("cls");
                    cout << endl;
                    cout << " # Ulepszanie motyki" << endl << endl;

                    if(wskaznik_wioska->p_motyka==0)
                        cout << " # Motyka poziom 0       DRE:10 KAM:10 ZEL:10";

                    if(wskaznik_wioska->p_motyka>0)
                        cout << " # Motyka poziom " << wskaznik_wioska->p_motyka << "       DRE:" << wskaznik_wioska->p_motyka*20 << " KAM:" << wskaznik_wioska->p_motyka*20 << " ZEL:" << wskaznik_wioska->p_motyka*20;

                    cout << endl << endl << "   Aby ulepszyc motyke nacisnij 'a'..." << endl;
                    cout << "   Aby wyjsc nacisnij cokolwiek innego...";
                    wskaznik_wioska->wyb_wioska = getch();

                    if(wskaznik_wioska->wyb_wioska == 'a')
                    {
                        if(wskaznik_wioska->p_motyka>0)
                        {
                            if(wskaznik_wioska->dre>=wskaznik_wioska->p_motyka*20 && wskaznik_wioska->kam>=wskaznik_wioska->p_motyka*20 && wskaznik_wioska->zel>=wskaznik_wioska->p_motyka*20)
                            {
                                wskaznik_wioska->dre-=wskaznik_wioska->p_motyka*20;
                                wskaznik_wioska->kam-=wskaznik_wioska->p_motyka*20;
                                wskaznik_wioska->zel-=wskaznik_wioska->p_motyka*20;
                                wskaznik_wioska->p_motyka++;
                                system("cls");
                                cout << endl << " Motyka usprawniona do " << wskaznik_wioska->p_motyka << " poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }

                        if(wskaznik_wioska->p_motyka==0)
                        {
                            if(wskaznik_wioska->dre>=10 && wskaznik_wioska->kam>=10 && wskaznik_wioska->zel>=10)
                            {
                                wskaznik_wioska->dre-=10;
                                wskaznik_wioska->kam-=10;
                                wskaznik_wioska->zel-=10;
                                wskaznik_wioska->p_motyka++;
                                system("cls");
                                cout << endl << " Motyka usprawniona do 1 poziomu!";
                                Sleep(1000);
                            }

                            else
                            {
                                system("cls");
                                cout << endl << " Za malo surowcow!";
                                Sleep(1000);
                            }
                        }
                    }
                }
            } break;

            case 'i':{
                bool uleczyciel_petla = true;
                do{
                wskaznik_wioska->wioska_uleczyciel();
                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    wskaznik_wioska->odl_ranni=wskaznik_wioska->odl_ranni*(-1);
                    if(wskaznik_wioska->ranni!=0&&wskaznik_wioska->odl_ranni>0)
                    {
                        if(wskaznik_wioska->b_uleczyciel<7)
                            wskaznik_wioska->odl_ranni=5;
                        if(wskaznik_wioska->b_uleczyciel>6&&wskaznik_wioska->b_uleczyciel<13)
                            wskaznik_wioska->odl_ranni=4;
                        if(wskaznik_wioska->b_uleczyciel>12&&wskaznik_wioska->b_uleczyciel<19)
                            wskaznik_wioska->odl_ranni=3;
                        if(wskaznik_wioska->b_uleczyciel>18&&wskaznik_wioska->b_uleczyciel<25)
                            wskaznik_wioska->odl_ranni=2;
                        if(wskaznik_wioska->b_uleczyciel>24)
                            wskaznik_wioska->odl_ranni=1;
                    }
                    if((wskaznik_wioska->lud+wskaznik_wioska->woj+wskaznik_wioska->rol)>=wskaznik_wioska->b_domy*10)
                        wskaznik_wioska->odl_ranni=wskaznik_wioska->odl_ranni*(-1);
                }

                else
                    uleczyciel_petla=false;
                } while(uleczyciel_petla==true);
            } break;

            case 'j':{
                wskaznik_wioska->wioska_domy();

                if(wskaznik_wioska->wyb_wioska=='a')
                {
                    short dodanie_ludnosci=0;

                            system("cls");
                            cout << endl;
                            cout << " # Dodawanie LUDnosci" << endl << endl;

                            cout << " # Aktualnie masz " << wskaznik_wioska->lud << " LUDnosci" << endl << endl;

                            cout << " # Koszt jednego LUDzia to   WARZ:3 MIE:3" << endl;
                            cout << " # Zuzycie na jednego LUDzia to WARZ:1 i MIE:1 na ture" << endl << endl;

                            cout << "   Aby stworzyc kolejnych LUDzi wpisz liczbe LUDu jaka chcesz stworzyc i nacisnij enter" << endl;
                            cout << "   Aby wyjsc wpisz '0' i nacisnij enter..." << endl << endl;

                            cout << " # Wskaz liczbe LUDnosci jaka chcesz dodac: "; cin >> dodanie_ludnosci;

                    if(dodanie_ludnosci!=0 && (dodanie_ludnosci + wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol)<=wskaznik_wioska->b_domy*10)
                    {
                        do{
                                system("cls");
                                cout << endl;
                                cout << " # Aktualnie masz " << wskaznik_wioska->lud + wskaznik_wioska->woj + wskaznik_wioska->rol << " populacji" << endl;
                                cout << " # Chcesz dodac " << dodanie_ludnosci << " LUDzi" << endl;
                                cout << " # To bedzie kosztowalo WARZ:" << dodanie_ludnosci*3 << " MIE:" << dodanie_ludnosci*3 << " a zuzycie na dzien to WARZ:" << dodanie_ludnosci << " i MIE:" << dodanie_ludnosci << endl;
                                cout << " # Czy chcesz kontynuowac? Tak(t) / Nie(n)" << endl;
                                wskaznik_wioska->wyb_wioska = getch();
                        }while(wskaznik_wioska->wyb_wioska!='t' && wskaznik_wioska->wyb_wioska!='n');
                    }

                    else
                    {
                        system("cls");
                        cout << endl;
                        cout << " # Nie mozesz dodac tylu LUDzi!";
                        Sleep(2000);
                    }

                    if(wskaznik_wioska->wyb_wioska=='t' && wskaznik_wioska->warz>=dodanie_ludnosci*3 && wskaznik_wioska->mie>=dodanie_ludnosci*3)
                    {
                        wskaznik_wioska->warz-=dodanie_ludnosci*3;
                        wskaznik_wioska->mie-=dodanie_ludnosci*3;
                        wskaznik_wioska->lud+=dodanie_ludnosci;
                        system("cls");
                        cout << endl;
                        cout << " # Dodales " << dodanie_ludnosci << " LUDnosci!";
                        Sleep(2000);
                    }

                    else if(dodanie_ludnosci!=0 && wskaznik_wioska->wyb_wioska=='t')
                    {
                        system("cls");
                        cout << endl;
                        cout << " # Za malo surowcow!";
                        Sleep(2000);
                    }
                }
            } break;

            case 'w':{
                bool_wioska=false;
                wskaznik_wioska->imie = "-";
                wskaznik_wioska->dni = 0;
            } break;

            case 'x':{
                ofstream plik_autozapis;

                wskaznik_wioska->dni += 1;

                wskaznik_wioska->dre += wskaznik_wioska->b_drwal*2 + wskaznik_wioska->p_siekiera*2;
                wskaznik_wioska->kam += wskaznik_wioska->b_kopalnia*2 + wskaznik_wioska->p_kilof*2;
                if(wskaznik_wioska->b_kopalnia>=3)
                    wskaznik_wioska->zel += wskaznik_wioska->b_kopalnia + wskaznik_wioska->p_kilof;

                wskaznik_wioska->warz += (wskaznik_wioska->b_pola*3) + (wskaznik_wioska->p_motyka*2);
                wskaznik_wioska->mie += (wskaznik_wioska->b_lowczy*3) + (wskaznik_wioska->p_luki*2);

                wskaznik_wioska->warz -= wskaznik_wioska->lud - (wskaznik_wioska->rol*2) - wskaznik_wioska->woj;
                if(wskaznik_wioska->warz<0)
                {
                    wskaznik_wioska->warz=0;
                    if(wskaznik_wioska->jedzenie_na_minusie>0)
                    {
                        wskaznik_wioska->jedzenie_na_minusie--;
                        if(wskaznik_wioska->jedzenie_na_minusie==0)
                            wskaznik_wioska->lud--;
                    }
                    if(wskaznik_wioska->jedzenie_na_minusie<=0)
                        wskaznik_wioska->jedzenie_na_minusie+=7;
                }
                wskaznik_wioska->mie -= wskaznik_wioska->lud - wskaznik_wioska->rol - (wskaznik_wioska->woj*2);
                if(wskaznik_wioska->mie<0)
                {
                    wskaznik_wioska->mie=0;
                    if(wskaznik_wioska->jedzenie_na_minusie>0)
                    {
                        wskaznik_wioska->jedzenie_na_minusie--;
                        if(wskaznik_wioska->jedzenie_na_minusie==0)
                            wskaznik_wioska->lud--;
                    }
                    if(wskaznik_wioska->jedzenie_na_minusie<=0)
                        wskaznik_wioska->jedzenie_na_minusie+=7;
                }
                if(wskaznik_wioska->warz>0 && wskaznik_wioska->mie>0)
                    wskaznik_wioska->jedzenie_na_minusie=-1;

                if(wskaznik_historie->odliczanie>0)
                    wskaznik_historie->odliczanie--;
                if(wskaznik_historie->odliczanie<0)
                    wskaznik_historie->odliczanie++;
                przeczytane=false;

                if(wskaznik_historie->odliczanie==0)
                    {
                        wskaznik_historie->historia=(std::rand() % 27)+1;
                        if(wskaznik_historie->historia>10)
                            wskaznik_historie->odliczanie=-4;
                        else if(wskaznik_historie->historia==1 ||
                                wskaznik_historie->historia==14)
                            wskaznik_historie->odliczanie=6;
                        else if(wskaznik_historie->historia>1&&wskaznik_historie->historia<5)
                            wskaznik_historie->odliczanie=7;
                        else if(wskaznik_historie->historia==5)
                            wskaznik_historie->odliczanie=9;
                        else if(wskaznik_historie->historia==6 ||
                                wskaznik_historie->historia==11 ||
                                wskaznik_historie->historia==12 ||
                                wskaznik_historie->historia==15)
                            wskaznik_historie->odliczanie=7;
                        else if(wskaznik_historie->historia==7 ||
                                wskaznik_historie->historia==13)
                            wskaznik_historie->odliczanie=5;
                        else if(wskaznik_historie->historia==8)
                            wskaznik_historie->odliczanie=9;
                        else if(wskaznik_historie->historia==9)
                            wskaznik_historie->odliczanie=5;
                        else if(wskaznik_historie->historia==10)
                            wskaznik_historie->odliczanie=4;
                    }

                wskaznik_wioska->odl_ranni--;
                if(wskaznik_wioska->odl_ranni==0 && (wskaznik_wioska->lud+1+wskaznik_wioska->woj+wskaznik_wioska->rol)<=wskaznik_wioska->b_domy*10)
                {
                    wskaznik_wioska->ranni--;
                    wskaznik_wioska->lud++;
                }

                if(slot_zapisu == '1')
                    plik_autozapis.open("save1.txt");

                if(slot_zapisu == '2')
                    plik_autozapis.open("save2.txt");

                if(slot_zapisu == '3')
                    plik_autozapis.open("save3.txt");

                system("cls");
                cout << endl << "   Wieczor "; Sleep(200);

                plik_autozapis << wskaznik_wioska->imie << endl;
                plik_autozapis << wskaznik_wioska->dni << endl;
                plik_autozapis << wskaznik_wioska->dre << endl;
                plik_autozapis << wskaznik_wioska->kam << endl;
                plik_autozapis << wskaznik_wioska->zel << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << wskaznik_wioska->warz << endl;
                plik_autozapis << wskaznik_wioska->mie << endl;
                plik_autozapis << wskaznik_wioska->bro << endl;
                plik_autozapis << wskaznik_wioska->lud << endl;
                plik_autozapis << wskaznik_wioska->woj << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << wskaznik_wioska->rol << endl;
                plik_autozapis << wskaznik_wioska->atk << endl;
                plik_autozapis << wskaznik_wioska->obr << endl;
                plik_autozapis << wskaznik_wioska->b_mur << endl;
                plik_autozapis << wskaznik_wioska->b_kopalnia << endl;

                system("cls");
                cout << endl << "   Noc "; Sleep(200);

                plik_autozapis << wskaznik_wioska->b_lowczy << endl;
                plik_autozapis << wskaznik_wioska->b_chata << endl;
                plik_autozapis << wskaznik_wioska->b_drwal << endl;
                plik_autozapis << wskaznik_wioska->b_koszary << endl;
                plik_autozapis << wskaznik_wioska->b_jaskinia << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << wskaznik_wioska->b_pola << endl;
                plik_autozapis << wskaznik_wioska->b_uleczyciel << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << wskaznik_wioska->b_domy << endl;
                plik_autozapis << wskaznik_wioska->p_kilof << endl;

                system("cls");
                cout << endl << "   Swit "; Sleep(200);

                plik_autozapis << wskaznik_wioska->p_siekiera << endl;
                plik_autozapis << wskaznik_wioska->p_motyka << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << wskaznik_wioska->p_luki << endl;
                plik_autozapis << wskaznik_historie->historia << endl;

                cout << ". "; Sleep(200);

                plik_autozapis << wskaznik_historie->odliczanie << endl;
                plik_autozapis << wskaznik_wioska->ranni << endl;
                plik_autozapis << wskaznik_wioska->odl_ranni << endl;
                plik_autozapis << wskaznik_wioska->jedzenie_na_minusie << endl;

                plik_autozapis.close();

                system("cls");
                cout << endl << "   Zapisuje "; Sleep(200); cout << ". "; Sleep(200); cout << ". "; Sleep(200); cout << ". "; Sleep(200);

                system("cls");
                cout << endl << "   ### Dzien " << wskaznik_wioska->dni << " ###"; Sleep(1000);
            } break;

            case 'y':{
                if(wskaznik_wioska->wioska_op_prog==1)
                {
                system("cls");
                cout << endl;
                cout << "   ### STATYSTYKI PROGRAMISTYCZNE ###" << endl << endl;

                cout << "     Historia: " << wskaznik_historie->historia << endl;
                cout << "     Odliczanie historii: " << wskaznik_historie->odliczanie << endl << endl;

                cout << "   SAVE:" << endl;
                cout << "   wskaznik_wioska->imie : " << wskaznik_wioska->imie << endl;
                cout << "   wskaznik_wioska->dni : " << wskaznik_wioska->dni << endl;
                cout << "   wskaznik_wioska->dre : " << wskaznik_wioska->dre << endl;
                cout << "   wskaznik_wioska->kam : " << wskaznik_wioska->kam << endl;
                cout << "   wskaznik_wioska->zel : " << wskaznik_wioska->zel << endl;
                cout << "   wskaznik_wioska->warz : " << wskaznik_wioska->warz << endl;
                cout << "   wskaznik_wioska->mie : " << wskaznik_wioska->mie << endl;
                cout << "   wskaznik_wioska->bro : " << wskaznik_wioska->bro << endl;
                cout << "   wskaznik_wioska->lud : " << wskaznik_wioska->lud << endl;
                cout << "   wskaznik_wioska->woj : " << wskaznik_wioska->woj << endl;
                cout << "   wskaznik_wioska->rol : " << wskaznik_wioska->rol << endl;
                cout << "   wskaznik_wioska->atk : " << wskaznik_wioska->atk << endl;
                cout << "   wskaznik_wioska->obr : " << wskaznik_wioska->obr << endl;
                cout << "   wskaznik_wioska->b_mur : " << wskaznik_wioska->b_mur << endl;
                cout << "   wskaznik_wioska->b_kopalnia : " << wskaznik_wioska->b_kopalnia << endl;
                cout << "   wskaznik_wioska->b_lowczy : " << wskaznik_wioska->b_lowczy << endl;
                cout << "   wskaznik_wioska->b_chata : " << wskaznik_wioska->b_chata << endl;
                cout << "   wskaznik_wioska->b_drwal : " << wskaznik_wioska->b_drwal << endl;
                cout << "   wskaznik_wioska->b_koszary : " << wskaznik_wioska->b_koszary << endl;
                cout << "   wskaznik_wioska->b_jaskinia : " << wskaznik_wioska->b_jaskinia << endl;
                cout << "   wskaznik_wioska->b_pola : " << wskaznik_wioska->b_pola << endl;
                cout << "   wskaznik_wioska->b_uleczyciel : " << wskaznik_wioska->b_uleczyciel << endl;
                cout << "   wskaznik_wioska->b_domy : " << wskaznik_wioska->b_domy << endl;
                cout << "   wskaznik_wioska->p_kilof : " << wskaznik_wioska->p_kilof << endl;
                cout << "   wskaznik_wioska->p_siekiera : " << wskaznik_wioska->p_siekiera << endl;
                cout << "   wskaznik_wioska->p_motyka : " << wskaznik_wioska->p_motyka << endl;
                cout << "   wskaznik_wioska->p_luki : " << wskaznik_wioska->p_luki << endl;
                cout << "   wskaznik_wioska->ranni : " << wskaznik_wioska->ranni << endl;
                cout << "   wskaznik_wioska->odl_ranni : " << wskaznik_wioska->odl_ranni << endl;
                cout << "   wskaznik_wioska->jedzenie_na_minusie : " << wskaznik_wioska->jedzenie_na_minusie << endl;

                cout << endl;
                cout << "  Nacisnij cokolwiek aby wyjsc..." << endl;

                wskaznik_wioska->wyb_wioska=getch();
                }
            } break;
        }
    }while(bool_wioska==true);

}
