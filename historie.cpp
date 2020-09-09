#include <iostream>
#include <conio.h>
#include <windows.h>
#include "historie.h"

using namespace std;

Historie::Historie(char wyb_h, short hist, short odli, bool czyt)
{
    wyb_historie = wyb_h;
    historia = hist;
    odliczanie = odli;
    czytanie = czyt;
}

void Historie::wywolywacz()
{
        cout << endl;

        switch(historia)
        {
            case 1:{        // ZO_choroba1
                if(odliczanie==6)
                    {
                        cout << "   # Twoi ludzie zaczynaja kaszlec krwia, nie wyglada to dobrze!" << endl;
                        cout << "   # Moze lekarz moglby pomoc...";
                        czytanie = true;
                    }
                else if(odliczanie==5)
                {
                    cout << "   # Paskudna zaraza spadla na Twoich ludzi!" << endl;
                    cout << "   # Kaszel krwi jest norma w Twoim spoleczenstwie!" << endl;
                    cout << "   # W Twojej wiosce panuje zaraza, ktora dziesiatkuje Twoich poddanych," << endl;
                    cout << "   # Chyba ze lekarz mial akurat wolny dzien!";
                    czytanie = true;
                }
            } break;

            case 2:{        // ZM_wilki
                if(odliczanie==6)
                {
                    cout << "   # W powietrzu unosi sie smrod psow, a zza muru slychac wycie." << endl;
                    cout << "   # Lepiej to sprawdzic!";
                    czytanie = true;
                }
                if(odliczanie==5)
                {
                    cout << "   # Gdy tylko wyszedles ze swojej chaty zauwazyles jak cichostapajace wilki przechodza przez palisade!" << endl;
                    cout << "   # Od razu krzyknales mobilizujac swoich ludzi do obrony wioski." << endl;
                    cout << "   # Wilki ustawily sie w pozycji bojowej przyjmujac formacje trojkata jakby mialy przetoczyc sie przez wioske!" << endl;
                    cout << "   # Dzieci zaczely plakac, kobiety chowaly sie w swoich domach, a zdolni do walki staneli w obronie swoich rodzin" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==4)
                {
                    cout << "   # Kobiety posprzataly truchla wilkow, a na placu znow jest pusto" << endl;
                    cout << "   # Widac tylko plamy krwii po wilkach" << endl;
                    cout << "   # I po ludziach...";
                    czytanie = true;
                }
            } break;

            case 3:{        // ZM_umarlacy
                if(odliczanie==6)
                {
                        cout << "   # W powietrzu wisi ciezki zapach smierci i rozkladajacego sie ciala!" << endl;
                        cout << "   # Ale przeciez to juz wiele dni minelo od ostatniej bitwy..." << endl;
                        cout << "   # Cos tu jest nie tak...";
                        czytanie = true;
                }
                if(odliczanie==5)
                {
                    cout << "   # Kolejny dzien zaczal sie zwyczajnie," << endl;
                    cout << "   # Kawka, ciasteczko... Nie no nie te czasy." << endl;
                    cout << "   # To OZYWIENCY U TWOICH BRAM! Przebijaja sie!" << endl;
                    cout << "   # Czas stawic im czola!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==4)
                {
                    cout << "   # Martwi leza na dziedzincu" << endl;
                    cout << "   # Czy to Twoi ludzie czy moze zombie?" << endl;
                    cout << "   # Zreszta co za roznica";
                    czytanie = true;
                }
            } break;

            case 4:{        // ZO_choroba2
                if(odliczanie==7)
                {
                        cout << "   # Choroba przyszla jak zlodziej w nocy!" << endl;
                        cout << "   # Twoi ludzie zaczeli sie zle czuc i mdlec." << endl;
                        cout << "   # To nie wyglada dobrze, oby lekarz pomogl!" << endl << endl;

                        cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                        wyb_historie = getch();
                        czytanie = true;
                }
                if(odliczanie==6)
                {
                    cout << "   # Twoi ludzie zaczeli czuc sie lepiej." << endl;
                    cout << "   # To pewnie te pierozki babuni..." << endl;
                    cout << "   # Gdyby nie byly gotowane w koszarach...";
                    czytanie = true;
                }
            } break;

            case 5:{        // ZM_smuga
                if(odliczanie==8)
                {
                        cout << "   # Na niebie krwawa smuga jest coraz blizej Twojej wioski" << endl;
                        cout << "   # W powietrzu wisi atmosfera strachu, Twoi ludzie nie chca wychodzic na dwor." << endl;
                        cout << "   # Moze z muru mozna wiecej zobaczyc";
                        czytanie = true;
                }
                if(odliczanie==7)
                {
                    cout << "   # Rano budzi Cie przerazliwy krzyk" << endl;
                    cout << "   # Wybiegasz z chaty i widzisz czerwona postac, jakby ducha" << endl;
                    cout << "   # Stoi z wielkim toporem i czeka na Twoich ludzi" << endl;
                    cout << "   # Bitwa zaczela sie!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==6)
                {
                    cout << "   # Strach nadal towarzyszy ludziom w Twojej wiosce." << endl;
                    cout << "   # Co chcial ten czerwony wedrowiec?!";
                    czytanie = true;
                }
            } break;

            case 6:{        // ZM_gwiazda
                if(odliczanie==6)
                {
                    cout << "   # Czerwona gwiazda nad Twoja glowa swieci coraz jasniej!" << endl;
                    cout << "   # Cos sie niedlugo wydarzy!";
                    czytanie = true;
                }
                if(odliczanie==5)
                {
                    cout << "   # Przed Twoja wioska stoi czerwona armia!" << endl;
                    cout << "   # Ma na sobie czerwone zbroje z czerwonego zelaza i piki" << endl;
                    cout << "   # Krzycza cos o matce smokow, krolu uzurpatorze i... " << endl;
                    cout << "   # O tym ze zapomnieli wylaczyc zelazka wiec biegna spowrotem do obozu." << endl;
                    cout << "   # Jednakze kilku z nich chce walczyc!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==4)
                {
                    cout << "   # Nazajutrz widzisz unoszacy sie dym za pagorkiem." << endl;
                    cout << "   # Chyba serio zapomnieli o tym zelazku...";
                    czytanie = true;
                }
            } break;

            case 7:{        // ZO_mrozy
                if(odliczanie==5)
                {
                    cout << "   # W nocy nadeszly koszmarne mrozy, ktore oslabily Twoich ziomkow" << endl;
                    cout << "   # Nikt nie ucierpial jednakze ludzie musieli sie czyms ogrzac";
                    czytanie = true;
                }
                if(odliczanie==4)
                {
                    cout << "   # Twoja wioska dochodzi do normy, jest coraz lepiej" << endl;
                    cout << "   # Oby taki mroz juz nigdy nie nastal!";
                    czytanie = true;
                }
            } break;

            case 8:{        // ZM_ufo
                if(odliczanie==8)
                {
                    cout << "   # Nad Twoja wioska widac dziwne cienie w chmurach!" << endl;
                    cout << "   # Tak, cienie w chmurach, bedzie grubo.";
                    czytanie = true;
                }
                else if(odliczanie==7)
                {
                    cout << "   # Czy to... spodek latajacy? Tak, ze statku kosmicznego wychodza obcy." << endl;
                    cout << "   # Szykuja sie do walki z Toba! Gotuj bron!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                else if(odliczanie==6)
                {
                    cout << "   # Kurz opadl, statek odlecial w nieokreslony sposob... albo to byl tylko sen?";
                    czytanie = true;
                }
            } break;

            case 9:{        // ZO_swieto
                if(odliczanie==5)
                {
                    cout << "   # Nazajutrz w Twojej wiosce maja odbywac sie zaslubiny!" << endl;
                    cout << "   # Drwalowie i gornicy nie beda pracowac!";
                    czytanie = true;
                }
                else if(odliczanie==4)
                {
                    cout << "   # Zabawa byla przednia, jednak drewno, kamien i zelazo nie zwiekszylo sie!";
                    czytanie = true;
                }
            } break;

            case 10:{       // ZO_manna
                if(odliczanie==4)
                {
                    cout << "   # Na Twoja wioske spadla manna z nieba!" << endl;
                    cout << "   # Kazdy mieszkaniec dostaje WARZ:2 i MIE:2!";
                    czytanie = true;
                }
            } break;

            case 11:{       // ZM_rosliny_atakuja
                if(odliczanie==6)
                {
                    cout << "   # Czy te trawy za murem nie byly mniejsze?" << endl;
                    cout << "   # Wczoraj jeszcze nie dochodzi³y do kolan, a co dopiero dzisiaj... ponad glowe!";
                    czytanie = true;
                }
                if(odliczanie==5)
                {
                    cout << "   # Uslyszales pukanie do bram... Znow Twoj straznik zasnal..." << endl;
                    cout << "   # Musisz samemu sprawdzic o co chodzi." << endl;
                    cout << "   # - Czego?! - zapytales spokojnie. Nie bylo odpowiedzi..." << endl;
                    cout << "   # Otworzyles a tam gigantyczne rosliny rodem z Mario gotowe do walki! DO BRONI!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==4)
                {
                    cout << "   # Trawa znow rosnie spokojnie i blogo, bez wielkich paszcz.";
                    czytanie = true;
                }
            } break;

            case 12:{       // ZM_pijany_stroz
                if(odliczanie==6)
                {
                    cout << "   # *hicks* Twoj straznik chodzi pijany *hicks*" << endl;
                    cout << "   # Nie powinienes go zwolnic? A trudno zrobie to jutro..." << endl;
                    cout << "   # *hicks*";
                    czytanie = true;
                }
                if(odliczanie==5)
                {
                    cout << "   # Kolejny dzien... Ptaki spiewaja, sloneczko swieci, traba wojenna brzmi..." << endl;
                    cout << "   # Zaraz co?! Twoj pijany straznik zapomnial nas o czyms poinformowac?" << endl;
                    cout << "   # Chyba tak... O ARMII POLNOCY CHCACA CIE PODBIC!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==4)
                {
                    cout << "   # Wioska odbita, przynajmniej tyle. Zaraz, mialem zwolnic tego typa..." << endl;
                    cout << "   # Aaaa, jutro to zrobie...";
                    czytanie = true;
                }
            } break;

            case 13:{       // ZM_staruszek_za_murem
                if(odliczanie==4)
                {
                    cout << "   # Przed Twoim murem stoja rycerze w zelaznych zbrojach!" << endl;
                    cout << "   # Jeden z nich ma otwarta przylbice i jest... staruszkiem!" << endl;
                    cout << "   # - NAUCZYMY TE BACHORY CO TO WALKA - krzyczy! DO WALKI!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==3)
                {
                    cout << "   # Co mozna powiedziec... The future is now, old man!";
                    czytanie = true;
                }
            } break;

            case 14:{       // ZO_plaga
                if(odliczanie==6)
                {
                    cout << "   # W Twojej wiosce zauwazyles wieksza niz zwykle ilosc robakow." << endl;
                    cout << "   # Albo to z warzywniaka, albo cos zlego sie zbliza...";
                    czytanie = true;
                }
                else if(odliczanie==5)
                {
                    cout << "   # Nadeszla plaga niszczaca zbiory!" << endl;
                    cout << "   # Dzis nie dostaniesz warzyw, a zapas twojego miesa zmalal!";
                    czytanie = true;
                }
            } break;

            case 15:{       // ZO_bunt
                if(odliczanie==7)
                {
                    cout << "   # W Twojej wiosce pojawil sie kaplan, ktory zaczal nawracac Twoich ludzi." << endl;
                    cout << "   # Ludzie zwrocili sie do Ciebie z prosba o usuniecie go." << endl;
                    cout << "   # Nie miales jednak na to czasu i czesc Twoich ludzi zbuntowala sie przeciw Tobie!" << endl << endl;

                    cout << "   # Nacisnij cokolwiek, aby kontynuowac...";
                    wyb_historie = getch();
                    czytanie = true;
                }
                if(odliczanie==6)
                {
                    cout << "   # Nastroje w wiosce uspokoily sie, kaplan uciekl w poplochu" << endl;
                    cout << "   # Tylko ludzi szkoda...";
                    czytanie = true;
                }
            } break;
        }
}
