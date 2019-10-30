#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

struct Square {
	public:
		int x;
		int y;
		Square ();
		Square (int x, int y);
		Square (string e2);
        bool OnBoard();
        void operator=(const Square& b);
        string Name2();
        char Name1();
        string ToStr (int k);
};

#endif