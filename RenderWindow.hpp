#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include"Entity.h"


class RenderWindow {
public:
	RenderWindow(const char* title, int p_w, int h_w);
	SDL_Texture* loadTexture(const char* p_path);
	void cleanUp();
	void clear();
	void render(Entity &p_entity);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};