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

Square::Square() {}

Square::Square (int x, int y) {
	this->x = x;
	this->y = y;
}

bool Square::OnBoard() {
	return x >= 0 && x < 8 &&
           y >= 0 && y < 8 ;
}

Square::Square (string e2) {
    if (e2.length() == 2 &&
    e2[0] >= 'a' && e2[0] <= 'h' &&
    e2[1] >= '1' && e2[1] <= '8') {
        this->x = e2[0] - 'a';
        this->y = e2[1] - '1';
    }
    else
        Square (-1, -1);
}

void Square::operator=(const Square& b) {
    x = b.x;
    y = b.y;
}

string Square::ToStr (int k) {
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

char Square::Name1() {
    return 'a' + x;// + ToStr(this->y+1);
}

string Square::Name2() {
    return ToStr(this->y+1);
}