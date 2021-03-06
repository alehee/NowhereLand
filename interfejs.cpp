#include <iostream>
#include "interfejs.h"
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

// DAJE TUTAJ ZMIENNA KOLOR BO NIE CHCE MI SIE JEJ UMIESZCZAC GDZIES DALEKO!
short kolor = 1;
string ver_i = "2.0";

void banner_interfejs()
{
    cout << "     *** Nowhere Land ***" << endl;
    cout << "  Competitive Edition v. " << ver_i << endl;
}

void nacisnij()
{
    char wyb = getch();
    system("cls");
    banner_interfejs();
    cout << "             Samouczek" << endl << endl;
}

Menu::Menu(char wy, bool o_p)
{
    wyb_menu = wy;
    op_prog = o_p;
}

Wioska::Wioska(string im, int dn, int dr, int ka, int ze, int wa, int mi, int br, int lu, int wo, int ro, int att, int ob, int mu, int ko, int lo, int ch, int dw, int ksz, int ja, int po, int ul, int domyy, int kil, int sie, int mot, int luk, int ran, short odl_ran, short jed_n_min,
               bool w_o_p)
{
    imie = im;
    dni = dn;
    dre = dr;
    kam = ka;
    zel = ze;
    warz = wa;
    mie = mi;
    bro = br;
    lud = lu;
    woj = wo;
    rol = ro;
    atk = att;
    obr = ob;
    b_mur = mu;
    b_kopalnia = ko;
    b_lowczy = lo;
    b_chata = ch;
    b_drwal = dw;
    b_koszary = ksz;
    b_jaskinia = ja;
    b_pola = po;
    b_uleczyciel = ul;
    b_domy = domyy;
    p_kilof = kil;
    p_siekiera = sie;
    p_motyka = mot;
    p_luki = luk;
    ranni = ran;
    odl_ranni = odl_ran;
    jedzenie_na_minusie = jed_n_min;

    wioska_op_prog = w_o_p;
}

void Wioska::surki_interfejs()
{
    int wspolczynnik_surki=0;

    cout << "      ### " << imie << " DNI:" << dni << " DRE:" << dre << "(+" << (b_drwal*2) + (p_siekiera*2) << ") KAM:" << kam << "(+" << (b_kopalnia*2) + (p_kilof*2) << ") ZEL:" << zel << "(+";
    if(b_kopalnia>2)
        cout << b_kopalnia + p_kilof;
    else
        cout << "0";
    cout << ") WARZ:" << warz;
    wspolczynnik_surki = ((b_pola*3) + (p_motyka*2)) - (lud - (rol*2) - woj);
    if(wspolczynnik_surki>=0)
        cout << "(+" << wspolczynnik_surki;
    else if(wspolczynnik_surki<0)
        cout << "(" << wspolczynnik_surki;
    wspolczynnik_surki=0;
    cout << ") MIE:" << mie;
    wspolczynnik_surki = ((b_lowczy*3) + (p_luki*2)) - (lud - rol - (woj*2));
    if(wspolczynnik_surki>=0)
        cout << "(+" << wspolczynnik_surki;
    else if(wspolczynnik_surki<0)
        cout << "(" << wspolczynnik_surki;
    cout << ") BRO:" << bro << " ###" <<endl;
    cout << "                            ### LUD:" << lud << " WOJ:" << woj << " ROL:" << rol << " ATK:" << atk << " OBR:" << obr << " ###" << endl << endl;
}

void Menu::intro()
{
    cout << endl;
    cout << "   *** Riverlake Studios ***" << endl;
    Sleep(500);
    cout << "         Prezentuje..." << endl;
    Sleep(1000);
}

void Menu::start()
{

    system("cls");

    banner_interfejs();
    cout << endl;
    cout << "  a. Nowa gra" << endl;
    cout << "  b. Wczytaj gre" << endl;
    cout << "  c. Opcje" << endl;
    cout << "  d. O grze" << endl;
    cout << "  e. Samouczek" << endl << endl;

    cout << "  Nacisnij cokolwiek innego, aby wyjsc..." << endl;
    wyb_menu = getch();
}

void Menu::nowa_gra()
{
    fstream save;
    string bufor_nowa_gra1, bufor_nowa_gra2;

    system("cls");

    banner_interfejs();
    cout << "             Nowa gra" << endl << endl;

    save.open("save1.txt", ios::in | ios::out);

    if(save.good() == true)
    {
        getline(save, bufor_nowa_gra1);
        getline(save, bufor_nowa_gra2);
    }

    else
    {
        system("cls");
        cout << "Nie udalo sie otworzyc pliku!";
        Sleep(1000);
        system("exit");
    }

    save.close();

    if(bufor_nowa_gra1 == "-" && bufor_nowa_gra2 == "0")
        cout << "  1. Pusty slot" << endl;

    else
        cout << "  1. " << bufor_nowa_gra1 << ", " << bufor_nowa_gra2 << " dni" << endl;

    save.open("save2.txt", ios::in | ios::out);

    if(save.good() == true)
    {
        getline(save, bufor_nowa_gra1);
        getline(save, bufor_nowa_gra2);
    }

    else
    {
        system("cls");
        cout << "Nie udalo sie otworzyc pliku!";
        Sleep(1000);
        system("exit");
    }

    save.close();

    if(bufor_nowa_gra1 == "-" && bufor_nowa_gra2 == "0")
        cout << "  2. Pusty slot" << endl;

    else
        cout << "  2. " << bufor_nowa_gra1 << ", " << bufor_nowa_gra2 << " dni" << endl;

    save.open("save3.txt", ios::in | ios::out);

    if(save.good() == true)
    {
        getline(save, bufor_nowa_gra1);
        getline(save, bufor_nowa_gra2);
    }

    else
    {
        system("cls");
        cout << "Nie udalo sie otworzyc pliku!";
        Sleep(1000);
        system("exit");
    }

    save.close();

    if(bufor_nowa_gra1 == "-" && bufor_nowa_gra2 == "0")
        cout << "  3. Pusty slot" << endl;

    else
        cout << "  3. " << bufor_nowa_gra1 << ", " << bufor_nowa_gra2 << " dni" << endl;

    wyb_menu = getch();
}

void Menu::wczytaj_gre()
{
    fstream save;
    string bufor_nowa_gra1, bufor_nowa_gra2;

    system("cls");

    banner_interfejs();
    cout << "             Wczytaj gre" << endl << endl;

    save.open("save1.txt", ios::in | ios::out);

    if(save.good() == true)
    {
        getline(save, bufor_nowa_gra1);
        getline(save, bufor_nowa_gra2);
    }

    else
    {
        system("cls");
        cout << "Nie udalo sie otworzyc pliku!";
        Sleep(1000);
        system("exit");
    }

    save.close();

    if(bufor_nowa_gra1 == "-" && bufor_nowa_gra2 == "0")
        cout << "  1. Pusty slot" << endl;

    else
        cout << "  1. " << bufor_nowa_gra1 << ", " << bufor_nowa_gra2 << " dni" << endl;

    save.open("save2.txt", ios::in | ios::out);

    if(save.good() == true)
    {
        getline(save, bufor_nowa_gra1);
        getline(save, bufor_nowa_gra2);
    }

    else
    {
        system("cls");
        cout << "Nie udalo sie otworzyc pliku!";
        Sleep(1000);
        system("exit");
    }

    save.close();

    if(bufor_nowa_gra1 == "-" && bufor_nowa_gra2 == "0")
        cout << "  2. Pusty slot" << endl;

    else
        cout << "  2. " << bufor_nowa_gra1 << ", " << bufor_nowa_gra2 << " dni" << endl;

    save.open("save3.txt", ios::in | ios::out);

    if(save.good() == true)
    {
        getline(save, bufor_nowa_gra1);
        getline(save, bufor_nowa_gra2);
    }

    else
    {
        system("cls");
        cout << "Nie udalo sie otworzyc pliku!";
        Sleep(1000);
        system("exit");
    }

    save.close();

    if(bufor_nowa_gra1 == "-" && bufor_nowa_gra2 == "0")
        cout << "  3. Pusty slot" << endl;

    else
        cout << "  3. " << bufor_nowa_gra1 << ", " << bufor_nowa_gra2 << " dni" << endl;

    wyb_menu = getch();
}

void Menu::opcje()
{
    do{
    system("cls");

    banner_interfejs();
    cout << "             Opcje" << endl << endl;

    cout << "  a. Pokaz statystyki programistyczne: ";
    if(op_prog==0)
        cout << "NIE" << endl;
    else
        cout << "TAK" << endl;

    cout << "  b. Zmien kolor czcionki: ";
    switch(kolor)
    {
        case 1:{
            cout << "color f";
        } break;
        case 2:{
            cout << "color 2";
        } break;
        case 3:{
            cout << "color 3";
        } break;
        case 4:{
            cout << "color 4";
        } break;
        case 5:{
            cout << "color 5";
        } break;
    }
    cout << endl;

    cout << endl;
    cout << " Nacisnij cokolwiek innego, aby kontynuowac...";

    wyb_menu = getch();

    if(wyb_menu=='a')
    {
        if(op_prog==0)
            op_prog=1;
        else
            op_prog=0;
    }

    if(wyb_menu=='b')
    {
        kolor++;
        if(kolor>5)
            kolor=1;
    }

    switch(kolor)
    {
        case 1:{
            system("color f");
        } break;
        case 2:{
            system("color 2");
        } break;
        case 3:{
            system("color 3");
        } break;
        case 4:{
            system("color 4");
        } break;
        case 5:{
            system("color 5");
        } break;
    }

    }while(wyb_menu=='a'||wyb_menu=='b');
}

void Menu::o_grze()
{
    system("cls");

    banner_interfejs();
    cout << "             O grze" << endl << endl;

    cout << " Gra jest pierwszym projektem poczatkujacego programisty C++." << endl;
    cout << " Jednoczesnie jest to pierwszy projekt Riverlake Studios." << endl;
    cout << " Miejscem powstawania byla piwnica szkolna, pieterko szkolne oraz dom" << endl;
    cout << " Symulatorek wlasnej wioski w CMD..." << endl << endl;

    cout << "   Osoby, ktore wziely udzial:" << endl << endl;

    cout << "    - Aleksander Heese - producent, deweloper i wszystko inne" << endl;
    cout << "    - Przemek - pre-alpha tester, konsultant" << endl;
    cout << "    - Rafal - pre-alpha tester, konsultant" << endl;
    cout << "    - Jamus - beta tester, konsultant" << endl;
    cout << "    - Kamil - beta tester, konsultant" << endl;

    cout << endl;
    cout << "  Nacisnij cokolwiek, aby wyjsc..." << endl;

    wyb_menu = getch();
}

void Menu::samouczek()
{
    system("cls");
    banner_interfejs();
    cout << "             Samouczek" << endl << endl;

    cout << " # Witam w samouczku do gry strategicznej Nowhere Land...";
    nacisnij();

    cout << " # W grze chodzi o to aby rozbudowywac swoja wioske," << endl;
    cout << " # dbac o bezpieczenstwo swoich poddanych i przetrwac w osamotnieniu.";
    nacisnij();

    cout << " # W obrebie gry poruszasz sie naciskajac klawisze na klawiaturze:" << endl << endl;

    cout << "   a. Nowa gra" << endl << endl;

    cout << " # W tym przypadku np, aby wybrac nowa gre nalezy wcisnac przycisk a..." << endl;
    cout << " # Ale to juz w menu, teraz jedziemy dalej";
    nacisnij();

    cout << " # Pokaze Ci teraz jak wyglada interfejs w samej grze abys sie nie zgubil po drodze... ";
    nacisnij();

    cout << "     ### imie " << endl << endl;

    cout << " # Tutaj wypisywane jest Twoje imie abys wiedzial czy masz wczytany poprawny zapis.";
    nacisnij();

    cout << "     ### imie DNI:10" << endl << endl;

    cout << " # Nastepnie widzimy dni jakie przezylismy, czyli ktora mamy runde.";
    nacisnij();

    cout << " # W grze jest kilka surowcow, ktore potrzene sa do przezycia i rozbudowy..." << endl;
    cout << " # Jako ze stanowia rdzen rozgrywki zapoznaj sie z nimi uwaznie";
    nacisnij();

    cout << "     ### imie DNI:10 DRE:12(+2) KAM:13(+2) ZEL:2(+1) WARZ:7(+1) MIE:7(+1)" << endl << endl;

    cout << " # DREwno, KAMien, ZELazo, WARZywa i MIEso." << endl;
    cout << " # DREwno, KAMien i ZELazo potrzebne sa do rozbudowy i tworzenia bronii dla armii." << endl;
    cout << " # Natomiast WARZywa i MIEso to surowce potrzebne do wyzywienia wioski i rekrutacji armii." << endl;
    cout << " # Po dwukropku widzisz stan surowca w magazynie, a w nawiasie jego przyrost na dzien.";
    nacisnij();

    cout << "     ### imie DNI:10 DRE:12(+2) KAM:13(+2) ZEL:2(+1) WARZ:7(+1) MIE:7(+1)" << endl << endl;

    cout << " # DREwno zdobywasz w budynku DRWAL." << endl;
    cout << " # KAMien w budynku KOPALNIA." << endl;
    cout << " # ZELazo w budynku KOPALNIA po osiagnieciu wymagan." << endl;
    cout << " # WARZywa w budynku POLE." << endl;
    cout << " # MIEso w budynku LOWCZY." << endl;
    cout << " # Ale rozbudowe budynkow omowimy pozniej.";
    nacisnij();

    cout << "     ### imie DNI:10 DRE:12(+2) KAM:13(+2) ZEL:2(+1) WARZ:7(+1) MIE:7(+1) BRO:1 ###" << endl << endl;

    cout << " # Nastepnie mamy ilosc naszej niezagospodarowanej BROnii, ktora moze byc rozdana wojownikom," << endl;
    cout << " # lub ludziom przy obronie wioski. Bron wykuwa sie w KOSZARACH.";
    nacisnij();

    cout << "     ### imie DNI:10 DRE:12(+2) KAM:13(+2) ZEL:2(+1) WARZ:7(+1) MIE:7(+1) BRO:1 ###" << endl;
    cout << "                         ### LUD:5 WOJ:3 ROL:1" << endl << endl;

    cout << " # Tutaj z kolei widac ilosc LUDnosci, WOJownikow i ROLnikow w wiosce." << endl;
    cout << " # Ilosc LUDnosci pozwala efektywniej bronic wioski, ale i rekrutowac wojownikow oraz rolnikow." << endl;
    cout << " # Mozna ich rekrutowac w DOMY." << endl;
    cout << " # WOJownicy dodaja wiosce ataku, ale tez jedza wiecej MIEsa niz ludzie. Rekrutuje sie ich w KOSZARY." << endl;
    cout << " # ROLnicy natomiast to obroncy, ktorzy jedza wiecej WARZyw i sa rekrutowani w POLA.";
    nacisnij();

    cout << "     ### imie DNI:10 DRE:12(+2) KAM:13(+2) ZEL:2(+1) WARZ:7(+1) MIE:7(+1) BRO:1 ###" << endl;
    cout << "                         ### LUD:5 WOJ:3 ROL:1 ATK:15 OBR:15 ###" << endl << endl;

    cout << " # No to ostatnie skladniki interfejsu czyli ATaK i OBRona." << endl;
    cout << " # Wbrew pozorom oba sluza do odpierania atakow na wiosce, jednak ataki sa w dwoch fazach:" << endl;
    cout << " # ATaKu i OBRony, wiec oba wskazniki powinny byc na rowno wysokim szczeblu." << endl;
    cout << " # ATaK zyskujemy dzieki LUDnosci, WOJownikom i KOSZAROM, " << endl;
    cout << " # Natomiast OBRone dzieki LUDnosci, ROLnikom i MUROWI";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl << endl;

    cout << " # Na murze mozesz sprawdzic, rozgladajac sie, czy nic wiosce nie zagraza, " << endl;
    cout << " # oraz wspomaga on Twoja obrone.";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl << endl;

    cout << " # Kopalnia to miejsce gdzie zdobywamy kamien i zelazo co ture." << endl;
    cout << " # Mozna tam takze ulepszyc kilof co zwieksza przyrost tych surowcow!";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl << endl;

    cout << " # Lowczy zdobywa mieso dla Ciebie! Tutaj takze mozna ulepszyc luk lowczych";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl;
    cout << "   d. Chata wodza  lvl 1" << endl << endl;

    cout << " # Chata wodza to Twoje miejsce dowodzenia gdzie tworzysz budynki wioski";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl;
    cout << "   d. Chata wodza  lvl 1" << endl;
    cout << "   e. Drwal        lvl 1" << endl << endl;

    cout << " # Drwal zdobywa dla Ciebie drewno. Mozesz tez tam ulepszyc siekiere";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl;
    cout << "   d. Chata wodza  lvl 1" << endl;
    cout << "   e. Drwal        lvl 1" << endl;
    cout << "   f. Koszary      lvl 1" << endl << endl;

    cout << " # Koszary to miejsce gdzie mozesz rekrutowac WOJownikow," << endl;
    cout << " # tworzyc bron i dodaja Ci one takze ATaKu";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl;
    cout << "   d. Chata wodza  lvl 1" << endl;
    cout << "   e. Drwal        lvl 1" << endl;
    cout << "   f. Koszary      lvl 1" << endl;
    cout << "   g. Jaskinia     lvl 1" << endl << endl;

    cout << " # Jaskinia, w razie porazki w bitwie, pozwala zachowac czesc surowcow.";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl;
    cout << "   d. Chata wodza  lvl 1" << endl;
    cout << "   e. Drwal        lvl 1" << endl;
    cout << "   f. Koszary      lvl 1" << endl;
    cout << "   g. Jaskinia     lvl 1" << endl;
    cout << "   h. Pola         lvl 1" << endl << endl;

    cout << " # Pola to miejsce gdzie zdobywasz WARZywa i ulepszasz motyke," << endl;
    cout << " # ktora daje wiecej WARZyw! Rekrutujesz tu takze ROLnikow!";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl;
    cout << "   d. Chata wodza  lvl 1" << endl;
    cout << "   e. Drwal        lvl 1" << endl;
    cout << "   f. Koszary      lvl 1" << endl;
    cout << "   g. Jaskinia     lvl 1" << endl;
    cout << "   h. Pola         lvl 1" << endl;
    cout << "   i. Uleczyciel   lvl 1" << endl << endl;

    cout << " # Do uleczyciela trafiaja wszyscy ranni po walkach" << endl;
    cout << " # Zbuduj uleczyciela a nie bedziesz tracil ludzi!";
    nacisnij();

    cout << " # Teraz zapoznam Cie z panelem Twojej wioski: " << endl << endl;

    cout << "   a. Mur          lvl 1" << endl;
    cout << "   b. Kopalnia     lvl 1" << endl;
    cout << "   c. Lowczy       lvl 1" << endl;
    cout << "   d. Chata wodza  lvl 1" << endl;
    cout << "   e. Drwal        lvl 1" << endl;
    cout << "   f. Koszary      lvl 1" << endl;
    cout << "   g. Jaskinia     lvl 1" << endl;
    cout << "   h. Pola         lvl 1" << endl;
    cout << "   i. Uleczyciel   lvl 1" << endl;
    cout << "   j. Domy         lvl 1" << endl << endl;

    cout << " # Ostatnim budynkiem sa domy, ktore pozwalaja miec wiecej" << endl;
    cout << " # LUDzi, WOJownikow i ROLnikow, a takze rekrutowac LUDzi!";
    nacisnij();

    cout << " # W grze mozesz otrzymac takze powiadomienia na poczatku rundy." << endl;
    cout << " # Informuja one o tym czy cos niedobrego (lub dobrego) dzieje sie" << endl;
    cout << " # z Twoja wioska. " << endl << endl;

    cout << " # W grze najwazniejszy aspektami sa: zapewnianie pozywienia," << endl;
    cout << " # rozbudowa armii oraz wioski i obrona jej co wymaga wlasnie" << endl;
    cout << " # rozbudowy Twoich posiadlosci.";
    nacisnij();

    cout << " # Kontroluj przyrost zywnosci, buduj nowe budynki w Chacie wodza" << endl;
    cout << " # i sprawdzaj na murze czy nic Ci nie grozi, a wszystko bedzie dobrze!" << endl << endl;

    cout << " # Nie boj sie chodzic po budynkach i sprawdzac co mozesz rozwinac!" << endl;
    cout << " # Pamietaj o swoich LUDziach i zywieniu ich!" << endl;
    cout << " # Upracuj plan rozwoju i zostan wymarzonym wodzem!" << endl << endl;

    cout << " # I nie martw sie, w budynkach takze podpowiadam co mozesz zrobic" << endl;
    cout << " # i za co dany budynek odpowiada!" << endl << endl;

    cout << " # Gra automatycznie zapisuje stan gry po kazdym pojsciu spac!" << endl << endl;

    cout << " # POWODZENIA!";
    wyb_menu = getch();
}

void Wioska::wioska_menu()
{
    system("cls");

    surki_interfejs();

    if(b_mur!=0)
        cout << "   a. Mur          lvl " << b_mur << endl;
    if(b_kopalnia!=0)
        cout << "   b. Kopalnia     lvl " << b_kopalnia << endl;
    if(b_lowczy!=0)
        cout << "   c. Lowczy       lvl " << b_lowczy << endl;
    if(b_chata!=0)
        cout << "   d. Chata wodza  lvl " << b_chata << endl;
    if(b_drwal!=0)
        cout << "   e. Drwal        lvl " << b_drwal << endl;
    if(b_koszary!=0)
        cout << "   f. Koszary      lvl " << b_koszary << endl;
    if(b_jaskinia!=0)
        cout << "   g. Jaskinia     lvl " << b_jaskinia << endl;
    if(b_pola!=0)
        cout << "   h. Pola         lvl " << b_pola << endl;
    if(b_uleczyciel!=0)
        cout << "   i. Uleczyciel   lvl " << b_uleczyciel << endl;
    if(b_domy!=0)
        cout << "   j. Domy         lvl " << b_domy << endl;

    cout << endl << endl;

    cout << "   x. Idz spac" << endl;
    cout << "   w. Wyjdz" << endl << endl;

    if(wioska_op_prog==1)
        cout << "   y. Statystyki programistyczne" << endl << endl;

    cout << " Nacisnij swoj wybor...";
    wyb_wioska = getch();
}

void Wioska::wioska_mur()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_mur < 10)
        {
        cout << " # Podchodzisz do swojej palisady... znaczy, poteznego muru lvl " << b_mur << endl;
        cout << " # Ja bym zbytnio na niego nie liczyl.";
        }
    if(b_mur >= 10 && b_mur <= 29)
        {
        cout << " # Podchodzisz do swojej  muru lvl " << b_mur << endl;
        cout << " # Wyglada schludnie i porzadnie, nie to co Ty!";
        }
    if(b_mur == 30)
        {
        cout << " # Murzysko jak ta lala! Lvl " << b_mur << endl;
        cout << " # To juz kawal walu obronnego!";
        }

    cout << endl << endl;

    cout << " # Twoj mur daje Ci " << b_mur*2 << " obrony!" << endl << endl;

    cout << "    a. Rozejrzyj sie" << endl;

    wyb_wioska = getch();
}

void Wioska::wioska_kopalnia()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_kopalnia < 3)
        {
        cout << " # Poki co mala dziurka... znaczy dolek, tak dolek lepiej brzmi." << endl;
        cout << " # W kazdym razie lvl " << b_kopalnia << ". Ale zelaza nadal nie widac!";
        }
    if(b_kopalnia >= 3 && b_kopalnia < 10)
        {
        cout << " # Coraz glebiej! That's what she said! Ale poziom " << b_kopalnia << endl;
        cout << " # To nadal ponizej sredniej krajowej!";
        }
    if(b_kopalnia >= 10 && b_kopalnia <= 29)
        {
        cout << " # Do pracy rodacy! Kopalnia poziomu " << b_kopalnia << endl;
        cout << " # Staje sie coraz efektywniejsza! Dig that iron bro!";
        }
    if(b_kopalnia == 30)
        {
        cout << " # Twoja kopalnia jest glebsza niz kopalnie Krasnolodow w Morii!" << endl;
        cout << " # Szacun bo to juz " << b_kopalnia << " poziom!";
        }

    cout << endl << endl;
    cout << " # Twoj przyrost KAMienia na dzien to " << b_kopalnia*2 + p_kilof*2;
    if(b_kopalnia>=3)
        cout << endl << " # Twoj przyrost ZELaza na dzien to " << b_kopalnia + p_kilof;
    cout << endl << " # Twoj poziom kilofa to " << p_kilof;

    cout << endl << endl;
    cout << "   a. Ulepsz kilof          ";
    if(p_kilof>0)
        cout << "DRE:" << p_kilof*20 << " KAM:" << p_kilof*20 << " ZEL:" << p_kilof*20;
    else
        cout << "DRE:10 KAM:10 ZEL:10";
    wyb_wioska = getch();
}

void Wioska::wioska_lowczy()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_lowczy < 10)
    {
        cout << " # Podchodzisz do lichego domku i widzisz siwowlosego staruszka z wlocznia," << endl;
        cout << " # ktory niesie malego krolika." << endl;
        cout << " # Zawsze cos, wkoncu to " << b_lowczy << " lvl.";
    }
    if(b_lowczy >= 10 && b_lowczy <= 29)
    {
        cout << " # Trzy chatki to juz tlum! Twoi lowczy maja juz " << b_lowczy << " poziom!" << endl;
        cout << " # Ale ten siwy dalej z ta wlocznia stoi. Czy z nim wszystko okej?";
    }
    if(b_lowczy == 30)
    {
        cout << " # Twoi lowczy sa czujni i potrafia upolowac jelenia z zamknietymi oczami!" << endl;
        cout << " # W koncu maja juz " << b_lowczy << " lvl!";
    }

    cout << endl << endl;
    cout << " # Twoj przyrost MIEsa na dzien to: " << b_lowczy*4 + p_luki*2 << endl;
    cout << " # Twoj poziom lukow to: " << p_luki;

    if(p_luki<3)
    {
        cout << endl << endl;
        cout << "   a. Ulepsz luki           ";
        if(p_luki>0)
            cout << "DRE:" << p_luki*20 << " KAM:" << p_luki*20 << " ZEL:" << p_luki*20;
        else
            cout << "DRE:10 KAM:10 ZEL:10";
    }

    if(b_lowczy == 30)
    {
        cout << endl;
        cout << "   b. Porozmawiaj z siwym mezczyzna";
    }

    wyb_wioska = getch();
}

void Wioska::wioska_chata()
{
    bool chata=true;

while(chata == true)
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_chata < 5)
    {
        cout << " # Ciasne, ale wlasne bo to " << b_chata << " poziom." << endl;
        cout << " # Witaj, " << imie << " w swoim centrum dowodzenia!";
    }
    if(b_chata >= 5 && b_chata <= 9)
    {
        cout << " # Twoja chata wyglada jak prawdziwe dzielo sztuki " << b_chata << " poziomu " << imie << "!";
    }
    if(b_chata == 10)
    {
        cout << " # Chcesz miec duzy dom pelen cudzych zon? To masz!" << endl;
        cout << " # I to na " << b_chata << " poziomie!" << endl;
        cout << " # Jestes niezmordowanym przywodca " << imie << "!";
    }

    cout << endl << endl;
    cout << " # TWOJE MOZLIWOSCI ROZBUDOWY:     ZASOBY:" << endl;

    cout << endl << "   a. Mur,         poziom " << b_mur << "      ";
    if(b_mur>0 && b_mur<30)
        cout << "DRE:" << b_mur*10 << " KAM:" << b_mur*15 << " ZEL:" << b_mur*5;
    cout << endl << "   b. Kopalnia,    poziom " << b_kopalnia << "      ";
    if(b_kopalnia>0 && b_kopalnia<30)
        cout << "DRE:" << b_kopalnia*5;
    if(b_kopalnia>=3 && b_kopalnia<30)
        cout << " KAM:" << b_kopalnia*10;
    cout << endl << "   c. Lowczy,      poziom " << b_lowczy << "      ";
    if(b_lowczy>0 && b_lowczy<30)
        cout << "DRE:" << b_lowczy*10;
    if(b_lowczy>=5 && b_lowczy<30)
        cout << " KAM:" << b_lowczy*5;
    cout << endl << "   d. Chata wodza, poziom " << b_chata << "      ";
    if(b_chata<30)
        cout << "DRE:" << b_chata*20 << " KAM:" << b_chata*20 << " ZEL:" << b_chata*20;
    cout << endl << "   e. Drwal,       poziom " << b_drwal << "      ";
    if(b_drwal<30)
        cout << "DRE:" << b_drwal*5;
    if(b_drwal>=5 && b_drwal<30)
        cout << " KAM:" << b_drwal*10 << " ZEL:" << b_drwal*5;
    cout << endl << "   f. Koszary,     poziom " << b_koszary << "      ";
    if(b_koszary>0 && b_koszary<30)
        cout << "DRE:" << b_koszary*15 << " KAM:" << b_koszary*15 << " ZEL:" << b_koszary*20;
    cout << endl << "   g. Jaskinia,    poziom " << b_jaskinia << "      ";
    if(b_jaskinia>0 && b_jaskinia<30)
        cout << "KAM:" << b_jaskinia*10 << " ZEL:" << b_jaskinia*10;
    cout << endl << "   h. Pola,        poziom " << b_pola << "      ";
    if(b_pola>0 && b_pola<30)
        cout << "DRE:" << b_pola*10;
    if(b_pola>=5 && b_pola<30)
        cout << " KAM:" << b_pola*15 << " ZEL:" << b_pola*5;
    cout << endl << "   i. Uleczyciel,  poziom " << b_uleczyciel << "      ";
    if(b_uleczyciel>0 && b_uleczyciel<30)
        cout << "DRE:" << b_uleczyciel*30 << " KAM:" << b_uleczyciel*20 << " ZEL:" << b_uleczyciel*10;
    cout << endl << "   j. Domy,        poziom " << b_domy << "      ";
    if(b_domy<30)
        cout << "DRE:" << b_domy*5;
    if(b_domy>=5 && b_domy<30)
        cout << " KAM:" << b_domy*10 << " ZEL:" << b_pola*5;

    wyb_wioska = getch();

    switch(wyb_wioska)
    {
    case 'a':
        {
            system("cls");
            surki_interfejs();

            cout << " # Mur,            Poziom " << b_mur << endl << endl;

            if(b_mur==0)
            {
                cout << " # Potrzebujesz:   ";
                if(b_drwal<3)
                    cout << "Drwal poziom 3, ";
                if(b_kopalnia<5)
                    cout << "Kopalnia poziom 5, ";

                cout << endl;
                cout << " # Surowce:        Drewno 10, Kamien 15, Zelazo 5" << endl << endl;
            }

            if(b_mur>0)
            {
                cout << " # Surowce:        Drewno " << b_mur*10 << ", Kamien " << b_mur*15 << ", Zelazo " << b_mur*5 << endl << endl;
            }

            cout << " # W zasadzie mur jest ukazaniem Twojej potegi! Daje tez wiecej obrony!" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska == 't' && b_mur>0 && b_mur<30)
            {
                if(dre>= b_mur*10 && kam>=b_mur*15 && zel>=b_mur*5)
                {
                    system("cls");
                    dre-=b_mur*10;
                    kam-=b_mur*15;
                    zel-=b_mur*5;
                    b_mur++;
                    cout << "   Mur, poziom " << b_mur;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska == 't' && b_mur == 0)
            {
                if(b_mur==0 && b_drwal>=3 && b_kopalnia>=5 && dre>=10 && kam>=15 && zel>=5)
                {
                    system("cls");
                    dre-=10;
                    kam-=15;
                    zel-=5;
                    b_mur++;
                    cout << "   Mur, poziom " << b_mur;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow, lub niespelnione wymagania!";
                    Sleep(2000);
                }
            }

        } break;

    case 'b':
        {
            system("cls");
            surki_interfejs();

            cout << " # Kopalnia,   Poziom " << b_kopalnia << endl << endl;

            if(b_kopalnia==0)
            {
                cout << " # Surowce:        Drewno 5" << endl << endl;
            }

            if(b_kopalnia>0 && b_kopalnia<3)
            {
                cout << " # Surowce:        Drewno " << b_kopalnia*5 << endl << endl;
            }

            if(b_kopalnia>=3)
            {
                cout << " # Surowce:        Drewno " << b_kopalnia*5 << ", Kamien " << b_kopalnia*10 << endl << endl;
            }
            cout << " # To Twoje zrodlo kamienia i zelaza! Im wiekszy poziom tym wiekszy zysk!" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska == 't' && b_kopalnia>=3 && b_kopalnia<30)
            {
                if(dre>=b_kopalnia*5 && kam>=b_kopalnia*10)
                {
                    system("cls");
                    dre-=b_kopalnia*5;
                    kam-=b_kopalnia*10;
                    b_kopalnia++;
                    cout << "   Kopalnia, poziom " << b_kopalnia;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska=='t' && b_kopalnia>0 && b_kopalnia<3)
            {
                if(dre>= b_kopalnia*5)
                {
                    system("cls");
                    dre-=b_kopalnia*5;
                    b_kopalnia++;
                    cout << "   Kopalnia, poziom " << b_kopalnia;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska=='t' && b_kopalnia==0)
            {
                if(dre>=5)
                {
                    system("cls");
                    dre-=5;
                    b_kopalnia++;
                    cout << "   Kopalnia, poziom " << b_kopalnia;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow, lub niespelnione wymagania!";
                    Sleep(2000);
                }
            }

        } break;

    case 'c':
        {
            system("cls");
            surki_interfejs();

            cout << " # Lowczy,      Poziom " << b_lowczy << endl << endl;

            if(b_lowczy==0)
            {
                cout << " # Surowce:        Drewno 10" << endl << endl;
            }

            if(b_lowczy>0 && b_lowczy<5)
            {
                cout << " # Surowce:        Drewno " << b_lowczy*10 << endl << endl;
            }

            if(b_lowczy>=5)
            {
                cout << " # Surowce:        Drewno " << b_lowczy*10 << ", Kamien " << b_lowczy*5 << endl << endl;
            }
            cout << " # To Twoje zrodlo miesa! Wazny surowiec aby Twoja wioska przetrwala!" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska=='t' && b_lowczy>=5 && b_lowczy<30)
            {
                if(dre>=b_lowczy*10 && kam>=b_lowczy*5)
                {
                    system("cls");
                    dre-=b_lowczy*10;
                    kam-=b_lowczy*5;
                    b_lowczy++;
                    cout << "   Lowczy, poziom " << b_lowczy;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska=='t' && b_lowczy>0 && b_lowczy<5)
            {
                if(dre>= b_lowczy*10)
                {
                    system("cls");
                    dre-=b_lowczy*10;
                    b_lowczy++;
                    cout << "   Lowczy, poziom " << b_lowczy;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska=='t' && b_lowczy==0)
            {
                if(dre>=10)
                {
                    system("cls");
                    dre-=10;
                    b_lowczy++;
                    cout << "   Lowczy, poziom " << b_lowczy;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow, lub niespelnione wymagania!";
                    Sleep(2000);
                }
            }

        } break;

    case 'd':
        {
            system("cls");
            surki_interfejs();

            cout << " # Chata wodza,  Poziom " << b_chata << endl << endl;

            cout << " # Surowce:        Drewno " << b_chata*20 << ", Kamien " << b_chata*20 << ", Zelazo " << b_chata*20 << endl << endl;

            cout << " # Chata wodza to Twoje centrum budowy, Twoja swiatynia. Wazne zebys mial wygodnie!" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska == 't' && b_chata<10)
            {
                if(dre>= b_chata*20 && kam>=b_chata*20 && zel>=b_chata*20)
                {
                    system("cls");
                    dre-=b_chata*20;
                    kam-=b_chata*20;
                    zel-=b_chata*20;
                    b_chata++;
                    cout << "   Chata wodza, poziom " << b_chata;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

        } break;

    case 'e':
        {
            system("cls");
            surki_interfejs();

            cout << " # Drwal,        Poziom " << b_drwal << endl << endl;


            cout << " # Surowce:        Drewno " << b_drwal*5 << endl << endl;
            if(b_drwal>=5)
                cout << ", Kamien " << b_drwal*10 << ", Zelazo " << b_drwal*5 << endl << endl;

            cout << " # Dzieki drwalom dostajesz drewno, chyba dobry deal nie?" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska == 't' && b_drwal>=5 && b_drwal<30)
            {
                if(dre>= b_drwal*5 && kam>=b_drwal*10 && zel>=b_drwal*5)
                {
                    system("cls");
                    dre-=b_drwal*5;
                    kam-=b_drwal*10;
                    zel-=b_drwal*5;
                    b_drwal++;
                    cout << "   Drwal, poziom " << b_drwal;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska == 't' && b_drwal>0 && b_drwal<5)
            {
                if(dre>= b_drwal*5)
                {
                    system("cls");
                    dre-=b_drwal*5;
                    b_drwal++;
                    cout << "   Drwal, poziom " << b_drwal;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

        } break;

    case 'f':
        {
            system("cls");
            surki_interfejs();

            cout << " # Koszary,      Poziom " << b_koszary << endl << endl;

            if(b_koszary==0)
            {
                cout << " # Potrzebujesz:   ";
                if(b_drwal<2)
                    cout << "Drwal poziom 2, ";
                if(b_kopalnia<2)
                    cout << "Kopalnia poziom 2, ";

                cout << endl;
                cout << " # Surowce:        Drewno 15, Kamien 15, Zelazo 20" << endl << endl;
            }

            if(b_koszary>0)
            {
                cout << " # Surowce:        Drewno " << b_koszary*15 << ", Kamien " << b_koszary*15 << ", Zelazo " << b_koszary*20 << endl << endl;
            }
            cout << " # Koszary pozwalaja rekrutowac zolnierzy i wykuwac bron!" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska == 't' && b_koszary>0 && b_koszary<30)
            {
                if(dre>= b_koszary*15 && kam>=b_koszary*15 && zel>=b_koszary*20)
                {
                    system("cls");
                    dre-=b_koszary*15;
                    kam-=b_koszary*15;
                    zel-=b_koszary*20;
                    b_koszary++;
                    cout << "   Koszary, poziom " << b_koszary;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            else if(wyb_wioska=='t' && b_koszary==0)
            {
                if(b_drwal>=2 && b_kopalnia>=2 && dre>=15 && kam>=15 && zel>=20)
                {
                    system("cls");
                    dre-=15;
                    kam-=15;
                    zel-=20;
                    b_koszary++;
                    cout << "   Koszary, poziom " << b_koszary;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow, lub niespelnione wymagania!";
                    Sleep(2000);
                }
            }

        } break;

    case 'g':
        {
            system("cls");
            surki_interfejs();

            cout << " # Jaskinia,     Poziom " << b_jaskinia << endl << endl;

            if(b_jaskinia==0)
            {
                cout << " # Potrzebujesz:   ";
                if(b_kopalnia<4)
                    cout << "Kopalnia poziom 4, ";

                cout << endl;
                cout << " # Surowce:        Kamien 10, Zelazo 10" << endl << endl;
            }

            if(b_jaskinia>0)
            {
                cout << " # Surowce:        Kamien " << b_jaskinia*10 << ", Zelazo " << b_jaskinia*10 << endl << endl;
            }
            cout << " # W razie porazki jaskinia pozwala zachowac surowce i twarz." << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska=='t' && b_jaskinia>0 && b_jaskinia<30)
            {
                if(kam>=b_jaskinia*10 && zel>=b_jaskinia*10)
                {
                    system("cls");
                    kam-=b_jaskinia*10;
                    zel-=b_jaskinia*10;
                    b_jaskinia++;
                    cout << "   Jaskinia, poziom " << b_jaskinia;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            else if(wyb_wioska=='t' && b_jaskinia==0)
            {
                if(b_kopalnia>=4 && kam>=10 && zel>=10)
                {
                    system("cls");
                    b_jaskinia++;
                    kam-=10;
                    zel-=10;
                    cout << "   Jaskinia, poziom " << b_jaskinia;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow, lub niespelnione wymagania!";
                    Sleep(2000);
                }
            }

        } break;

    case 'h':
        {
            system("cls");
            surki_interfejs();

            cout << " # Pola,           Poziom " << b_pola << endl << endl;

            if(b_pola==0)
            {
                cout << " # Potrzebujesz:   ";
                if(b_drwal<2)
                    cout << "Drwal poziom 2";

                cout << endl;
                cout << " # Surowce:        Drewno 10" << endl << endl;
            }

            if(b_pola>0)
            {
                cout << " # Surowce:        Drewno " << b_pola*10;
                if(b_pola>=5)
                    cout << ", Kamien " << b_pola*15 << ", Zelazo " << b_pola*5;
                cout << endl << endl;
            }
            cout << " # Pola to doskonale zrodlo warzyw. Znaczy.. jedyne zrodlo warzyw w Twojej wiosce." << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska=='t' && b_pola>=5 && b_pola<30)
            {
                if(dre>=b_pola*10 && kam>=b_pola*15 && zel>=b_pola*5)
                {
                    system("cls");
                    dre-=b_pola*10;
                    kam-=b_pola*15;
                    zel-=b_pola*5;
                    b_pola++;
                    cout << "   Pola, poziom " << b_pola;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska=='t' && b_pola>0 && b_pola<5)
            {
                if(dre>= b_pola*10)
                {
                    system("cls");
                    dre-=b_pola*10;
                    b_pola++;
                    cout << "   Pola, poziom " << b_pola;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska=='t' && b_pola==0)
            {
                if(b_drwal>=2 && dre>=10)
                {
                    system("cls");
                    b_pola++;
                    dre-=10;
                    cout << "   Pola, poziom " << b_pola;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow, lub niespelnione wymagania!";
                    Sleep(2000);
                }
            }

        } break;

    case 'i':
        {
            system("cls");
            surki_interfejs();

            cout << " # Uleczyciel,   Poziom " << b_uleczyciel << endl << endl;

            if(b_uleczyciel==0)
            {
                cout << " # Potrzebujesz:   ";
                if(b_chata<3)
                    cout << "Chata wodza poziom 3";

                cout << endl;
                cout << " # Surowce:        Drewno 30, Kamien 20, Zelazo 10" << endl << endl;
            }

            if(b_uleczyciel>0)
            {
                cout << " # Surowce:        Drewno " << b_uleczyciel*30 << ", Kamien " << b_uleczyciel*20 << ", Zelazo " << b_uleczyciel*10 << endl << endl;
            }
            cout << " # Ten budynek daje Ci miejsce dla rannych, aby mogli dojsc do siebie!" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska =='t' && b_uleczyciel>0 && b_uleczyciel<30)
            {
                if(dre>= b_uleczyciel*30 && kam>=b_uleczyciel*20 && zel>=b_uleczyciel*10)
                {
                    system("cls");
                    dre-=b_uleczyciel*30;
                    kam-=b_uleczyciel*20;
                    zel-=b_uleczyciel*10;
                    b_uleczyciel++;
                    cout << "   Uleczyciel, poziom " << b_uleczyciel;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska== 't' && b_uleczyciel==0)
            {
                if(b_chata>=3 && dre>=30 && kam>=20 && zel>=10)
                {
                    system("cls");
                    b_uleczyciel++;
                    dre-=30;
                    kam-=20;
                    zel-=10;
                    cout << "   Uleczyciel, poziom " << b_uleczyciel;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow, lub niespelnione wymagania!";
                    Sleep(2000);
                }
            }

        } break;

    case 'j':
        {
            system("cls");
            surki_interfejs();

            cout << " # Domy,        Poziom " << b_domy << endl << endl;

            cout << " # Surowce:        Drewno " << b_domy*5;
            if(b_domy>=5)
                cout << ", Kamien " << b_domy*10 << ", Zelazo " << b_domy*5;
            cout << endl << endl;

            cout << " # W domach mieszkaja ludzie, wiecej domow -> wiecej ludzi!" << endl << endl;

            cout << "  Czy chcesz wybudowac ten obiekt?  Tak(t)";
            wyb_wioska = getch();

            if(wyb_wioska=='t' && b_domy>=5 && b_domy<30)
            {
                if(dre>=b_domy*5 && kam>=b_domy*10 && zel>=b_domy*5)
                {
                    system("cls");
                    dre-=b_domy*5;
                    kam-=b_domy*10;
                    zel-=b_domy*5;
                    b_domy++;
                    lud+=5;
                    cout << "   Domy, poziom " << b_domy;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

            if(wyb_wioska=='t' && b_domy>0 && b_domy<5)
            {
                if(dre>= b_domy*5)
                {
                    system("cls");
                    dre-=b_domy*5;
                    b_domy++;
                    lud+=5;
                    cout << "   Domy, poziom " << b_domy;
                    Sleep(1000);
                }

                else
                {
                    system("cls");
                    cout << "   Za malo surowcow!";
                    Sleep(2000);
                }
            }

        } break;

    default:
        {
            chata = false;
        }
    }
}
}

void Wioska::wioska_drwal()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_drwal < 10)
    {
        cout << " # Barczysty mezczyzna zwinnie tnie drzewa... a nie to w sasiedniej wiosce!" << endl;
        cout << " # Ty masz dopiero " << b_drwal << " poziom!";
    }
    if(b_drwal >= 10 && b_drwal <= 29)
    {
        cout << " # Hej ho do pracy by sie szlo z tym " << b_drwal << " lvlem!" << endl;
        cout << " # Ale miesnie ma ten drwal!";
    }
    if(b_drwal == 30)
        cout << " # Prawdziwa druzyna A z siekierami. To sie nazywa " << b_drwal << " poziom!";

    cout << endl << endl;
    cout << " # Twoj przyrost DREwna na dzien to " << b_drwal*2 + p_siekiera*2;
    cout << endl << " # Twoj poziom siekiery to " << p_siekiera;

    if(p_siekiera<3)
    {
        cout << endl << endl;
        cout << "   a. Ulepsz siekiere       ";
        if(p_siekiera>0)
            cout << "DRE:" << p_siekiera*20 << " KAM:" << p_siekiera*20 << " ZEL:" << p_siekiera*20;
        else
            cout << "DRE:10 KAM:10 ZEL:10";
    }

    wyb_wioska = getch();
}

void Wioska::wioska_koszary()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_koszary < 10)
    {
        cout << " # Nie ma to jak koszary zrobione z chaty Twojej babuni..." << endl;
        cout << " # Ale przynajmniej pachnie pierogami i " << b_koszary << " lvlem!";
    }
    if(b_koszary >= 10 && b_koszary <= 29)
        cout << " # Caly rzad przygotowanych do boju facetow! Poziom " << b_koszary << " i jazda!";
    if(b_koszary == 30)
    {
        cout << " # To juz nie zabawa dla malych dziewczynek." << endl;
        cout << " # Prawdziwy osrodek " << b_koszary << " tylko dla twardzieli!";
    }

    cout << endl << endl;
    cout << " # Twoje koszary daja Ci " << b_koszary*2 << " ataku!";

    cout << endl << endl;
    cout << " # Twoja BROn: " << bro << endl;
    cout << " # Twoi WOJownicy: " << woj << endl;
    cout << " # Twoj ATK i OBR: " << atk << " / " << obr;

    cout << endl << endl;
    cout << "   a. Wykuj BROn            DRE:5 ZEL:3" << endl;
    cout << "   b. Tworz WOJownikow      ZEL:5 BRO:1 LUD:1";

    wyb_wioska = getch();
}

void Wioska::wioska_jaskinia()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_jaskinia < 10)
        cout << " # Poki co tylko skromna grota " << b_jaskinia << " poziomu, ale jaka pojemna";
    if(b_jaskinia >= 10 && b_jaskinia <= 29)
        cout << " # Coraz glebiej, coraz ciemniej, coraz wiecej miejsca na tym " << b_jaskinia << " poziomie";
    if(b_jaskinia == 30)
        cout << " # Dokopales sie do jadra ziemi... To juz 30 poziom!";

    cout << endl << endl;
    cout << " # Twoj towar jest bezpieczny w " << b_jaskinia*3 << " procentach" << endl << endl;

    cout << " # Jezeli Twoja wioska bedzie zagrozona czesc towaru bedzie bezpieczna" << endl;
    cout << " # Jaskinia to Twoja kryjowka na surowce, zawsze beda tu bezpieczne";

    wyb_wioska = getch();
}

void Wioska::wioska_pola()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_pola < 10)
        cout << " # Tu narazie jest sciernisko, ale bedzie San Francisco " << b_pola << " poziomu!";
    if(b_pola >= 10 && b_pola <= 29)
        cout << " # Grupa ludzi z motykami i kilka pol " << b_pola << " poziomu, ale z Ciebie biznesmen";
    if(b_pola == 30)
        cout << " # No i masz swoje San Francisco bo to juz 30 lvl!";

    cout << endl << endl;
    cout << " # Twoj przyrost WARZyw na dzien to: " << b_pola*3 + p_motyka*2;
    cout << endl << " # Twoj poziom motyki to: " << p_motyka;

    cout << endl << endl;
    cout << "   a. Wyszkol ROLnika          ZEL:5 BRO:1 LUD:1";
    if(p_motyka<3)
    {
        cout << endl << "   b. Ulepsz motyke          ";
        if(p_motyka>0)
            cout << "DRE:" << p_motyka*20 << " KAM:" << p_motyka*20 << " ZEL:" << p_motyka*20;
        else
            cout << "DRE:10 KAM:10 ZEL:10";
    }

    wyb_wioska = getch();
}

void Wioska::wioska_uleczyciel()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_uleczyciel <10)
    {
        cout << " # Starsza babcia powiedziala ze potrafi leczyc ludzi..." << endl;
        cout << " # Co moze pojsc nie tak na " << b_uleczyciel << " poziomie!";
    }
    if(b_uleczyciel >= 10 && b_uleczyciel <= 29)
        cout << " # Coraz mniej chorob w Twojej wiosce, to juz " << b_uleczyciel << " poziom!";
    if(b_uleczyciel == 30)
        cout << " # Prawdziwe Centrum Zdrowia Matki i Dzikiego... 30 poziom!";

    cout << endl << endl;
    cout << " # Twoja gwarancja bezpieczenstwa ludzi to: " << b_uleczyciel*3 << "%" << endl;
    cout << " # Ilosc osob ktora moze ulec \"wypadkowi\" to: " << 70-b_uleczyciel*2 << "%" << endl << endl;

    cout << " # Aktualnie w Twojej lecznicy lezy " << ranni << " rannych" << endl;
    cout << " # Czas leczenia jednego LUDzia to ";
    if(b_uleczyciel<7)
        cout << "5" << endl;
    else if(b_uleczyciel>6 && b_uleczyciel<13)
        cout << "4" << endl;
    else if(b_uleczyciel>12 && b_uleczyciel<19)
        cout << "3" << endl;
    else if(b_uleczyciel>18 && b_uleczyciel<25)
        cout << "2" << endl;
    else if(b_uleczyciel>24)
        cout << "1" << endl;
    cout << " # Aktualnie leczenie jest ";
    if(odl_ranni>0 && (lud+woj+rol)<b_domy*10)
        cout << "AKTYWNE, nastepny LUD za " << odl_ranni << " dni" << endl;
    else
        cout << "NIEAKTYWNE" << endl;
    if((lud+woj+rol)>=b_domy*10)
        cout << " # Masz za duzo ludzi! Twoja lecznica nie leczy poprawnie!" << endl;

    cout << endl;
    cout << "   a. Zmien aktywnosc leczenia ludzi";

    wyb_wioska = getch();
}

void Wioska::wioska_domy()
{
    system("cls");

    surki_interfejs();

    cout << endl;
    if(b_domy < 10)
        cout << " # Kilka chat " << b_domy << " poziomu i kilka wiesniakow, niezle!";
    if(b_domy >= 10 && b_domy <= 29)
        cout << " # Caly rzad chat " << b_domy << " poziomu wiesniakow do Twojej dyspozycji!";
    if(b_domy == 30)
        cout << " # Nie ma to jak hotel dla dzikich. 30 poziom chat ludnosci!";

    cout << endl << endl;
    cout << " # Twoja populacja to: " << lud + woj + rol << endl;
    cout << " # Twoja maskymalna populacja to: " << b_domy*10 << endl << endl;

    cout << "   a. Dodaj sobie czlowieka";

    wyb_wioska = getch();
}
