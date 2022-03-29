#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Terrain.hpp"
#include "Player.hpp"

Terrain test_terrain{1};

Game::Game() :
    is_running_{false},
    window_{NULL},
    renderer_{NULL},
    player_{Player()}
{
    std::cout << "New game" << std::endl;
}

Game::~Game()
{
    clean();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    is_running_ = false;
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO ) == 0)
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
                is_running_ = true;
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
        is_running_ = false;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_ESCAPE:
            is_running_ = false;
            break;
        case SDLK_LEFT:
            player_.move_left(test_terrain);
            break;
        case SDLK_RIGHT:
            player_.move_right(test_terrain);
            break;
        }
        break;
    case SDLK_d:
        
        break;
    }
}

void Game::update()
{
    test_terrain.update(player_.get_lane_id());
}

void Game::render()
{
    SDL_RenderClear(renderer_);
    test_terrain.render(renderer_);
    SDL_RenderPresent(renderer_);
}

void Game::clean()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}
