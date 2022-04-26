#include "Level.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Lane.hpp"
#include <fstream>
void Level::init(SDL_Renderer* renderer,unsigned int lvl)
{
    int width,height;
    SDL_GetRendererOutputSize(renderer,&width,&height);
    std::ifstream file;
    file.open("../Assets/Levels/level"+std::to_string(lvl)+".txt");
    if (file.is_open()) 
    {   
        texture_ = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,height, height);
        SDL_SetTextureBlendMode(texture_, SDL_BLENDMODE_BLEND);
        dst_.x = width/2 - height/2;
        dst_.y = 0;
        dst_.w = height;
        dst_.h = height;
        float xmin,xmax,ymin,ymax;
        int x_center,y_center;
        float scale;
        file >> circular_;
        file >> xmin >> xmax;
        file >> ymin >> ymax;
        file >> x_center >> y_center;
        file >> scale;
        center_ = v_normalize(x_center,xmin,xmax,y_center,ymin,ymax,height,height);
        while(!file.eof())
        {
            float x_FR,y_FR,x_FL,y_FL; // FR = Front Right, FL = Front Left
            file >> x_FR >> y_FR >> x_FL >> y_FL;
            const vertex fr_norm = v_normalize(x_FR,xmin,xmax,y_FR,ymin,ymax,height,height);
            const vertex fl_norm = v_normalize(x_FL,xmin,xmax,y_FL,ymin,ymax,height,height);
            lanes_.push_back(Lane(center_,scale,fr_norm,fl_norm));
        }
    }
    else
        std::cout << "Error opening file" << std::endl;
}
void Level::update(unsigned int player_pos)
{
    player_pos_ = player_pos;
    for (auto &lane : lanes_) {
        lane.set_active(false);
    }
    lanes_[player_pos_].set_active(true);
}

void Level::render(SDL_Renderer* renderer)
{
    SDL_SetRenderTarget(renderer, texture_);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    for (auto lane : lanes_) {
        lane.render(renderer);
    }
    lanes_[player_pos_].render(renderer);
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_RenderClear(renderer);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, texture_, NULL, &dst_);
    SDL_SetRenderTarget(renderer, texture_);
}

void Level::clean()
{
    
}