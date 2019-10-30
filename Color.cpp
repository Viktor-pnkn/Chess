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

Color ColorMethods::FlipColor (Color color) {
	if (color == black) {
		return white;
    }
    if (color == white) {
    	return black;
    } 
    return non;
}