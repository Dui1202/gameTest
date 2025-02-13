#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "Entity.h"
#include "GameObject.h"

class Game {
public:
	void update();
	void start();
	void handleEvent();
	void clean();
private:
};
