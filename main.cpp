#include <iostream>
#include "board.h"

using namespace std;

int main() {
   int posX  = 4;
   int posY = 4;

   board master;
   buildBoard(master, posX, posY);
   printBoard(master);
}
