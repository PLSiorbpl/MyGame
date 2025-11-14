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

// Klasa 1-Rycerz 2-Łucznik 3-Mag
int Klasa;
int HP; int MaxHP;
int exp = 0; int zdobyty_exp;
int lvl = 0;
int Mana; int MaxMana;
int DEX;
string Nazwa_Broni;
int Atak_Broni;
string Imie;
string wybor;
int Przeciwnik[2];
int Lokacja = 0;

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
                fstream plik("Zapis_Gry.txt"); // Miejsce MaxHP exp lvl Mana MaxMana DEX Nazwa_Broni Atak_Broni Imie Klasa
                if (plik.is_open()) {
                    plik >> Lokacja >> HP >> MaxHP >> exp >> lvl >> Mana >> MaxMana >> DEX >> Nazwa_Broni >> Atak_Broni >> Imie >> Klasa;
                    plik.close();
                } else {
                    cout << "Nie Mozna Otworzyc Zapis_Gry.txt Bez Tego Pliku Niekture Funkcje moga nie dzialac!!\n";
                }
                cout << "Wczytano Gre\n";
                Sleep(1000);
                switch (Lokacja) {
                case 0:
                    goto Nowa_Gra;
                case 1:
                    goto Dom_Dziadka;
                case 2:
                    goto Przy_Domie_Dziadka;
                default:
                    goto Nowa_Gra;
                }
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
    Lokacja = 0;
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
    cout << "Dziadek: Witaj mlody podrozniku czego szukasz?\n";
    Sleep(3000);
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "?: Podruzuje po swiecie i szukam przygod!\n";
    Sleep(3000);
    cout << "?: W Mojej ostatniej Podrozy zgubilem swoja Bron\n";
    Sleep(3000);
    cout << "?: Czy mialbys dla mnie bron ktora moge pozycyc?\n";
    Sleep(3000);
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    cout << "Dziadek: Mysle ze mam cos dla ciebie w domu\n";
    Sleep(3000);
    cout << "Dziadek: Ale najpierw powiedz mi jak sie Nazywasz\n";
    Sleep(3000);
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
        cout << "Dziadek: Swietnie " << Imie << "\n";
        Sleep(3000);
        cout << "Dziadek: Powiedz mi jeszcze kim wogule jestes\n\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Wybierz kim Jestes:\n\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "/-------------------------------------------------------------------------------\\\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "1: Rycerz         HP: 125 | DEX: 5\n";
        cout << "2: Lucznik        HP: 100 | DEX: 10\n";
        cout << "3: Czarodziej     HP: 75  | DEX: 15 | Mana: 20 |\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        cout << "\\-------------------------------------------------------------------------------/\n";
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << "(1/2/3): ";
        cin >> Klasa;
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << endl;
        if (Klasa == 1) {
            cout << Imie << ": Jestem Rycerzem\n";
            MaxHP = 125; DEX = 5; MaxMana = 0;
            break;
        } else if (Klasa == 2) {
            cout << Imie << ": Jestem Lucznikiem\n";
            MaxHP = 100; DEX = 10; MaxMana = 0;
            break;
        } else if (Klasa == 3) {
            cout << Imie << ": Jestem Czarodziejem\n";
            MaxHP = 75; DEX = 15; MaxMana = 20;
            break;
        }
        system("cls");
    }
    HP = MaxHP; Mana = MaxMana;
    SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
    Sleep(2000);
    cout << "Dziadek: W takim razie Wejdz do mojego Domu\n";
    cout << "Dziadek: W skrzyni znajdziesz Bron za ktora bendziesz mi winien 5 zlotych Monet\n";
    Sleep(3000);
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
            cout << "Znalazles w Skrzyni:\n";
            Sleep(2000);
            SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
            cout << "(Zwykly) ";
            SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            if (Klasa == 1) {
                cout << "Drewniany Miecz  |  STR: 5\n";
                Nazwa_Broni = "Drewniany_Miecz"; Atak_Broni = 5;
                break;
            } else if (Klasa == 2) {
                cout << "Luk z Strzalami  |  STR: 4\n";
                Nazwa_Broni = "Luk_z_Strzalami"; Atak_Broni = 4;
                break;
            } else if (Klasa == 3) {
                cout << "Zaczarowany Patyk  |  STR: 3\n";
                Nazwa_Broni = "Zaczarowany_Patyk"; Atak_Broni = 3;
                break;
            }
        }
    }
    Sleep(4000);
Dom_Dziadka:
    Lokacja = 1;
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
            fstream plik("Zapis_Gry.txt"); // Miejsce MaxHP exp lvl Mana MaxMana DEX Nazwa_Broni Atak_Broni Imie Klasa
            if (plik.is_open()) {
                plik << Lokacja << "\n" << HP << "\n" << MaxHP << "\n" << exp << "\n" << lvl << "\n" << Mana << "\n" << MaxMana << "\n" << DEX << "\n" << Nazwa_Broni << "\n" << Atak_Broni << "\n" << Imie << "\n" << Klasa;
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
    Lokacja = 2;
    system("cls");
    SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
    cout << "Widzisz Goblina ktory atakuje dziadka! Szybko Pomusz Mu!!\n";
    Sleep(3000);

    Przeciwnik[0] = 50; // HP
    Przeciwnik[1] = 5;  // DMG
    zdobyty_exp = 0;
    srand(time(NULL));
    while (Przeciwnik[0] > 0 && HP > 0) {
        system("cls");
        while (true) {
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "Goblin (LV1):  ATK: " << Przeciwnik[1]-2 << "/" << Przeciwnik[1] << "  HP: " << Przeciwnik[0] << "/50  [";
            for (int i = 0; i < 20; i++) {
                if (i < Przeciwnik[0]*20/50) {
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
            cout << "/-------------------------------------------------------------------------------\\\n\n";
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
            if (Klasa == 3) {
                cout << "  MP:" << Mana;
            }
            SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
            int szansa = rand() % 100 + 1;
            cout << "\n/-------------------------------------------------------------------------------\\\n\n";
            cout << "Wybierz Atak:     Szansa:  STR:\n";
            cout << "1 Normalny Atak   (100%)   " << Atak_Broni-2 << "/" << Atak_Broni << "\n";
            cout << "2 Ryzykowny Atak  (40%)    " << Atak_Broni+2 << "/" << Atak_Broni+5 << "\n";
            if (Klasa == 3 && Mana >= 5) {cout << "3 Magiczny Atak:  (100%)   " << Atak_Broni+2 << "/" << Atak_Broni+5 << " Wymaga 5MP\n";
                szansa = 0;
            }
            cin >> wybor;
            cout << endl;
            SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            if (wybor == "1") {
                int dmg = (Atak_Broni - 2) + rand() % 3;
                cout << "Atakujesz Goblina: -" << dmg << "HP\n\n";
                Przeciwnik[0] -= dmg; zdobyty_exp += dmg;
            } else if (wybor == "2" || (wybor == "3" && (Klasa == 3 && Mana >= 5))) {
                if (wybor == "3") {Mana -= 5;}
                SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
                if (40 > szansa) {
                    int dmg = Atak_Broni+2 + rand() % 4;
                    cout << "Atakujesz Goblina: -" << dmg << "HP\n\n";
                    Przeciwnik[0] -= dmg; zdobyty_exp += dmg*2;
                } else {
                    cout << "Nie Udalo ci sie wykonac Ryzykownego Ataku!\n\n";
                }
            } else {
                break;
            }
            SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            int dmg = Przeciwnik[1] - 2 + rand() % 3;
            szansa = rand() % 100 + 1;
            if (DEX > szansa) {
                dmg = 0;
                cout << "Obroniles Atak Goblina!\n";
            } else {
                cout << "Goblin Atakuje Ciebie: -" << dmg << "HP\n";
                HP -= dmg;
            }
            break;
        }
        Sleep(2000);
    }
    system("cls");
    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    if (HP > 0) {
        exp += zdobyty_exp; lvl += exp/100; exp = exp%100;
        cout << "Brawo Pokonałes Goblina (LV1)\n";
        cout << "Zdobyles exp: " << zdobyty_exp << "\n";
        cout << Imie << " LV: " << lvl << " exp: " << exp << "/100\n";
    } else {
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
        while (true) {
            system("cls");
            cout << "Niestety Przegrales z Goblin (LV1)\n";
            cout << "Wpisz (1) aby sprubowac jeszcze raz lub (2) aby wyjsc z gry\n";
            cin >> wybor;
            if (wybor == "1") {HP = MaxHP; Mana = MaxMana; goto Dom_Dziadka;} else {return 0;}
        }
    }
    system("pause");
    return 0;
}