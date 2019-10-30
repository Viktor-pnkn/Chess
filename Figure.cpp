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

Color FigureMethods::GetColor (Figure figure) {
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