#ifndef CHESS_H
#define CHESS_H

#include <string>
#include <list>
#include "Board.h"
#include "Moves.h"
#include "Square.h"
using namespace std;

class Chess {
	public:
		Board board;
		string fen;
		Moves moves;
		Chess (string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
		Chess (Board board);
		Chess Move (string move);
		char GetFigureAt (int x, int y);
		void FindAllMoves();
		list <string> GetAllMoves ();
		Color GetColor (Figure figure);
		bool IsCheck ();
};
#endif