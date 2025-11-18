#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

int WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
int CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;
int YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;

using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

// Rycerz | Lucznik | Mag
string Klasa; string Imie;
int HP; int MaxHP;
int Mana; int MaxMana;
int DEX;
int lvl = 0; int exp = 0; int zdobyty_exp;
int Monety = 0; int Zdobyte_Monety;
string Nazwa_Broni; int Atak_Broni;
string Amulet_1;
string Quest; int Quest_Postep;
// HP | MaxHP | STR_min | STR_max
int Przeciwnik[4]; string Przeciwnik_Nazwa; string Ascii;
string wybor; int szansa = 0; int szansa_pulapki = 0;
string Lokacja = "Nowa_Gra";

int main() {
Menu:
    while (true) {
        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        cout << R"(|
|        /$$      /$$            /$$$$$$
|       | $$$    /$$$           /$$__  $$
|       | $$$$  /$$$$ /$$   /$$| $$  \__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$
|       | $$ $$/$$ $$| $$  | $$| $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$
|       | $$  $$$| $$| $$  | $$| $$|_  $$  /$$$$$$$| $$ \ $$ \ $$| $$$$$$$$
|       | $$\  $ | $$| $$  | $$| $$  \ $$ /$$__  $$| $$ | $$ | $$| $$_____/
|       | $$ \/  | $$|  $$$$$$$|  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$
|       |__/     |__/ \____  $$ \______/  \_______/|__/ |__/ |__/ \_______/
|                     /$$  | $$
|                    |  $$$$$$/
|                     \______/)" << "\n";

        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "|-------------------------------------\\_/---------------------------------------|\n";
        SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
        cout << "| Witaj w MyGame co chcesz zrobic?     |\n|                                      |\n";
        cout <<"|1 Nowa Gra                            |\n";
        cout <<"|2 Wczytaj Gre                         |\n";
        cout <<"|3 Wyjscie                             |\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "\\-------------------------------------/-\\---------------------------------------/\n";
        while (true) {
            SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
            cout << "Wpisz (1/2/3)\n";
            cin >> wybor;
            if (wybor=="1") {
                SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
                cout << "Zaczynanie Nowej Gry\n";
                goto Nowa_Gra;
            } else if (wybor=="2") {
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << "Wczytywanie Gry:\n";
                fstream plik("Zapis_Gry.txt"); // Miejsce MaxHP exp lvl Mana MaxMana DEX Nazwa_Broni Atak_Broni Imie Klasa Monety Quest Quest_Postep
                if (plik.is_open()) {
                    plik >> Lokacja >> HP >> MaxHP >> exp >> lvl >> Mana >> MaxMana >> DEX >> Nazwa_Broni >> Atak_Broni >> Imie >> Klasa >> Monety >> Quest >> Quest_Postep;
                    plik.close();
                } else {
                    cout << "Nie Mozna Otworzyc Zapis_Gry.txt Bez Tego Pliku Niekture Funkcje moga nie dzialac!!\n";
                }
                cout << "Wczytano Gre\n";
                srand(time(NULL));
                Sleep(1000);
                if (Lokacja == "Nowa_Gra") { goto Nowa_Gra; }
                else if (Lokacja == "Dom_Dziadka") { goto Dom_Dziadka; }
                else if (Lokacja == "Przy_Domie_Dziadka") { goto Przy_Domie_Dziadka; }
                else if (Lokacja == "Rozdzial_1") { goto Rozdzial_1; }
                else if (Lokacja == "Rozdzial_1") { goto Las; }
                else if (Lokacja == "Rozdzial_1") { goto Dziadek; }
                else if (Lokacja == "Rozdzial_1") { goto Wioska; }
                else { goto Nowa_Gra; }
                system("pause");
                return 0;
            } else if (wybor=="3") {
                SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                cout << "Gra Pomyslnie zamknieta\n";
                return 0;
            }
        }
        system("cls");
    }
Nowa_Gra:
    Lokacja = "Nowa_Gra";
    system("cls");
    SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
    cout << "|--------- Start Twojej Przygody ---------|\n\n";
    cout << "Po dlugim podruzowaniu w poszukiwaniu przygod spotykasz starego Dziadka:\n\n";
    SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
    Sleep(3000);
    cout << "/-------------------------------------------------------------------------------\\\n";
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    cout << R"(              _,-'|
           ,-'._  |
 .||,      |####\ |
\.`',/     \####| |
= ,. =      |###| |
/ || \    ,-'\#/,'`.
  ||     ,'   `,,. `.
  ,|____,' , ,;' \| |
 (3|\    _/|/'   _| |
  ||/,-''  | >-'' _,\\
  ||'      ==\ ,-'  ,'
  ||       |  V \ ,|
  ||       |    |` |
  ||       |    |   \
  ||       |    \    \
  ||       |     |    \
  ||       |      \_,-'
  ||       |___,,--")_\
  ||         |_|   ccc/
  ||        ccc/
  ||                   )" << endl;
    SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
    cout << "\\-------------------------------------------------------------------------------/\n";
    Sleep(2000);
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    cout << "Dziadek: Witaj mlody podrozniku czego szukasz?\n"; Sleep(3000);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "?: Podruzuje po swiecie i szukam przygod!\n"; Sleep(3000);
    cout << "?: W Mojej ostatniej Podrozy zgubilem swoja Bron\n"; Sleep(3000);
    cout << "?: Czy mialbys dla mnie bron ktora moge pozycyc?\n"; Sleep(3000);
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    cout << "Dziadek: Mysle ze mam cos dla ciebie w domu\n"; Sleep(3000);
    cout << "Dziadek: Ale najpierw powiedz mi jak sie Nazywasz\n"; Sleep(3000);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "                  (Wpisz Bez Spacji!!)\n";
    cout << "Jasne Nazywam sie: ";
    cin >> Imie;
    Sleep(2000);
    system("cls");
    while (true) {
        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        cout << R"(              _,-'|
           ,-'._  |
 .||,      |####\ |
\.`',/     \####| |
= ,. =      |###| |
/ || \    ,-'\#/,'`.
  ||     ,'   `,,. `.
  ,|____,' , ,;' \| |
 (3|\    _/|/'   _| |
  ||/,-''  | >-'' _,\\
  ||'      ==\ ,-'  ,'
  ||       |  V \ ,|
  ||       |    |` |
  ||       |    |   \
  ||       |    \    \
  ||       |     |    \
  ||       |      \_,-'
  ||       |___,,--")_\
  ||         |_|   ccc/
  ||        ccc/
  ||                   )" << endl;
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "\\-------------------------------------------------------------------------------/\n";
        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        cout << "Dziadek: Swietnie " << Imie << "\n"; Sleep(3000);
        cout << "Dziadek: Powiedz mi jeszcze kim wogule jestes\n\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Wybierz kim Jestes:\n\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "/-------------------------------------------------------------------------------\\\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "1: Rycerz         HP: 125 | DEX: 5\n";
        cout << "2: Lucznik        HP: 100 | DEX: 10\n";
        cout << "3: Mag            HP: 75  | DEX: 15 | Mana: 20 |\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "\\-------------------------------------------------------------------------------/\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "(1/2/3): ";
        cin >> wybor;
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << endl;
        if (wybor == "1") {
            cout << Imie << ": Jestem Rycerzem\n";
            MaxHP = 125; DEX = 5; MaxMana = 0; Klasa = "Rycerz";
            break;
        } else if (wybor == "2") {
            cout << Imie << ": Jestem Lucznikiem\n";
            MaxHP = 100; DEX = 10; MaxMana = 0; Klasa = "Lucznik";
            break;
        } else if (wybor == "3") {
            cout << Imie << ": Jestem Czarodziejem\n";
            MaxHP = 75; DEX = 15; MaxMana = 20; Klasa = "Mag";
            break;
        }
        system("cls");
    }
    HP = MaxHP; Mana = MaxMana;
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    Sleep(2000);
    cout << "Dziadek: W takim razie Wejdz do mojego Domu\n"; Sleep(2000);
    cout << "Dziadek: W skrzyni znajdziesz Bron za ktora bendziesz mi winien 5 zlotych Monet\n"; Sleep(3000);
    Monety -= 5;
    system("cls");
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Wchodzisz do domu Dziadka:\n";
    while (true) {
        system("cls");
        SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
        cout << R"(*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/______/_
*******************************************************************************)" << endl;
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "/-------------------------------------------------------------------------------\\\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Wpisz (E) aby Otworzyc Skrzynie\n";
        cin >> wybor;
        if (wybor == "E" || wybor == "e") {
            Sleep(1000);
            cout << "Znalazles w Skrzyni:\n"; Sleep(2000);
            SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
            cout << "(Zwykly) ";
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            if (Klasa == "Rycerz") {
                cout << "Drewniany Miecz  |  STR: 5\n";
                Nazwa_Broni = "Drewniany_Miecz"; Atak_Broni = 5;
                break;
            } else if (Klasa == "Lucznik") {
                cout << "Luk z Strzalami  |  STR: 4\n";
                Nazwa_Broni = "Luk_z_Strzalami"; Atak_Broni = 4;
                break;
            } else if (Klasa == "Mag") {
                cout << "Zaczarowany Patyk  |  STR: 3\n";
                Nazwa_Broni = "Zaczarowany_Patyk"; Atak_Broni = 3;
                break;
            }
        }
    }
    Sleep(4000);
Dom_Dziadka:
    Lokacja = "Dom_Dziadka";
    while (true) {
        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "/-------------------------------------------------------------------------------\\\n";
        cout << "1 Wyjdz z Domu Dziadka\n";
        cout << "2 Zapisz Gre\n";
        cout << "3 Wyjdz z Gry\n\n";
        cout << "Wpisz: (1/2/3)\n";
        cin >> wybor;
        cout << endl;
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        if (wybor == "1") {
            Sleep(1000);
            cout << "Wychodzisz z Domu Dziadka...\n";
            break;
        } else if (wybor == "2") {
            cout << "Zapisywanie Gry\n";
            fstream plik("Zapis_Gry.txt"); // Miejsce MaxHP exp lvl Mana MaxMana DEX Nazwa_Broni Atak_Broni Imie Klasa Monety Quest Quest_Postep
            if (plik.is_open()) {
                plik << Lokacja << "\n" << HP << "\n" << MaxHP << "\n" << exp << "\n" << lvl << "\n" << Mana << "\n" << MaxMana << "\n" << DEX << "\n" << Nazwa_Broni << "\n" 
                << Atak_Broni << "\n" << Imie << "\n" << Klasa << "\n" << Monety << "\n" << Quest << "\n" << Quest_Postep;
                plik.close();
            } else {
                cout << "Nie Mozna Otworzyc Zapis_Gry.txt Bez Tego Pliku Niekture Funkcje moga nie dzialac!!\n";
                system("pause");
            }
            cout << "Zapisano Gre\n";
            Sleep(2000);
        } else if (wybor == "3") {
            cout << "Wychodzenie z Gry\n";
            return 0;
        }
    }
Przy_Domie_Dziadka:
    Lokacja = "Przy_Domie_Dziadka";
    system("cls");
    SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
    cout << "Widzisz Goblina ktory atakuje dziadka! Szybko Pomusz Mu!!\n"; Sleep(3000);

    Przeciwnik[0] = 35; // HP
    Przeciwnik[1] = 35; // MaxHP
    Przeciwnik[2] = 1; Przeciwnik[3] = 3; // STR: min-max
    Przeciwnik_Nazwa = "Goblin (LV 1)";
    zdobyty_exp = 0; Zdobyte_Monety = 0;
    srand(time(NULL));
    while (Przeciwnik[0] > 0 && HP > 0) {
        system("cls");
        while (true) {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << Przeciwnik_Nazwa << ":  ATK: " << Przeciwnik[2] << "/" << Przeciwnik[3] << "  HP: " << Przeciwnik[0] << "/" << Przeciwnik[1] << "  [";
            for (int i = 0; i < 20; i++) {
                if (i < Przeciwnik[0]*20/Przeciwnik[1]) {
                    cout << "#";
                } else {
                    cout << "-";
                }
            }
            cout << "]\n";
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << R"(             ,      ,   
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \)" << endl;
            SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
            cout << "/----------------------------------------------------------------------------------------------\\\n\n";
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << Imie << " (LVL" << lvl << "):" << "  STR: " << Atak_Broni << "  HP: " << HP << "/" << MaxHP << " [";
            for (int i = 0; i < 20; i++) {
                if (i < HP*20/MaxHP) {
                    cout << "#";
                } else {
                    cout << "-";
                }
            }
            cout << "]" << "  DEX: " << DEX;
            if (Klasa == "Mag") {
                cout << "  MP:" << Mana;
            }
            cout << "  Zdobyty Exp: " << zdobyty_exp << " Zdobyte Monety: " << Zdobyte_Monety;
            SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
            cout << "\n\\----------------------------------------------------------------------------------------------/\n\n";
            cout << "Wybierz Atak:     Szansa:  STR:\n";
            cout << "1 Normalny Atak   (100%)   " << Atak_Broni-2 << "/" << Atak_Broni << "\n";
            cout << "2 Ryzykowny Atak  (40%)    " << Atak_Broni+2 << "/" << Atak_Broni+5 << "\n";
            if (Klasa == "Mag" && Mana >= 5) {
                cout << "3 Magiczny Atak:  (100%)   " << Atak_Broni+2 << "/" << Atak_Broni+5 << " Wymaga 5MP\n";
            }
            cin >> wybor;
            cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            if (wybor == "1") {
                int dmg = Atak_Broni - 2 + rand() % 3;
                cout << "Atakujesz "<< Przeciwnik_Nazwa << ": -" << dmg << "HP\n\n";
                Przeciwnik[0] -= dmg; zdobyty_exp += dmg;
            } else if (wybor == "2" || (wybor == "3" && (Klasa == "Mag" && Mana >= 5))) {
                szansa = rand() % 100 + 1;
                if (wybor == "3") {Mana -= 5; szansa = 0;}
                SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
                if (40 > szansa) {
                    int dmg = Atak_Broni+2 + rand() % 4;
                    cout << "Atakujesz "<< Przeciwnik_Nazwa << ": -" << dmg << "HP\n\n";
                    Przeciwnik[0] -= dmg; zdobyty_exp += dmg*2;
                } else {
                    cout << "Nie Udalo ci sie wykonac Ryzykownego Ataku!\n\n";
                }
            } else {
                break;
            }
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            int dmg = Przeciwnik[2] + rand() % (Przeciwnik[3] - Przeciwnik[2] + 1);
            szansa = rand() % 100 + 1;
            if (DEX > szansa) {
                dmg = 0;
                cout << "Obroniles Atak " << Przeciwnik_Nazwa << "!\n";
            } else {
                cout << Przeciwnik_Nazwa << " Atakuje Ciebie: -" << dmg << "HP\n";
                HP -= dmg;
            }
            szansa = rand() % 100 + 1;
            if (35 > szansa) {
                SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
                cout << "\nZdobyles 1 Monete!\n";
                Zdobyte_Monety++;
            }
            break;
        }
        Sleep(2000);
    }
    system("cls");
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    if (HP > 0) {
        Monety += Zdobyte_Monety;
        exp += zdobyty_exp; lvl += exp/100; exp = exp%100;
        cout << "Brawo Pokonales " << Przeciwnik_Nazwa;
        cout << "\nZdobyles exp: " << zdobyty_exp << " i Monety: " << Zdobyte_Monety << "\n";
        cout << Imie << " LV: " << lvl << " exp: " << exp << "/100 Monety: " << Monety;
    } else {
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        while (true) {
            system("cls");
            cout << "Niestety Przegrales z " << Przeciwnik_Nazwa;
            cout << "\nWpisz (1) aby sprubowac jeszcze raz lub (2) aby wyjsc z gry\n";
            cin >> wybor;
            if (wybor == "1") {HP = MaxHP; Mana = MaxMana; goto Dom_Dziadka;} else {return 0;}
        }
    }
    Sleep(7000); system("cls");
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    cout << R"(              _,-'|
           ,-'._  |
 .||,      |####\ |
\.`',/     \####| |
= ,. =      |###| |
/ || \    ,-'\#/,'`.
  ||     ,'   `,,. `.
  ,|____,' , ,;' \| |
 (3|\    _/|/'   _| |
  ||/,-''  | >-'' _,\\
  ||'      ==\ ,-'  ,'
  ||       |  V \ ,|
  ||       |    |` |
  ||       |    |   \
  ||       |    \    \
  ||       |     |    \
  ||       |      \_,-'
  ||       |___,,--")_\
  ||         |_|   ccc/
  ||        ccc/
  ||                   )" << endl;
    SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
    cout << "\\-------------------------------------------------------------------------------/\n";
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    cout << "Dziadek: Dziekuje ze mnie uratowales... Nie chce nawet myslec co by sie stalo, gdyby cie tu nie bylo\n"; Sleep(3000);
    cout << "Dziadek: Musze przyznac ze niezle sobie radzisz z walka\n"; Sleep(3000);
    cout << "Dziadek: Od kilku dni w lesie slychac jakies niepokojace odglosy Handlarze mowili o dziwnych stworach...\n"; Sleep(3000);
    cout << "Dziadek: Gdybys mogl sprawdzic co tam sie tam dzieje... uznalbym twoj dlug za splacony\n"; Sleep(3000);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << Imie << ": Nie ma sprawy zajme sie tym\n"; Sleep(3000);
    Quest = "Idz_Glemboko_w_Las"; Quest_Postep = 0;
    system("pause"); system("cls");
    SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
    cout << "----------- Odblokowywujesz Rozdzial 1 -----------\n Powodzenia!!\n"; Sleep(2000);
Rozdzial_1:
    Lokacja = "Rozdzial_1";
    while (true) {
        system("cls");
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "----------- Rozdzial 1 -----------\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << Imie << " (LVL " << lvl << ") exp: " << exp << "/100 | HP: " << HP << "/" << MaxHP << " | Mana: " << Mana << "/" << MaxMana;
        cout << "\nKlasa: " << Klasa << " | STR: " << Atak_Broni << " | Bron: " << Nazwa_Broni << " | DEX: " << DEX << " | Zlote Monety: " << Monety;
        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        cout << "\n\nQuesty:\n";
        cout << "1: " << Quest << " | Postep: " << Quest_Postep << "/100%\n";
        SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
        cout << "\nWybierz Akcje:\n";
        cout << "1 Wejdz Do Lasu\n";
        cout << "2 Wroc Do Dziadka\n";
        cout << "3 Idz Do Wioski\n";
        SetConsoleTextAttribute(hOut, WHITE);
        cout << "4 Zapisz Gre\n";
        cout << "5 Wyjdz z Gry\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cin >> wybor;
        if (wybor == "1") {goto Las; system("cls");}
        else if (wybor == "2") {goto Dziadek; system("cls");}
        else if (wybor == "3") {goto Wioska; system("cls");}
        else if (wybor == "4") {
            cout << "Zapisywanie Gry\n";
            fstream plik("Zapis_Gry.txt"); // Miejsce MaxHP exp lvl Mana MaxMana DEX Nazwa_Broni Atak_Broni Imie Klasa Monety Quest Quest_Postep
            if (plik.is_open()) {
                plik << Lokacja << "\n" << HP << "\n" << MaxHP << "\n" << exp << "\n" << lvl << "\n" << Mana << "\n" << MaxMana << "\n" << DEX << "\n" << Nazwa_Broni << "\n" 
                << Atak_Broni << "\n" << Imie << "\n" << Klasa << "\n" << Monety << "\n" << Quest << "\n" << Quest_Postep;
                plik.close();
            } else {
                cout << "Nie Mozna Otworzyc Zapis_Gry.txt Bez Tego Pliku Niekture Funkcje moga nie dzialac!!\n";
                system("pause");
            }
            cout << "Zapisano Gre\n";
            Sleep(2000);}
        else if (wybor == "5") {
            cout << "Wychodzenie z Gry\n";
            return 0;
        }
    }
Las:
    Lokacja = "Las";
    system("cls");
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    cout << "Idziesz Do Lasu...\n"; Sleep(3000);
    cout << "Drzewa staja sie coraz gestsze a swiatlo powoli zanika pod grubymi konarami.\n"; Sleep(4000);
    cout << "W powietrzu unosi sie wilgotny zapach mchu, a z oddali dochodzi odglos lamanych galezi...\n"; Sleep(4000);
    cout << "Po chwili zatrzymujesz sie na niewielkim wzniesieniu, aby zlapac oddech.\n"; Sleep(5000);
    Las_Skip:
    while (true) {
        SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
        system("cls");
        cout << "Wybierz, dokad chcesz sie udac:\n";
        cout << "1  W Glab lasu\n";
        cout << "2  W strone dymu unoszacego sie w oddali\n";
        cout << "3  Wzdluz waskiej sciezki\n";
        SetConsoleTextAttribute(hOut, WHITE);
        cout << "4  Wrocic\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cin >> wybor;
        cout << "\n";
        if (wybor == "1") {Sleep(2000); goto Las_Glemboko;}
        else if (wybor == "2") {Sleep(2000); goto Las_Dym;}
        else if (wybor == "3") {Sleep(2000); goto Las_Sciezka;}
        else if (wybor == "4") {cout << "Wracasz z Lasu\n"; Sleep(3000); goto Rozdzial_1;}
    }
    Las_Glemboko:
    Las_Dym:
        system("cls");
        szansa_pulapki = 40;
        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        cout << "Idziesz w strone dymu ktory unosi sie ponad drzewami\n"; Sleep(3000);
        cout << "Po chwili dostrzegasz maly stary dom ukryty miedzy pniami\n"; Sleep(3000);
        cout << "Drzwi sa uchylone a z srodka dobiega lekki odglos trzaskajacego ognia\n"; Sleep(5000);
        while (true) {
            system("cls");
            SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
            cout << "Wybierz Akcje:\n";
            cout << "1  Wejdz Do Domu\n";
            cout << "2  Wroc\n";
            cin >> wybor;
            if (wybor == "1") {
                system("cls");
                SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
                cout << "Wchodzisz Do Starego Domu...\n"; Sleep(3000);
                szansa = rand() % 100;
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                if (szansa_pulapki > szansa) {
                    szansa_pulapki -= 5;
                    cout << "Niestety w domu byla pulapka ktorej nie zauwazyles\n"; Sleep(3000);
                    szansa = rand() % 100;
                    if (50 > szansa && Monety >= 5) {
                        cout << "Tracisz 5 Zlotych Monet!!\n"; Sleep(3000);
                        Monety -= 5;
                        cout << "Twoje Monety: " << Monety << "\n";
                    } else {
                        cout << "Tracisz 15 HP!!!\n"; Sleep(3000);
                        HP -= 15;
                        cout << "Twoje HP: " << HP << "/" << MaxHP << "\n";
                        if (HP <= 0 && Amulet_1 != "Amulet_Odrodzenia") {cout << "\nNiestety Zginoles i nie masz Amuletu Odrodzenia - Umierasz\n"; Sleep(3000); return 0;}
                        else if (HP <= 0 && Amulet_1 == "Amulet_Odrodzenia") {cout << "\nZginoles ale masz Amulet Odrodzenia  Odrodzisz sie z Pelnym HP\n"; Sleep(3000); HP = MaxHP; Amulet_1 = ""; goto Rozdzial_1;}
                    }
                } else {
                    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                    szansa_pulapki += 10;
                    szansa = rand() % 100;
                    cout << "W domu nie bylo pulapki!\n"; Sleep(3000);
                    if (50 > szansa) {
                        cout << "Przy Kominku Lezy Upieczony Kurczak ktory uleczy ci 20 HP i 5 Many!\n"; Sleep(3000);
                        HP += 20; Mana += 5;
                        if (HP > MaxHP) {HP = MaxHP;}
                        if (Mana > MaxMana) {Mana = MaxMana;}
                        cout << "Twoje HP: " << HP << "/" << MaxHP << " Mana: " << Mana << "/" << MaxMana << "\n";
                    } else {
                        cout << "Na stole lezy sakiewka z 5 Zlotymi Monetami\n"; Sleep(3000);
                        Monety += 5;
                        cout << "Twoje Monety: " << Monety << "\n";
                    }
                }
                Sleep(4000);
            }
            else if (wybor == "2") {cout << "Wracasz sie\n"; Sleep(2000); goto Las_Skip;}
        }
    Las_Sciezka:
        system("cls");
        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        cout << "Idziesz wzdluz krentej sciezki...\n"; Sleep(3000);
        cout << "Slyszysz dziwne dzwienki dobiegajace z za drzew\n"; Sleep(3000);
        cout << "Czujesz ze ktos cie obserwuje...\n"; Sleep (4000);
        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        szansa = rand() % 100;
        zdobyty_exp = 0; Zdobyte_Monety = 0;
        if (60 > szansa) {
            Przeciwnik[0] = 25; // HP
            Przeciwnik[1] = 25; // MaxHP
            Przeciwnik[2] = 2; Przeciwnik[3] = 2; // STR: min-max
            Przeciwnik_Nazwa = "Wilk (LV 1)";
            Ascii = R"(     _                  _
    | '-.            .-' |
    | -. '..\\,.//,.' .- |
    |   \  \\\||///  /   |
   /|    )M\/%%%%/\/(  . |\
  (/\  MM\/%/\||/%\\/MM  /\)
  (//M   \%\\\%%//%//   M\\)
(// M________ /\ ________M \\)
 (// M\ \(',)|  |(',)/ /M \\) \\\\  
  (\\ M\.  /,\\//,\  ./M //)
    / MMmm( \\||// )mmMM \  \\
     // MMM\\\||///MMM \\ \\
      \//''\)/||\(/''\\/ \\
      mrf\\( \oo/ )\\\/\
           \'-..-'\/\\
              \\/ \\)";
            cout << "Nagle z krzakow wyskakuje Wilk!\n"; Sleep(1000);
            cout << "Rzuca sie na ciebie musisz walczyc! Na szczescie nie wyglada na bardzo silnego!\n"; Sleep(3000);
        } else {
            Przeciwnik[0] = 35; // HP
            Przeciwnik[1] = 35; // MaxHP
            Przeciwnik[2] = 1; Przeciwnik[3] = 3; // STR: min-max
            Przeciwnik_Nazwa = "Goblin (LV 1)";
            Ascii = R"(             ,      ,   
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \)";
            cout << "Slyszysz cichy chichotliwy smiech dochodzacy zza drzewa...\n"; Sleep(3000);
            cout << "Nagle goblin wyskakuje z ukrycia i proboje cie zaatakowac!\n"; Sleep(1000);
            cout << "Przygotuj sie do walki!\n"; Sleep(3000);
        }
        while (Przeciwnik[0] > 0 && HP > 0) {
            system("cls");
            srand(time(NULL));
            while (true) {
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << Przeciwnik_Nazwa << ":  ATK: " << Przeciwnik[2] << "/" << Przeciwnik[3] << "  HP: " << Przeciwnik[0] << "/" << Przeciwnik[1] << "  [";
                for (int i = 0; i < 20; i++) {
                    if (i < Przeciwnik[0]*20/Przeciwnik[1]) {
                        cout << "#";
                    } else {
                        cout << "-";
                    }
                }
                cout << "]\n";
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                cout << Ascii << endl;
                SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
                cout << "/----------------------------------------------------------------------------------------------\\\n\n";
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                cout << Imie << " (LVL" << lvl << "):" << "  STR: " << Atak_Broni << "  HP: " << HP << "/" << MaxHP << " [";
                for (int i = 0; i < 20; i++) {
                    if (i < HP*20/MaxHP) {
                        cout << "#";
                    } else {
                        cout << "-";
                    }
                }
                cout << "]" << "  DEX: " << DEX;
                if (Klasa == "Mag") {
                    cout << "  MP:" << Mana;
                }
                cout << "  Zdobyty Exp: " << zdobyty_exp << " Zdobyte Monety: " << Zdobyte_Monety;
                SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
                cout << "\n\\----------------------------------------------------------------------------------------------/\n\n";
                cout << "Wybierz Atak:     Szansa:  STR:\n";
                cout << "1 Normalny Atak   (100%)   " << Atak_Broni-2 << "/" << Atak_Broni << "\n";
                cout << "2 Ryzykowny Atak  (40%)    " << Atak_Broni+2 << "/" << Atak_Broni+5 << "\n";
                if (Klasa == "Mag" && Mana >= 5) {
                    cout << "3 Magiczny Atak:  (100%)   " << Atak_Broni+2 << "/" << Atak_Broni+5 << " Wymaga 5MP\n";
                }
                cin >> wybor;
                cout << endl;
                SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                if (wybor == "1") {
                    int dmg = Atak_Broni - 2 + rand() % 3;
                    cout << "Atakujesz "<< Przeciwnik_Nazwa << ": -" << dmg << "HP\n\n";
                    Przeciwnik[0] -= dmg; zdobyty_exp += dmg;
                } else if (wybor == "2" || (wybor == "3" && (Klasa == "Mag" && Mana >= 5))) {
                    szansa = rand() % 100 + 1;
                    if (wybor == "3") {Mana -= 5; szansa = 0;}
                    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
                    if (40 > szansa) {
                        int dmg = Atak_Broni+2 + rand() % 4;
                        cout << "Atakujesz "<< Przeciwnik_Nazwa << ": -" << dmg << "HP\n\n";
                        Przeciwnik[0] -= dmg; zdobyty_exp += dmg*2;
                    } else {
                        cout << "Nie Udalo ci sie wykonac Ryzykownego Ataku!\n\n";
                    }
                } else {
                    break;
                }
                SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
                int dmg = Przeciwnik[2] + rand() % (Przeciwnik[3] - Przeciwnik[2] + 1);
                szansa = rand() % 100 + 1;
                if (DEX > szansa) {
                    dmg = 0;
                    cout << "Obroniles Atak " << Przeciwnik_Nazwa << "!\n";
                } else {
                    cout << Przeciwnik_Nazwa << " Atakuje Ciebie: -" << dmg << "HP\n";
                    HP -= dmg;
                }
                szansa = rand() % 100 + 1;
                if (35 > szansa) {
                    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
                    cout << "\nZdobyles 1 Monete!\n";
                    Zdobyte_Monety++;
                }
                break;
            }
            Sleep(2000);
        }
        system("cls");
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        if (HP > 0) {
            Monety += Zdobyte_Monety;
            exp += zdobyty_exp; lvl += exp/100; exp = exp%100;
            cout << "Brawo Pokonales " << Przeciwnik_Nazwa;
            cout << "\nZdobyles exp: " << zdobyty_exp << " i Monety: " << Zdobyte_Monety << "\n";
            cout << Imie << " LV: " << lvl << " exp: " << exp << "/100 Monety: " << Monety;
            Sleep(5000);
            system("cls");
            cout << "Postanawiasz wrocic i odpoczanc po przeciwniku\n"; Sleep(2000);
            goto Las_Skip;
        } else {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            while (true) {
                system("cls");
                cout << "Niestety Przegrales z " << Przeciwnik_Nazwa;
                if (HP <= 0 && Amulet_1 != "Amulet_Odrodzenia") {cout << "\nNiestety nie masz Amuletu Odrodzenia - Umierasz\n"; Sleep(3000); return 0;}
                else if (HP <= 0 && Amulet_1 == "Amulet_Odrodzenia") {cout << "\nZginoles ale masz Amulet Odrodzenia - Odrodzisz sie z Pelnym HP\n"; Sleep(3000); HP = MaxHP; Amulet_1 = ""; goto Rozdzial_1;}
            }
        }
Dziadek:
    Lokacja = "Dziadek";
    cout << "Idziesz Do Domu Dziadka\n";
Wioska:
    Lokacja = "Wioska";
    cout << "Idziesz Do Wioski\n";
    return 0;
}