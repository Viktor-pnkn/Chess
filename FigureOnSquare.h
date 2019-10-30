#ifndef FIGUREONSQUARE_H
#define FIGUREONSQUARE_H

#include "Figure.h"
#include "Square.h"

using namespace std;

class FigureOnSquare {
    public:
	Figure figure;
	Square square;
	FigureOnSquare ();
	FigureOnSquare (Figure figure, Square square);
	
};

#endif