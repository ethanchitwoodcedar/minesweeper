#include <stdio.h>
#include "board.c"


int main() {
   int posX;
   int posY;
   board master;

   printBoard();
   printf("Enter move (X Y): ");
   posX = fgetc();
   posY = fgetc();

   buildBoard(master, posX, posY);
   printBoard(master);
}
