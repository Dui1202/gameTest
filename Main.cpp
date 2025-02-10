#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "RenderWindow.hpp";

int main(int argc, char* agrs[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "Failed to init SDL! Error: " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "Failed to init IMG! Error: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("Gametest", 1280, 720);

	bool isGameRunning = true;
	SDL_Event e;
	while (isGameRunning) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				isGameRunning = false;
			}
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}