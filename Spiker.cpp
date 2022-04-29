#include "Spiker.hpp"
#include <math.h>
mesh Spiker_template {{{0 ,0},
                        {-0.4, 0.4},
                        {0  , 0.6},
                        {0.4,0.4},
                        {0.4, 0},
                        {0 ,-0.4},
                        {-0.6,0},
                        {-0.6,0.6},
                        {0,1},
                        {0.8,0.6},
                        {0.8,0},
                        {0,-0.8},
                        {-1,0},
                        {-1,0.8}}};


Spiker::Spiker(int lane_id, float depth,const Level& terrain) :
    Enemy{lane_id, depth, Spiker_template,50},
    destination_{lane_id_},
    direction_{0},
    angle_{}{
    vertices_ = get_pos(terrain);
}
Spiker::~Spiker(){};

void Spiker::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    Object::render(renderer);
}


void Spiker::update(const Level& terrain){
    (depth_<1.0) ? depth_ += 0.001 : depth_ = 1.0;
    vertices_ = get_pos(terrain);
}
