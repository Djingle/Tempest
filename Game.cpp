#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Terrain.hpp"

// const vertex& f1 = {100, 100};
// const vertex& f2 = {300, 100};
// const vertex& f3 = {500, 100};
// const vertex& f4 = {700, 100};
// const vertex& b1 = {100, 500};
// const vertex& b2 = {300, 500};
// const vertex& b3 = {500, 500};
// const vertex& b4 = {700, 500};

// const Lane test_lane1{f1, f2, b1, b2};
// const Lane test_lane2{f2, f3, b2, b3};
// const Lane test_lane3{f3, f4, b3, b4};

// std::vector<Lane> mes_lanes = {test_lane1, test_lane2, test_lane3};

Terrain test_terrain{1, 1};

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
        case SDLK_LEFT:
            
            break;
        case SDLK_RIGHT:
            break;
        }
        break;
    case SDLK_d:
        
        break;
    }
}

void Game::update()
{
    test_terrain.update();
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
