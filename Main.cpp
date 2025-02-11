#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "RenderWindow.hpp"
#include "Entity.h"

int main(int argc, char* agrs[]) {
	//Initialize SDL and IMG
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "Failed to init SDL! Error: " << SDL_GetError() << std::endl;
	}

	if (!IMG_Init(IMG_INIT_PNG)) {
		std::cout << "Failed to init IMG! Error: " << SDL_GetError() << std::endl;
	}

	RenderWindow window("Gametest", 1280, 720);
	SDL_Texture* playerTexture = window.loadTexture("./asset/player/witch-idle-sprite.png");
	Entity player(Vector2f(100,100), playerTexture);

	bool isGameRunning = true;
	SDL_Event e;
	Uint32 lastTime = SDL_GetTicks();
	float accumulator = 0.0f;
	const float timeStep = 16.67f;

	//The main game loop
	while (isGameRunning) {
		Uint32 currentTime = SDL_GetTicks();
		float frameTime = currentTime - lastTime;
		lastTime = currentTime;
		accumulator += frameTime;

		while (accumulator >= timeStep) {
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_QUIT) {
					isGameRunning = false;
				}
			}
			accumulator -= timeStep;
		}
		//Clear the screen
		window.clear();
		//Draw the screen
		window.render(player);
		//Show screen
		window.display();

		//Show the fps on console
		float fps = 1000.0f / frameTime;
		std::cout << fps << std::endl;

		//Frame Delay ( make sure the game is always on 60 fps )
		int frameDelay = 16 - (SDL_GetTicks() - currentTime);
		if (frameDelay > 0) SDL_Delay(frameDelay);
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}