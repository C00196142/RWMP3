#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Sprite.h"
class Game
{
public:
	Game();
	~Game();


private:
	SDL_Window * window;
	SDL_Event event;
	bool isRunning = true;
	SDL_Renderer* renderer;
};

