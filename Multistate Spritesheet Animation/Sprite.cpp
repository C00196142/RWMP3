#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer)
{
	texture = IMG_LoadTexture(renderer, "png/spritesheet.png");
	//texture = IMG_LoadTexture(renderer, "png/sonic.png");

	//Chnages how much of the sprite is shown
	frameRect.x = 0;
	frameRect.y = 0;
	frameRect.w = 360;
	frameRect.h = 500;
	//frameRect.w = 40;
	//frameRect.h = 50;

	//Adjust the size of the sprite to suit
	spriteRect.x = 0;
	spriteRect.y = 0;
	spriteRect.w = 128;
	spriteRect.h = 175;
}


Sprite::~Sprite()
{
}

void Sprite::Jump()
{
	animate.jumping();
}

void Sprite::Climb()
{
	animate.climbing();
}

void Sprite::Walk()
{
	animate.walking();
}

void Sprite::Render(SDL_Renderer* renderer)
{
	animate.Update(frameRect);
	SDL_RenderCopy(renderer, texture, &frameRect, &spriteRect);
}