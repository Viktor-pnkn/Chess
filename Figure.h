#ifndef FIGURE_H
#define FIGURE_H

#include "Color.h"
using namespace std;

enum Figure
{
	none = '.',

	whiteKing = 'K',
    whiteQueen = 'Q',
    whiteRook = 'R',
    whiteBishop = 'B',
    whiteKnight = 'N',
    whitePawn = 'P',

    blackKing = 'k',
    blackQueen = 'q',
    blackRook = 'r',
    blackBishop = 'b',
    blackKnight = 'n',
    blackPawn = 'p'
};
#endif