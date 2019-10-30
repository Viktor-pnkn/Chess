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

Chess::Chess (string fen) {
	this->fen = fen;
	Board b(fen);
	board = b;
	Moves moves(board);
	this->moves = moves;
}

Chess::Chess (Board board) {
	this->board = board;
	this->fen = board.fen;
	Moves moves(board);
	this->moves = moves;
}

Chess Chess::Move (string move) {
	FigureMoving fm(move);
	if (!moves.CanMove(fm)) {
		Chess t(board);
		return t;
	}
	if (board.IsCheckAfterMove(fm)) {
		Chess t(board);
		return t;
	}
	Board nextBoard = board.Move(fm);
	Chess nextChess(nextBoard);
	return nextChess;
}

char Chess::GetFigureAt (int x, int y) {
	Square square(x, y);
    Figure f = board.GetFigureAt(square);
    return static_cast<char>(f);
}

Color Chess::GetColor (Figure figure) {
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

void Chess::FindAllMoves () {
	FigureOnSquare AllFigures[16];
	Square AllSquares[8][8];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Square s(i, j);
			AllSquares[i][j] = s;
		}
	}
	int l = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Square square = AllSquares[i][j];
			Figure f = board.GetFigureAt(square);
			if (GetColor(f) == board.moveColor) {
				FigureOnSquare fs(f, square);
				AllFigures[l] = fs;
				l++;
			}
		}
	}
	for (int k = 0; k < l; k++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Square to = AllSquares[i][j];
				FigureMoving fm(AllFigures[k], to);
				if (!board.IsCheckAfterMove(fm) && moves.CanMove(fm)) {
					cout << static_cast<char>(fm.figure); //+ from.Name() + to.Name();
					cout << fm.from.Name1() << fm.from.Name2() << fm.to.Name1() << fm.to.Name2() << " ";
				}
			}
		}
	}
}

bool Chess::IsCheck () {
	return board.IsCheck();
}