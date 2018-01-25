#include "Animation.h"
#include "State.h"

int sheet_width = 2880; //How wide the entire sheet is
int sprite_width = 360; //The width of each individual sprite

//IDLE
void Idle::jumping(Animation* a)
{
	a->setCurrent(new Jumping);
	delete this;
}

void Idle::climbing(Animation* a)
{
	a->setCurrent(new Climbing);
	delete this;
}
void Idle::walking(Animation* a)
{
	a->setCurrent(new Walking);
	delete this;
}

void Idle::Animate(SDL_Rect& rect, Animation* a)
{
	rect.y = 1000;
}

//JUMPING
void Jumping::idle(Animation* a)
{
	a->setCurrent(new Idle);
	delete this;
}

void Jumping::Animate(SDL_Rect& rect, Animation* a)
{
	rect.y = 500;

	if (rect.x < sheet_width)
	{
		rect.x += sprite_width;
	}
	else
	{
		rect.x = 0;
		idle(a);
	}
}


//CLIMBING
void Climbing::idle(Animation* a)
{
	a->setCurrent(new Idle);
	delete this;
}

void Climbing::Animate(SDL_Rect& rect, Animation* a)
{
	rect.y = 0;

	if (rect.x < sheet_width)
	{
		rect.x += sprite_width;
	}
	else
	{
		rect.x = 0;
		idle(a);
	}
}

//Walking
void Walking::idle(Animation* a)
{
	a->setCurrent(new Idle);
	delete this;
}

void Walking::Animate(SDL_Rect& rect, Animation* a)
{
	rect.y = 1500;
	if (rect.x < sheet_width)
	{
		rect.x += sprite_width;
	}
	else
	{
		rect.x = 0;
		idle(a);
	}

	
	/*rect.y = 0;
	if (rect.x < sheet_width)
	{
		rect.x += sprite_width;
	}
	else
	{
		rect.x = 0;
		idle(a);
	}*/
}
