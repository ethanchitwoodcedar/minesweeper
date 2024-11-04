#include <iostream>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 9
#define MINES 10

using namespace std;

struct board {
   char front[BOARD_SIZE][BOARD_SIZE];
   char back[BOARD_SIZE][BOARD_SIZE];
};

void printBoard(board& master) {
   system("clear");

   for(int i = 0; i < BOARD_SIZE; i++) {
      for(int j = 0; j < BOARD_SIZE; j++) {
         if(master.front[i][j] == '+') {
            cout << '+';
         }
         else {
            cout << master.back[i][j];
         }
      }
      cout << endl;
   }
}

void buildBoard(board& master, int posX, int posY) {
   int x;
   int y;
   srand(time(0));

   for(int i = 0; i < BOARD_SIZE; i++) {
      x = rand() % BOARD_SIZE;
      y = rand() % BOARD_SIZE;
      if((x >= (posX - 1)) && (x <= (posX + 1)) && (y >= (posY - 1)) && (y <= (posY + 1))) {
         i--;
         continue;
      }
      if(master.back[x][y] != '*') {
         master.back[x][y] = '*';
      }
      else {
         i--;
      }
   }

   for(int i = 0; i < BOARD_SIZE; i++) {
      for(int j = 0; j < BOARD_SIZE; j++) {
         master.front[i][j] = '+';
      }
   }
}
