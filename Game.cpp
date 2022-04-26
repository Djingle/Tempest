#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Level.hpp"

Level test_terrain{2};
Game::Game() :
    is_running_{false},
    window_{NULL},
    renderer_{NULL},
    player_{Player(test_terrain)}
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
        case SDLK_SPACE:
            player_.set_is_shooting(true);
            break;
        }
        break;
    }
}

void Game::update()
{
    test_terrain.update(player_.get_lane_id());
    if (player_.get_is_shooting())
    {
        bullets_.push_back(Bullet(player_.get_lane_id(), test_terrain));
        player_.set_is_shooting(false);
    }
    // if (Bullet::get_bullet_count() > 0) {
        for (std::vector<Bullet>::iterator bullet = bullets_.begin(); bullet != bullets_.end(); ++bullet) {
            bullet->update();
            if (bullet->get_depth() <= 0.25) {
                bullets_.erase(bullet);
            }
        }
    // }
}

void Game::render()
{
    SDL_RenderClear(renderer_);
    test_terrain.render(renderer_);
    player_.render(renderer_, test_terrain);
    for (auto& bullet : bullets_)
        bullet.render(renderer_, test_terrain);
    m_write(renderer_, "Hello World!", 100, 100);
    SDL_RenderPresent(renderer_);
}

void Game::clean()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}
