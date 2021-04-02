#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

struct Vector2 {
	int x, y;
	Vector2() :
		x(0), y(0)
	{}
	Vector2(int x, int y) :
		x(x), y(y)
	{}
	Vector2 zero() {
		return Vector2(0, 0);
	}
};


#endif // GLOBALS_H_INCLUDED
