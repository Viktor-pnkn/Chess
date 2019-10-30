#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "Figure.h"
#include "Color.h"
#include "Square.h"
#include "FigureMoving.h"

class Board {
    public:
        string fen;
	    Figure figures[8][8];
	    Color moveColor;
	    int moveNumber;
	    Board ();
	    Board (string fen);
	    void Init();
	    void InitFigures(string data);
	    int StrToInt (string s);
	    void ReplaceDigits (string& s);
	    void Replace (string &s, string a, string v);
	    void GenerateFEN();
	    string IntToStr(int k);
	    string FenFigures();
	    void operator=(const Board& b);
	    Figure GetFigureAt (Square square);
	    void SetFigureAt (Square square, Figure figure);
	    Board Move (FigureMoving fm);
	    bool IsCheck ();
	    bool CanEatKing();
	    Square FindBadKing ();
	    Color GetColor (Figure figure);
	    bool IsCheckAfterMove (FigureMoving fm);
};
#endif