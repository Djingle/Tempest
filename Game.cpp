#include "Game.hpp"
#include <iostream>

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
        }
        break;
    }
}

void Game::update()
{
    
}

void Game::render()
{
    SDL_RenderClear(renderer_);
    SDL_RenderPresent(renderer_);
}

void Game::clean()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
