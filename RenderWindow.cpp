#include <iostream>
#include<SDL.h>
#include<SDL_image.h>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int p_w, int p_h)
	:window(NULL), renderer(NULL) {
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	if (window == NULL) {
		std::cout << "Failed to initialize window! Error: " << SDL_GetError << std::endl;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
SDL_Texture* RenderWindow::loadTexture(const char* p_path) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_path);
	if (texture == NULL) {
		std::cout << "Failed to load texture! Error:" << SDL_GetError() << std::endl;
	}

	return texture;
}
void RenderWindow::cleanUp() {
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
}
void RenderWindow::clear() {

}