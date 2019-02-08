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

void showStatus(string mask, int remainingAttempts, string attemptLetters) {

    cout << "Word: " << mask << "\n";

    cout << "Remaining attempts: " << remainingAttempts  << "\n";

    cout << "Attempt letters: ";

    for ( int count = 0; count < attemptLetters.size() ; count++ ) {

        cout << attemptLetters[count];

        if ( count < attemptLetters.size() - 1 ) {
            cout << ", ";
        }

    }

}

void onePlayer() {

    string word = returnRandomWord();

    int sizeWord = word.size();

    int attempts = 0, maxAttempts = 5;

    char letter;

    string mask = createMask(sizeWord), attemptLetters = "";

    while ( word != mask && maxAttempts - attempts > 0 ) {

        bool letterWasTried = false;

        showStatus(mask, maxAttempts - attempts, attemptLetters);

        cout << "\nEnter a letter: ";
        cin >> letter;

        for ( int count = 0; count < attempts; count++ ) {

            if ( letter == attemptLetters[count] ) {

                cout << "\nThis letter has already been tried\n";
                letterWasTried = true;

            }
        }

        if ( letterWasTried == false ) {

            attemptLetters += letter;

            for ( int i = 0; i < sizeWord; i++ ) {

                if ( word[i] == letter ) {
                    mask[i] = letter;
                }

            }

            attempts++;

        }

    }

    if ( word == mask ) {
        clearScreen();
        cout << "You win!";
    } else {
        clearScreen();
        cout << "You lose!";
    }

}


