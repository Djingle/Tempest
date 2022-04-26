#include <SDL.h>
#include <assert.h>
#include <iostream>
#include "Game.hpp"
#include "Bullet.hpp"


Game *game = nullptr;

int main(int argc, char** argv)
{
	game = new Game();
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	int frameCount = 0;
	game->init("Tempest", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600,900, false);
	while (game->running())
	{
        // We change the color in the lane renderer, we have to set back the base color here.
        SDL_SetRenderDrawColor(game->get_renderer(), 0, 0, 0, 0);
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	delete game;
	return EXIT_SUCCESS;
}
