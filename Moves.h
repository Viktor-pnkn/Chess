#ifndef MOVES_H
#define MOVES_H

#include "FigureMoving.h"
#include "Board.h"
#include "Color.h"

class Moves {
	public:
		FigureMoving fm;
		Board board;
		Moves ();
		Moves (Board board);
		bool CanMove(FigureMoving fm);
		bool CanMoveFrom();
		bool CanMoveTo();
		bool Ravn (Square s1, Square s2);
		bool CanFigureMove();
		Color GetColor(Figure figure);
		bool CanKnightMove();
		bool CanKingMove();
		bool CanStraightMove();
		bool CanPawnMove();
		bool CanPawnGo(int stepY);
		bool CanPawnJump(int stepY);
		bool CanPawnEat(int stepY);
};
#endif