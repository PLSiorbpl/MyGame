#include <iostream>
#include <Windows.h> // system()
#include <string>
#include <conio.h> // _getch() _kbhit() (GetChar) (KeyboardHit)
#include <stdlib.h>

// Można by użyć Makr (#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
int WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
int CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;
int YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;

//using namespace std; // nie lubie tego wole std:: poprostu

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

int Menu() {
    int Pozycja = 0;
    std::string enter;
    while (true) {
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        std::cout << "/-------------------------------------------------------------------------------\\\n";

        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        std::cout << R"(|
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
        std::cout << "|-------------------------------------\\_/---------------------------------------|\n";

        SetConsoleTextAttribute(hOut, WHITE | FOREGROUND_INTENSITY);
        std::cout << "| Witaj w MyGame co chcesz zrobic?     |\n|                                      |\n";

        // Można użyć std::cout << "| Nowa Gra " << ((Pozycja == 0) ? "   <-                       |" : "                            |") << "\n";
        // ale nie wiem czy można tak (jest to skrucony if (?) else (:))
        if (Pozycja == 0) {std::cout <<"| Nowa Gra    "<<"   <--                   |\n";}
        else {std::cout <<"| Nowa Gra    "<<"                         |\n";}
        if (Pozycja == 1) {std::cout <<"| Wczytaj Gre "<<"   <--                   |\n";}
        else {std::cout <<"| Wczytaj Gre "<<"                         |\n";}
        if (Pozycja == 2) {std::cout <<"| Wyjscie     "<<"   <--                   |\n";}
        else {std::cout <<"| Wyjscie     "<<"                         |\n";}

        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        std::cout << "\\-------------------------------------/-\\---------------------------------------/\n";

        // Klawiatura
        while (true) {
            SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
            std::cout << "Wpisz (0/1/2/enter)\n";
            std::cin >> enter;
            if (enter=="enter") {
                return Pozycja;
            } else if (enter=="0") {
                Pozycja = 0;
                break;
            } else if (enter=="1") {
                Pozycja = 1;
                break;
            } else if (enter=="2") {
                Pozycja = 2;
                break;
            } else {
                break;
            }
        //    if (_kbhit()) { // jak tego nie mozna to zrobie poprostu cin ale wtedy to -1000000 chinskich social credit
        //        char key = _getch();
        //        if (key == 'w' && Pozycja > 0) {
        //            Pozycja -= 1;
        //            break;
        //        } else if (key == 's' && Pozycja < 2) {
        //            Pozycja += 1;
        //            break;
        //        } else if (key == 13) { // 13 = enter
        //            return Pozycja;
        //        }
        //  }
        }

        // czyszczenie ekranu
        system("cls");
    }
}

int main() {
    int start = Menu();
    if (start == 2) { // Wyjscie
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cout << "Gra Pomyslnie zamknieta\n";
        system("pause");
        return 0;
    } else if (start == 0) { // Nowa Gra
        SetConsoleTextAttribute(hOut, YELLOW | FOREGROUND_INTENSITY);
        std::cout << "Nowa Gra WIP\n";
        system("pause");
        return 0;
    } else if (start == 1) { // Wczytaj gre i zacznij
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        std::cout << "Wczytywanie WIP\n";
        system("pause");
        return 0;
    }
}