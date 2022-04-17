#include "Terrain.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Lane.hpp"
#include <fstream>
#include <cmath>

vertex normalize(float x,float min_x,float max_x,float y, float min_y, float max_y)
{
    int x_norm = lround((x-min_x)/(max_x-min_x)*800);
    int y_norm = 600-lround((y-min_y)/(max_y-min_y)*600);
    std::cout << "x_norm: " << x_norm << " y_norm: " << y_norm << std::endl;
    return {x_norm,y_norm}; 
}

Terrain::Terrain(unsigned int lvl)
{
    std::ifstream file;
    file.open("../Assets/Levels/level"+std::to_string(lvl)+".txt");
    if (file.is_open()) 
    {
        unsigned int nb_lanes;
        int xmin,xmax,ymin,ymax;
        file >> nb_lanes;
        file >> circular_;
        file >> xmin >> xmax;
        file >> ymin >> ymax;
        for (unsigned int i = 0; i < nb_lanes; i++)
        {
            float x1,y1,x2,y2,x3,y3,x4,y4;
            file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            const vertex a = {x1,y1};
            const vertex b = {x2,y2};
            const vertex c = {x3,y3};
            const vertex d = {x4,y4};
            const vertex a_normalize = normalize(x1,xmin,xmax,y1,ymin,ymax);
            const vertex b_normalize = normalize(x2,xmin,xmax,y2,ymin,ymax);
            const vertex c_normalize = normalize(x3,xmin,xmax,y3,ymin,ymax);
            const vertex d_normalize = normalize(x4,xmin,xmax,y4,ymin,ymax);
            // const Lane tmp_lane{a, b, c, d};
            const Lane tmp_lane{a_normalize, b_normalize, c_normalize, d_normalize};
            lanes_.push_back(tmp_lane);
        }
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
}

void Terrain::update(unsigned int player_pos)
{
    player_pos_ = player_pos;
    for (auto &lane : lanes_) {
        lane.set_active(false);
    }
    lanes_[player_pos_].set_active(true);
}

void Terrain::render(SDL_Renderer* renderer)
{
    for (auto lane : lanes_) {
        lane.render(renderer);
    }
    lanes_[player_pos_].render(renderer);
}

void Terrain::clean()
{
    
}