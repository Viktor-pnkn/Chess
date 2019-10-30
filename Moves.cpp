#include <iostream>
#include <string>
#include <vector>
#include "Chess.h"
#include "Square.h"
#include "Color.h"
#include "Figure.h"
#include "FigureOnSquare.h"
#include "FigureMoving.h"
#include "Board.h"
#include "Moves.h"

using namespace std;

Moves::Moves () {
}

Moves::Moves (Board board) {
	this->board = board;
}

bool Moves::CanMove(FigureMoving fm) {
    this->fm = fm;
    return
        CanMoveFrom() &&
        CanMoveTo() &&
        CanFigureMove();
}

bool Moves::CanMoveFrom() {
    return fm.from.OnBoard() &&
           GetColor(fm.figure) == board.moveColor;
}

bool Moves::Ravn (Square s1, Square s2) {
    return (s1.x == s2.x) && (s1.y == s2.y);
}

bool Moves::CanMoveTo() {
    return fm.to.OnBoard() &&
           !Ravn(fm.from, fm.to) &&
           GetColor(board.GetFigureAt(fm.to)) != board.moveColor;
}

bool Moves::CanFigureMove() {
    switch (fm.figure) {
                case whiteBishop:
                case blackBishop:
                    return (fm.SignX() != 0 && fm.SignY() != 0) &&
                            CanStraightMove();

                case whiteKing:
                case blackKing:
                    return CanKingMove();

                case whiteKnight:
                case blackKnight:
                    return CanKnightMove();

                case whitePawn:
                case blackPawn:
                    return CanPawnMove();

                case whiteQueen:
                case blackQueen:
                    return CanStraightMove();

                case whiteRook:
                case blackRook:
                    return (fm.SignX() == 0 || fm.SignY() == 0) &&
                            CanStraightMove();

                default: return false;
            }
}

bool Moves::CanStraightMove() {
    Square at = fm.from;
    do {
    	at.x = at.x + fm.SignX();
    	at.y = at.y + fm.SignY();
        //Square at(at.x + fm.SignX(), at.y + fm.SignY());
        if (Ravn(at, fm.to))
            return true;
	} while (at.OnBoard() &&
             board.GetFigureAt(at) == none);
    return false;
}

bool Moves::CanPawnMove() {
    if (fm.from.y < 1 || fm.from.y > 6)
        return false;
    int stepY = (GetColor(fm.figure) == white) ? 1 : -1;
    return CanPawnGo(stepY) ||
           CanPawnJump(stepY) ||
           CanPawnEat(stepY);
}

bool Moves::CanPawnGo(int stepY) {
    if (board.GetFigureAt(fm.to) == none)
        if (fm.DeltaX() == 0)
            if (fm.DeltaY() == stepY)
                return true;
    return false;
}

bool Moves::CanPawnJump(int stepY) {
    if (board.GetFigureAt(fm.to) == none)
        if (fm.DeltaX() == 0)
            if (fm.DeltaY() == 2 * stepY)
                if (fm.from.y == 1 || fm.from.y == 6) {
                	Square s(fm.from.x, fm.from.y + stepY);
                    if (board.GetFigureAt(s) == none)
                        return true;
                }
    return false;
}

bool Moves::CanPawnEat(int stepY) {
    if (board.GetFigureAt(fm.to) != none)
        if (fm.AbsDeltaX() == 1)
            if (fm.DeltaY() == stepY)
                return true;
    return false;
}

bool Moves::CanKingMove() {
    if (fm.AbsDeltaX() <= 1 && fm.AbsDeltaY() <= 1)
        return true;
    return false;
}

bool Moves::CanKnightMove() {
    if (fm.AbsDeltaX() == 1 && fm.AbsDeltaY() == 2)
        return true;
    if (fm.AbsDeltaX() == 2 && fm.AbsDeltaY() == 1)
        return true;
    return false;
}


Color Moves::GetColor (Figure figure) {
	if (figure == none) {
		return non;
	}
	return (figure == whiteBishop ||
            figure == whiteKing ||
            figure == whiteKnight ||
            figure == whitePawn ||
            figure == whiteQueen ||
            figure == whiteRook) 
            ? white
            : black;
}
