#include <iostream>

using namespace std;

class Wioska;
class Menu;

class Historie
{
protected:

    char wyb_historie;
    short historia;
    short odliczanie;
    bool czytanie;

    void wywolywacz();

public:

    friend void funkcja_wioska(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie);
    friend void menu_gry(Menu *wskaznik_menu, Wioska *wskaznik_wioska, Historie *wskaznik_historie);
    friend int main();

    Historie(char='a', short=0, short=0, bool=false);
};
