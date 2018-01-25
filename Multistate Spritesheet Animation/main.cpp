#include "Sprite.h"
#include "Animation.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Set framerate
	float FramesPerSecond = 60.0f;
	//float FramesPerSecond = 10000.0f / 30.0f;
	Uint32 TickStart;

	bool gameRunning = true;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window;
	window = SDL_CreateWindow("RWM_P3", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Sprite Player(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);

	Animation animate;
	int timer = 0;

	while (gameRunning)
	{
		SDL_Event event;

		//Control Framerate
		TickStart = SDL_GetTicks();
		if (FramesPerSecond > SDL_GetTicks() - TickStart)
		{
			SDL_Delay(FramesPerSecond - (SDL_GetTicks() - TickStart));
		}

		//Cycle through the animations
		timer++;
		if (timer <= 100 && timer != 0)
		{
			Player.Walk();
		}
		else if (timer > 100 && timer <= 200)
		{
			Player.Jump();
		}
		else if (timer > 200 && timer < 300)
		{
			Player.Climb();
		}
		if (timer >= 300)
		{
			timer = 0;
		}
		SDL_RenderClear(renderer);
		Player.Render(renderer);
		SDL_RenderPresent(renderer);

	}

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	return 0;
}
