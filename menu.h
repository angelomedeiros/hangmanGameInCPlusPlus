#include <iostream>
#include <stdlib.h>
#include <string>

#include "clearScreen.h"
#include "play.h"

using namespace std;

void mainMenu() {
    int option = 0;
    int oneOrTwoPlayer;
    char backToGoMenu;

    while ( option < 1 || option > 3 ) {
        cout << "Welcome to the hangman game\n";
        cout << "\n1 - Play";
        cout << "\n2 - About";
        cout << "\n3 - Exit\n";
        cout << "\nChoice an option and press the key enter: ";
        cin >> option;

        clearScreen();

        switch ( option ) {
            case 1:
                cout << "Do you want to play alone or with someone?\n\n";
                cout << "1 - One player\n";
                cout << "2 - Two player\n\n";
                cout << "Choice an option: ";

                cin >> oneOrTwoPlayer;

                clearScreen();

                if ( play(oneOrTwoPlayer) ) {
                    mainMenu();
                }

                break;
            case 2:
                cout << "About the game: \n\n";

                cout << "=======================================\n";
                cout << "Game developed by Angelo Medeiros with\n";
                cout << "the help of the course of 'One day code'\n";
                cout << "=======================================\n";

                cout << "\nDo you want to go back to the menu (y/n)? ";
                cin >> backToGoMenu;
                clearScreen();

                if ( tolower(backToGoMenu) == 'y' ) {
                    mainMenu();
                } else {
                    cout << "See ya!\n";
                }


                break;
            case 3:
                cout << "See ya!\n";
                break;
        }
    }
}
