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
#include <math.h>

FigureMoving::FigureMoving() {
}

FigureMoving::FigureMoving (FigureOnSquare fs, Square to) {
	this->figure = fs.figure;
    this->from = fs.square;
    this->to = to;
}

FigureMoving::FigureMoving (FigureOnSquare fs, Square to, Figure promotion) {
	this->figure = fs.figure;
    this->from = fs.square;
    this->to = to;
    this->promotion = promotion;
}

FigureMoving::FigureMoving (string move) {
	this->figure = (Figure)move[0]; // приведение от char к Figure
    // возможно, так как в классе Figure всем фигурам дали имена
    this->from = Square(move.substr(1, 2));
    this->to = Square(move.substr(3, 2));
    this->promotion = (move.length() == 6) ? (Figure)move[5] : none;
}

int FigureMoving::DeltaX () {
	return this->to.x - this->from.x;
}

int FigureMoving::DeltaY () {
	return this->to.y - this->from.y;
}

int FigureMoving::AbsDeltaX () {
	return abs(DeltaX());
}

int FigureMoving::AbsDeltaY () {
	return abs(DeltaY());
}

int FigureMoving::Sign(int val)
{
   return (val>0)?(1):((val<0)?(-1):(0));
}

int FigureMoving::SignX () {
	return Sign(DeltaX());
}

int FigureMoving::SignY () {
	return Sign(DeltaY());
}

string FigureMoving::ToString () {
	/*char text = static_cast<char>(figure) + from.Name() + to.Name();
	if (promotion != none)
		text += static_cast<char>(promotion);
	*/return "";
}