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

void onePlayer() {

    string word = returnRandomWord();

    int sizeWord = word.size();

    cout << "The secret word is " << word << "\n";

    cout << "Mask: " << createMask(sizeWord) << "\n";

}


