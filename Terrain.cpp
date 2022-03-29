#include "Terrain.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include "Lane.hpp"
#include <fstream>
#include <cmath>

Terrain::Terrain(unsigned int player_pos, std::vector<Lane> lanes) :
    player_pos_{player_pos},
    lanes_{lanes}
{ 
    lanes_[player_pos_].set_active(true);
    std::cout << "New terrain" << std::endl;
}

int normalize(float x,float min,float max)
{
    return lround(((x-min)/(max-min)));
}
Terrain::Terrain(unsigned int player_pos, unsigned int lvl):player_pos_{player_pos}
{
    std::ifstream file;
    file.open("../Assets/Levels/level"+std::to_string(lvl)+".txt");
    if (file.is_open()) 
    {
        unsigned int nb_lanes;
        int xmin,xmax,ymin,ymax;
        file >> nb_lanes;
        file >> xmin >> xmax;
        file >> ymin >> ymax;
        for (unsigned int i = 0; i < nb_lanes; i++)
        {
            float x1,y1,x2,y2,x3,y3,x4,y4;
            file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            // const vertex& a = {normalize(x1,xmin,xmax),normalize(y1,ymin,ymax)};
            // const vertex& b = {normalize(x2,xmin,xmax),normalize(y2,ymin,ymax)};
            // const vertex& c = {normalize(x3,xmin,xmax),normalize(y3,ymin,ymax)};
            // const vertex& d = {normalize(x4,xmin,xmax),normalize(y4,ymin,ymax)};
            const vertex a = {x1,y1};
            const vertex b = {x2,y2};
            const vertex c = {x3,y3};
            const vertex d = {x4,y4};
            const Lane tmp_lane{a, b, c, d};
            lanes_.push_back(tmp_lane);
        }
        for(auto i : lanes_){
            std::cout << i << std::endl;
        }
        lanes_[player_pos_].set_active(true);
    }
    else
    {
        std::cout << "Error opening file" << std::endl;
    }
}

void Terrain::update()
{
    for (auto lane : lanes_) lane.set_active(false);
    lanes_[player_pos_].set_active(true);
}

void Terrain::render(SDL_Renderer* renderer)
{
    int i=0;
    for (auto lane : lanes_) {
        if (i!=player_pos_) lane.render(renderer);
        i++;
    }
    lanes_[player_pos_].render(renderer);
}

void Terrain::clean()
{
    
}