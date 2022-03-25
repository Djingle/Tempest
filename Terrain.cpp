#include "Terrain.hpp"
#include "Game.hpp"

Terrain::Terrain(unsigned int player_pos, std::vector<Lane> lanes) :
    player_pos_{player_pos},
    lanes_{lanes}
{ 
    lanes_[player_pos_].set_active(true);
    std::cout << "New terrain" << std::endl;
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