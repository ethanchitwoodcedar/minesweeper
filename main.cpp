// Minesweeper written in c++
// made by Ethan Chitwood.
#include "Board.h"

using namespace std;

int main() {
	int x;
	int y;
	bool hasLost = false;
	Board* board = new Board;

	cout << *board << endl;
	cout << "enter move (x, y): ";
	cin >> x >> y;
	while (board->peak(x, y) != ' ') {
		delete board;
		board = new Board;
	}
	board->move(y, x);
	
	while (!hasLost) {
		cout << *board << endl;
		cout << "enter move (x, y): ";
		cin >> x >> y;
		hasLost = board->move(y, x);
		if (board->won()) {
			break;
		}
	}

	if (hasLost) {
		cout << *board << endl << "You lost\n";
	}
	else {
		cout << *board << endl << "You won\n";
	}

	return 0;
}
