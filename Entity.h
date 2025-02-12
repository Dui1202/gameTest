#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include"Math.h"

class Entity {
public:
	Entity(Vector2f p_vector, SDL_Texture* p_tex, SDL_Rect p_frame);
	//Get the Entity position
	Vector2f& getPos();
	void setPos(const Vector2f& p_pos);
	SDL_Rect getCurrentFrame();
	SDL_Texture* getTex();
private:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};
