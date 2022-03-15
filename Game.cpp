#include "Game.hpp"
#include <iostream>

int last_x;
int last_y;
Game::Game()
{
    isRunning_ = false;
    window_ = NULL;
    renderer_ = NULL;
}
Game::~Game()
{
    clean();
}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    isRunning_ = false;
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems initialized..." << std::endl;
        window_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window_ != NULL)
        {
            std::cout << "Window created..." << std::endl;
            renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer_ != NULL)
            {
                std::cout << "Renderer created..." << std::endl;
                isRunning_ = true;
            }
        }
    }
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning_ = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            isRunning_ = false;
            break;
        case SDLK_SPACE:
            SDL_SetRenderDrawColor(renderer_, 0,0,0,255);
            SDL_RenderClear(renderer_);
            break;
        }
        break;
    }
}

void Game::update()
{
    
}

void Game::render()
{
    //SDL_RenderClear(renderer_);
    draw();
    SDL_RenderPresent(renderer_);
}

void Game::clean()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}

void Game::draw()
{
	int x,y;
	if ( SDL_GetMouseState(&x,&y) & SDL_BUTTON(SDL_BUTTON_LEFT) ) 
	{
		const Uint8* state = SDL_GetKeyboardState(NULL);
		SDL_SetRenderDrawColor(renderer_, 255, 255, 0,255);
		if (state[SDL_SCANCODE_RSHIFT])
		{
			SDL_RenderDrawLine(renderer_, last_x,last_y,x,y);
		}
		else
		{
			SDL_RenderDrawPoint(renderer_, x, y);
		}
		last_x = x;
		last_y = y;
        SDL_SetRenderDrawColor(renderer_, 0,0,0,255);
	}
}
