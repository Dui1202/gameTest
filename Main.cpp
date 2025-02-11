#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "RenderWindow.hpp";
#include "Entity.h"

int main(int argc, char* agrs[]) {
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "Failed to init SDL! Error: " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "Failed to init IMG! Error: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("Gametest", 1280, 720);
	SDL_Texture* playerTexture = window.loadTexture("./asset/player/witch-idle-sprite.png");
	SDL_Texture* grassTexture = window.loadTexture("./asset/grass");
	Entity player(Vector2f(100,100), playerTexture);
	std::vector<Entity> grasses;
	Entity grass(Vector2f(0, 120), grassTexture);
	for (int i = 0; i < 4; i++) {

	}

	bool isGameRunning = true;
	SDL_Event e;
	while (isGameRunning) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				isGameRunning = false;
			}
		}
		window.clear();
		window.render(player);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}