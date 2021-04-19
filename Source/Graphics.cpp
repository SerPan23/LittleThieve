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


void Graphics::clear(int r, int g, int b) {
    SDL_SetRenderDrawColor(this->_renderer, r, g, b, 255);
	SDL_RenderClear(this->_renderer);
}

void Graphics::clear() {
    SDL_SetRenderDrawColor(this->_renderer, 158, 158, 158, 255);
	SDL_RenderClear(this->_renderer);
}


SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}
