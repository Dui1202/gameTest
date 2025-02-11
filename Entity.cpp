#include"Entity.h"
#include<SDL.h>
#include<SDL_image.h>

Entity::Entity(Vector2f p_vector, SDL_Texture* p_tex)
	:pos(p_vector), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 64;
	currentFrame.h = 64;
}
Vector2f Entity::getPos() {
	return pos;
}
SDL_Rect Entity::getCurrentFrame() {
	return currentFrame;
}
SDL_Texture* Entity::getTex() {
	return tex;
}