#include "Graphics.h"
#include "Globals.h"

Graphics::Graphics(bool t) {
    if(t)
    {
        SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
        SDL_SetWindowTitle(this->_window, "LittleThieve");
    }
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
	SDL_DestroyRenderer(this->_renderer);
}

void Graphics::flip() {
	SDL_RenderPresent(this->_renderer);
}


void Graphics::clear() {
    SDL_SetRenderDrawColor(this->_renderer, 0, 0, 0, 0);
	SDL_RenderClear(this->_renderer);
}


SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}
