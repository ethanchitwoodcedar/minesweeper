#include <iostream>
#include "board.h"

using namespace std;

int main() {
   int posX;
   int posY;
   board master;

   printBoard();
   cout << "Enter move (X Y): ";
   cin >> posX;
   cin >> posY;

   buildBoard(master, posX, posY);
   printBoard(master);
}
