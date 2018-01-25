#include <SDL.h>
#include <SDL_image.h>
#include "Animation.h"
#pragma once

class Sprite
{
public:
	Sprite(SDL_Renderer*);
	~Sprite();
	void Render(SDL_Renderer*);
	void Jump();
	void Climb();
	void Walk();

private:
	Animation animate;

	SDL_Rect spriteRect;
	SDL_Rect frameRect;
	SDL_Texture * texture;
};