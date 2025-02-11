#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"Math.h"

class Entity {
public:
	Entity(Vector2f p_vector, SDL_Texture* p_tex);
	//Get the Entity position
	Vector2f getPos();
	SDL_Rect getCurrentFrame();
	SDL_Texture* getTex();
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
