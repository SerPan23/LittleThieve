#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED


#include "LittleThieve.h"

class Graphics {
public:
    Graphics(bool t);
	Graphics(){};
	~Graphics();

	void flip();
	void clear();

	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

#endif // GRAPHICS_H_INCLUDED
