#include <iostream>
#include <string>
#include "Chess.h"
#include "Square.h"
#include "Color.h"
#include "Figure.h"
#include "FigureOnSquare.h"
#include "FigureMoving.h"
#include "Board.h"
#include "Moves.h"

using namespace std;

	void ChessToAscii (Chess chess) {
		cout << "   +-----------------+\n";
        for (int y = 7; y >= 0; y--) {
            cout << " " << y + 1 << " | ";
            for (int x = 0; x < 8; x++)
                cout << chess.GetFigureAt(x, y) << " ";
            cout << "|\n";
        }
        cout << "   +-----------------+\n";
        cout << "     a b c d e f g h\n";
	}
int main() {
	Chess chess;
	while (true) {
		cout << chess.fen << endl;
		ChessToAscii(chess);
		/*for (string moves : chess.GetAllMoves()) {
			cout << moves << " ";
		}*/
		if (chess.IsCheck()) 
			cout << "CHECK" << endl;
		chess.FindAllMoves();
		cout << endl;
		cout << "> ";
		string move;
		getline(cin, move);
		if (move == "") {
			break;
		}
		chess = chess.Move(move);
	}
}