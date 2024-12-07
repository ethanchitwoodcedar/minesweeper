#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 9
#define MINES 10

using namespace std;

struct board {
   char front[BOARD_SIZE][BOARD_SIZE];
   char back[BOARD_SIZE][BOARD_SIZE];
   const int SIZE = BOARD_SIZE;
};

void printBoard(board &master) {
   system("clear");

   for(int i = 0; i < BOARD_SIZE; i++) {
      for(int j = 0; j < BOARD_SIZE; j++) {
         if(master.front[i][j] == '+') {
            printf('+');
         }
         else {
            printf(master.back[i][j]);
         }
      }
      printf("\n");
   }
}

void printBoard() {
   system("clear");
   for(int i = 0; i < BOARD_SIZE; i++) {
     for(int j = 0; j < BOARD_SIZE; j++) {
        printf("+");
     }
     printf("\n");
   }
}

void findSum(board &master, int x, int y) {
   if(x > 0 && x < (BOARD_SIZE - 1) && y > 0 && y < (BOARD_SIZE - 1)) {
      return master.back[x - 1][y - 1] + master.back[x - 1][y]
                  + master.back[x - 1][y + 1] + master.back[x][y - 1] + master.back[x][y + 1] 
                  + master.back[x + 1][y - 1] + master.back[x + 1][y] + master.back[x + 1][y + 1];
   }
   else if(x == 0 && y == 0) {
      return master.back[x + 1][y] + master.back[x + 1][y - 1] + master.back[x][y - 1];
   }
   else if(x == 0 && y == BOARD_SIZE - 1) {
      return master.back[x + 1][y] + master.back[x + 1][y + 1] + master.back[x][y + 1];
   }
   else if(x == BOARD_SIZE -1 && y == 0) {
      return master.back[x + 1][y] + master.back[x + 1][y + 1] + master.back[x][y + 1];
   }
   else if(x == BOARD_SIZE - 1 && y == BOARD_SIZE - 1) {
      return master.back[x + 1][y] + master.back[x + 1][y + 1] + master.back[x][y + 1];
   }




}

void buildBoard(board &master, int posX, int posY) {
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
