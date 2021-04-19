#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

namespace globals {
	const int SCREEN_WIDTH = 1500;
	const int SCREEN_HEIGHT = 1000;
}

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

class Mouse{
public:
    Vector2 pos;
    bool leftBtnPressed = false;
};

#endif // GLOBALS_H_INCLUDED
