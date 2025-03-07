#include "board.h"

Board::Board() {
    int x;
    int y;
    int squareValue;
    srand((unsigned int)time(0));

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            back[i][j] = ' ';
        }
    }

    for (int i = 0; i < NUM_MINES; i++) {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;

        if (back[x][y] != '*') {
            back[x][y] = '*';
        }
        else {
            i--;
        }
    }
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            squareValue = getSquareValue(i, j);
            if (squareValue > 0) {
                back[i][j] = (char)(squareValue + 0x30);
            }
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            front[i][j] = '#';
        }
    }
}

char Board::peak(const int x, const int y) const
{
    return back[x][y];
}

bool Board::won() const {
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (front[i][j] == '#') {
                count++;
            }
        }
    }
    return (count == NUM_MINES);
}

bool Board::move(int x, int y) {
    if (back[x][y] == '*') {
        return true;
    }

    reveal(x, y);

    return false;
}

void Board::reveal(int x, int y) {
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE || 
        front[x][y] == 'o') {
        return;
    }
    cout << x << " " << y << endl;
    front[x][y] = 'o';

    if (back[x][y] == ' ') {
        reveal(x    , y - 1);
        reveal(x    , y + 1);
        reveal(x - 1, y - 1);
        reveal(x + 1, y - 1);
        reveal(x + 1, y + 1);
        reveal(x - 1, y + 1);
        reveal(x - 1, y    );
        reveal(x + 1, y    );
    }
}

int Board::getSquareValue(const int x, const int y) const {
    if (back[x][y] == '*') {
        return 0;
    }

    int count = 0;
    int pos[] = {1, 0, -1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((x + pos[i] >= 0) && (x + pos[i] < BOARD_SIZE) && 
                (y + pos[j] >= 0) && (y + pos[j] < BOARD_SIZE) && 
                (back[x + pos[i]][y + pos[j]] == '*')) {
                count++;
            }
        }
    }
    
    return count;
}

ostream& operator<<(ostream& out, const Board &board) {
	system("cls"); // use "clear" for unix like operating systems

    out << "X0 1 2 3 4 5 6 7 8\n";
	for (int i = 0; i < BOARD_SIZE; i++) {
        out << i;
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board.front[i][j] == '#') {
				out << board.front[i][j] << " ";
			}
			else {
				out << board.back[i][j] << " ";
			}
		}
		out << endl;
	}
	return out;
}
