#include <iostream>
#include <string>
#include "Chess.h"
#include "Square.h"
#include <vector>
#include "Color.h"
#include "Figure.h"
#include "FigureOnSquare.h"
#include "FigureMoving.h"
#include "Board.h"
#include "Moves.h"

using namespace std;

Board::Board () {
}

Board::Board (string fen) {
    this->fen = fen;
    for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			figures[i][j] = none;
		}
	}
    Init();	
}

int Board::StrToInt (string s) {
	int t = s[0] - '0';
	for (size_t i = 1; i < s.length(); ++i) {
		t = t*10;
		t += s[i] - '0';
	}
	return t;
}

void Board::Init () {
	// rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1
    // 0                                           1 2    3 4 5
    vector<string> parts(6);
	int k = 0;
	for (int i = 0; i < 6; i++) {
		while (fen[k] != ' ' && k < fen.length()) {
			parts[i] += fen[k];
			k++;
		}
		k++;
	}
	InitFigures(parts[0]);
    moveColor = parts[1] == "b" ? black : white;
    moveNumber = StrToInt(parts[5]);
}

void Board::ReplaceDigits (string& s) {
	char k = '2';
	string m = "..";
	while (k <= '9') {
		int pos = s.find(k);
		while (pos != -1) {
			s.erase(pos,1);
			s.insert(pos,m);
			pos = s.find(k);
		}
		k++;
		m += ".";
	}
}


void Board::InitFigures(string data) {
    ReplaceDigits(data);
    vector<string> lines(8);
	int k = 0;
	for (int i = 0; i < 8; i++) {
		while (data[k] != '/' && k < data.length()) {
			lines[i] += data[k];
			k++;
		}
		k++;
	}
    for (int y = 7; y >= 0; y--)
        for (int x = 0; x < 8; x++)
            this->figures[x][y] = ((lines[7-y][x] == '.') || (lines[7-y][x] == '1'))  ? none :
                        (Figure)lines[7-y][x];
}

void Board::SetFigureAt (Square square, Figure figure) {
    if (square.OnBoard()) {
        this->figures[square.x][square.y] = figure;

    }
}

Figure Board::GetFigureAt (Square square) {
    if (square.OnBoard()) {
        return figures[square.x][square.y];
	}
	return none;
}

string Board::IntToStr (int k) {
	string s, m;
	while (k > 0) {
		m = k%10 + '0';
		s += m;
		k = (k - k%10)/10;
	}
	for (size_t i = 0; i < s.length()/2; ++i) {
	    char c = s[i];
	    s[i] = s[s.length() - i - 1];
	    s[s.length() - i - 1] = c;
	}
	return s;
}

void Board::GenerateFEN() {
    this->fen = FenFigures() +
    (moveColor == white ? " w" : " b") +
    " - - 0 " + IntToStr(moveNumber);
}

void Board::Replace (string &s, string a, string v) {
	int pos = s.find(a);
	while (pos != -1) {
		s.erase(pos,a.length());
		s.insert(pos,v);
		pos = s.find(a);
	}
}

string Board::FenFigures() {
    string sb;
    for (int y = 7; y >= 0; y--) {
        for (int x = 0; x < 8; x++) {
        	if (figures[x][y] == none) {
        		sb += "1";
        	}
        	else {
        		sb += (char)figures[x][y];
        	}
        }
        if (y > 0)
            sb += "/";
    }
    string eight = "11111111";
    for (int j = 8; j >= 2; j--) {
    	Replace(sb, eight.substr(0,j), IntToStr(j));
    }
    return sb;
}

Board Board::Move (FigureMoving fm) {
    Board next(fen);
    next.SetFigureAt(fm.from, none);
    //next.SetFigureAt(fm.to, fm.promotion == none ? fm.figure : fm.promotion);
    next.SetFigureAt(fm.to, fm.figure);
    if (moveColor == black)
        next.moveNumber++;
    next.moveColor = ColorMethods::FlipColor(moveColor);
    next.GenerateFEN();
    return next;
}

void Board::operator=(const Board& b) {
	fen = b.fen;
	moveColor = b.moveColor;
	moveNumber = b.moveNumber;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			figures[i][j] = b.figures[i][j];
		}
	}
}

bool Board::IsCheck () {
	Board after(fen);
	after.moveColor = ColorMethods::FlipColor(moveColor);
	return after.CanEatKing();
}

bool Board::CanEatKing () {
    Square badKing = FindBadKing(); // находим координату чужого короля
    Moves moves; // создаем все возможные ходы на доске
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Square square(i, j);
			Figure f = GetFigureAt(square);
			if (GetColor(f) == moveColor) {
				FigureOnSquare fs(f, square);
				FigureMoving fm(fs, badKing);
                if (moves.CanMove(fm))
                    return true;
			}
		}
	}
	return false;
}

Square Board::FindBadKing () {
	Figure badKing;
	if (moveColor == black)
		badKing = whiteKing;
	else
		badKing = blackKing;
    for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Square s(i, j);
        	if (GetFigureAt(s) == badKing)
            	return s;
        }
    }
    Square s(-1,-1);
    return s;
}

Color Board::GetColor (Figure figure) {
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

bool Board::IsCheckAfterMove (FigureMoving fm) {
	Board after = Move(fm);
	return after.CanEatKing(); 
}