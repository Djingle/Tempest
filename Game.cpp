#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Level.hpp"

// TODO : Gérer l'update des ennemies car la boucle itère sur la liste mais les objets
// sont de types Enemy et non Flipper.
// Peut-être tenter de faire un template pour les objets ? ( Proposition de Copilot :) )
// ou bien avec les dynamic_cast ? 
// TODO : Regarder pourquoi le player ne se déplace pas
// TODO : Gérer les collisions entre les objets

Game::Game() :
    is_running_{false},
    window_{NULL},
    renderer_{NULL}
{
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
        std::cout << "AAAH" << v_angle({450,562.5},{525,562.5},{525,487.5}) << std::endl;
        std::cout << "Subsystems initialized..." << std::endl;
        window_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window_ != NULL)
        {
            std::cout << "Window created..." << std::endl;
            renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer_ != NULL)
            {
                std::cout << "Renderer created..." << std::endl;
                texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,height, height);
                SDL_SetTextureBlendMode(texture_, SDL_BLENDMODE_BLEND);
                dst_.x = width/2 - height/2;
                dst_.y = 0;
                dst_.w = height;
                dst_.h = height;
                hud_.init(renderer_);
                level_.init(2,height);
                is_running_ = true;
            }
            player_= Player(level_);
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
void Game::test_collisions()
{
    std::vector<Enemy*>::const_iterator it = enemies_.begin(); 
    while (it != enemies_.end())
    {
        if ((*it)->get_lane_id() == player_.get_lane_id())
        {
            if ((*it)->get_depth() == player_.get_depth())
            {
                player_.set_nb_lives(player_.get_nb_lives()-1);
                delete *it;     
                enemies_.erase(it);
            }
        }
        std::vector<Bullet>::iterator bullet = bullets_.begin();
        while (bullet != bullets_.end()) {
            if (bullet->get_lane_id() == (*it)->get_lane_id())
            {
                if (bullet->get_depth() >= (*it)->get_depth()-0.005 && bullet->get_depth() <= (*it)->get_depth()+0.005)
                {
                    player_.set_score(player_.get_score()+(*it)->get_value());
                    delete *it;
                    bullets_.erase(bullet); 
                    enemies_.erase(it);
                }
            }
            if(bullet != bullets_.end())
                bullet++;
        }
        if(it != enemies_.end())
            it++;
    }           
}       
void Game::generate_enemies()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib_percentage(1,100);
    std::uniform_int_distribution<> distrib_lane(0,15);
    if (distrib_percentage(gen) == 1)
    {
        Flipper* flipper = new Flipper(distrib_lane(gen), 0.2,level_);
        enemies_.push_back(flipper);
    }

}
void Game::update_enemies(){
    for(auto& enemy : enemies_)
    {
        if(Flipper* f = dynamic_cast<Flipper*>(enemy))
        {
            f->update(level_);
        }
    }
}
void Game::update()
{
    level_.update(player_.get_lane_id());
    player_.update(level_);
    // Generate randomly enemies
    generate_enemies();
    // detect collisions with depth
    test_collisions();
    if (player_.get_is_shooting())
    {
        bullets_.push_back(Bullet(player_.get_lane_id(), 0.99, true,level_));
        player_.set_is_shooting(false);
    }
    if (Bullet::get_bullet_count() > 0) {
        std::vector<Bullet>::iterator bullet = bullets_.begin();
        while (bullet != bullets_.end()) {
            bullet->update(level_);
            if (bullet->get_depth() <= 0.20 || bullet->get_depth() >= 1.5) {
                bullets_.erase(bullet);
            }
            else ++bullet;
        }
    }
    update_enemies();
}
void Game::render()
{
    SDL_RenderClear(renderer_);
    hud_.render(renderer_,player_.get_score(),player_.get_nb_lives(),1);
    SDL_SetRenderTarget(renderer_, texture_);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 0);
    SDL_RenderClear(renderer_);
    level_.render(renderer_);
    player_.render(renderer_);
    for(auto enemy : enemies_) {
        enemy->render(renderer_);
    }
    SDL_SetRenderDrawColor(renderer_, 255, 0, 255, 255);
    for (auto& bullet : bullets_) {
        bullet.render(renderer_);
    }
    SDL_SetRenderTarget(renderer_, NULL);
    SDL_RenderCopy(renderer_, texture_, NULL, &dst_);
    SDL_RenderPresent(renderer_);
}

void Game::clean()
{
    if(texture_ != NULL)
        SDL_DestroyTexture(texture_);
    SDL_DestroyWindow(window_);
    SDL_DestroyRenderer(renderer_);
    SDL_Quit();
    std::cout << "Game cleaned..." << std::endl;
}
