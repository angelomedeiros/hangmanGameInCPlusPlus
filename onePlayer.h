#include <string>
#include <iostream>

#define SIZE 5

using namespace std;

string returnRandomWord() {

    string words[SIZE] = { "Apple", "Strawberry", "Pear", "Watermelon", "Pineapple" };

    int randomIndex = rand() % SIZE;

    return words[randomIndex];

}

string createMask(int sizeWord) {

    string wordWithMask;

    for ( int count = 0; count < sizeWord; count++ ) {
        wordWithMask += "_";
    }

    return wordWithMask;

}

void showStatus(string mask, int remainingAttempts, string attemptLetters, string message) {

    cout << message << "\n";

    cout << "Word: " << mask << "\n\n";

    cout << "Remaining attempts: " << remainingAttempts  << "\n";

    cout << "Attempt letters: ";

    for ( int count = 0; count < attemptLetters.size() ; count++ ) {

        cout << attemptLetters[count];

        if ( count < attemptLetters.size() - 1 ) {
            cout << ", ";
        } else {
            cout << "\n";
        }

    }

}

bool onePlayer() {

    string word = returnRandomWord();

    int sizeWord = word.size();

    int attempts = 0, maxAttempts = 5;

    char letter;

    char restart = true;

    string mask = createMask(sizeWord),
           attemptLetters = "",
           message = "Welcome to the game! Good luck :)\n";

    while ( word != mask && maxAttempts - attempts > 0 ) {

        bool letterWasTried = false, letterWasMatch = false;

        clearScreen();

        showStatus(mask, maxAttempts - attempts, attemptLetters, message);

        cout << "\nEnter a letter: ";
        cin >> letter;

        for ( int count = 0; count < attempts; count++ ) {

            if ( letter == attemptLetters[count] ) {

                message = "This letter has already been tried\n";
                letterWasTried = true;

            }
        }

        if ( letterWasTried == false ) {


            attemptLetters += letter;

            for ( int i = 0; i < sizeWord; i++ ) {

                if ( word[i] == letter ) {
                    mask[i] = letter;
                    letterWasMatch = true;
                }

            }

            if ( letterWasMatch == false ) {
               message = "Sorry, but you made a mistake\n";
            } else {
               message = "Congrats! You hit a letter :)\n";
            }

            attempts++;

        }

    }

    if ( word == mask ) {
        clearScreen();
        cout << "You win!\n";

    } else {
        clearScreen();
        cout << "You lose!\n";
    }

    cout << "\nPlay again (Y/N)? ";
    cin >> restart;

    clearScreen();

    if ( restart == 'Y' ) {
        return true;
    } else {
        return false;
    }

}


