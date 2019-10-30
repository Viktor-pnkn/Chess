#ifndef FIGUREMOVING_H
#define FIGUREMOVING_H

#include "Figure.h"
#include "Square.h"
#include "FigureOnSquare.h"

class FigureMoving {
    public:
        Figure figure;
	    Square from;
	    Square to;
	    Figure promotion;
	    FigureMoving();
	    FigureMoving (FigureOnSquare fs, Square to);
	    FigureMoving (FigureOnSquare fs, Square to, Figure promotion);
	    FigureMoving (string move);
	    int DeltaX ();
	    int DeltaY ();
	    int AbsDeltaX ();
	    int AbsDeltaY ();
	    int SignX ();
	    int SignY ();
	    int Sign(int val);
	    string ToString ();
};

#endif