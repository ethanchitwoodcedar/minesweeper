#pragma once

#include <iostream>
#include <stdlib.h>
#include <time.h>

constexpr int BOARD_SIZE = 9;
constexpr int NUM_MINES = 10;

using namespace std;

class Board {
public:
	Board();
	char peak(const int x, const int y) const;
	bool won() const;
	bool move(int x, int y);
	friend ostream& operator<<(ostream &out, const Board &board);
private:
	void reveal(int x, int y);
	int getSquareValue(const int x, const int y) const;
	char front[BOARD_SIZE][BOARD_SIZE];
	char back[BOARD_SIZE][BOARD_SIZE];
};
