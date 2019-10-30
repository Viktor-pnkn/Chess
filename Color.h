#ifndef COLOR_H
#define COLOR_H

using namespace std;

enum Color {
    non,
    white,
    black
};

class ColorMethods {
	public:
		static Color FlipColor (Color color);
};
#endif