#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <stdlib.h>
#define WHITE FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
#define GRAY !FOREGROUND_RED | !FOREGROUND_GREEN | !FOREGROUND_BLUE
#define YELLOW FOREGROUND_RED | FOREGROUND_GREEN
#define CYAN FOREGROUND_GREEN | FOREGROUND_BLUE

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

int Start() {
    int Pozycja = 0;
    while (true) {
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        std::cout << "/-------------------------------------------------------------------------------\\\n";
        SetConsoleTextAttribute(hOut, YELLOW);
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
        SetConsoleTextAttribute(hOut, ((Pozycja == 0) ? WHITE : GRAY));
        std::cout << "| Nowa Gra " << ((Pozycja == 0) ? "   <-                       |" : "                            |") << "\n";
        SetConsoleTextAttribute(hOut, ((Pozycja == 1) ? WHITE : GRAY));
        std::cout << "| Kontynouj" << ((Pozycja == 1) ? "   <-                       |" : "                            |") << "\n";
        SetConsoleTextAttribute(hOut, ((Pozycja == 2) ? WHITE : GRAY));
        std::cout << "| Wyjscie  " << ((Pozycja == 2) ? "   <-                       |" : "                            |") << "\n";
        SetConsoleTextAttribute(hOut, CYAN | FOREGROUND_INTENSITY);
        std::cout << "\\-------------------------------------/-\\---------------------------------------/\n";

        while (true) {
            if (_kbhit()) {
                char key = _getch();
                if (key == 'w' && Pozycja > 0) {
                    Pozycja -= 1;
                    break;
                } else if (key == 's' && Pozycja < 2) {
                    Pozycja += 1;
                    break;
                } else if (key == 13) { // 13 = enter
                    return Pozycja;
                }
            }
        }

        system("cls"); // czyszczenie ekranu
    }
}

int main() {
    int start = Start();
    if (start == 2) {
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
        std::cout << "Gra Pomyslnie zamknieta\n";
        return 0; // wyjście
    } else if (start == 0) {
        // Nowa Gra
    }
}