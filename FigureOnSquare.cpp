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

FigureOnSquare::FigureOnSquare () {
}

FigureOnSquare::FigureOnSquare (Figure figure, Square square) {
	this->figure = figure;
	this->square = square;
}