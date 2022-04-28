#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Level.hpp"

Flipper flipper{2, 0.45};
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
            texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,height, height);
            SDL_SetTextureBlendMode(texture_, SDL_BLENDMODE_BLEND);
            dst_.x = width/2 - height/2;
            dst_.y = 0;
            dst_.w = height;
            dst_.h = height;
            hud_.init(renderer_);
            level_.init(height,2);
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
            player_.move_left(level_);
            break;
        case SDLK_RIGHT:
            player_.move_right(level_);
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
    level_.update(player_.get_lane_id());

    if (player_.get_is_shooting())
    {
        bullets_.push_back(Bullet(player_.get_lane_id(), 0.99, true));
        player_.set_is_shooting(false);
    }
    if (Bullet::get_bullet_count() > 0) {
        std::vector<Bullet>::iterator bullet = bullets_.begin();
        while (bullet != bullets_.end()) {
            bullet->update();
            if (bullet->get_depth() <= 0.20 || bullet->get_depth() >= 1.5) {
                bullets_.erase(bullet);
            }
            else ++bullet;
        }
    }
    flipper.update();
}
void Game::render()
{
    SDL_RenderClear(renderer_);
    hud_.render(player_.get_score(),player_.get_nb_lives(),1);
    SDL_SetRenderTarget(renderer_, texture_);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
    SDL_RenderClear(renderer_);
    level_.render(renderer_);
    player_.render(renderer_,level_);
    for (auto bullet : bullets_) {
        bullet.render(renderer_, level_);
    }
    flipper.render(renderer_, level_);
    SDL_SetRenderTarget(renderer_, NULL);
    SDL_RenderCopy(renderer_, texture_, NULL, &dst_);
    SDL_RenderPresent(renderer_);
}

void Game::clean()
{
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}
