#include "Level.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Lane.hpp"
#include <fstream>
void Level::init(unsigned int lvl,int height)
{
    std::ifstream file;
    file.open("../Assets/Levels/level"+std::to_string(lvl)+".txt");
    if (file.is_open()) 
    {   
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
    for (auto lane : lanes_) {
        lane.render(renderer);
    }
    lanes_[player_pos_].render(renderer);
}

void Level::clean()
{
    
}