#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>

#include "menu.h"
#include "onePlayer.h"

using namespace std;

int main() {

    srand((unsigned)time(NULL));

    mainMenu();

    onePlayer();

    return 0;

}

