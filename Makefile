all: Program.o Board.o Chess.o Color.o FigureMoving.o FigureOnSquare.o Square.o Moves.o
	g++ -o prog Program.o Board.o Chess.o Color.o FigureMoving.o FigureOnSquare.o Square.o Moves.o

Program: Program.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp Program.cpp

Board: Board.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp Board.cpp

Chess: Chess.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp Chess.cpp

Color: Color.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp Color.cpp

FigureMoving: FigureMoving.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp FigureMoving.cpp

FigureOnSquare: FigureOnSquare.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp FigureOnSquare.cpp

Square: Square.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp Square.cpp

Moves: Moves.cpp Board.h Chess.h Color.h Figure.h FigureMoving.h FigureOnSquare.h Square.h Moves.h Figure.h
	g++ -cpp Moves.cpp

clear:
	rm *.o