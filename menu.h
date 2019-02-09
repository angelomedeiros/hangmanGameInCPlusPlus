#include <iostream>
#include <stdlib.h>
#include <string>

#include "clearScreen.h"
#include "onePlayer.h"

using namespace std;

void mainMenu() {
    int option = 0;

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
                cout << "The game started!\n\n";
                if ( onePlayer() ) {
                    mainMenu();
                }
                break;
            case 2:
                cout << "About the game: \n\n";
                break;
            case 3:
                cout << "See ya!\n\n";
                break;
        }
    }
}
