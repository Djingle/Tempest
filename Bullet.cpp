#include "Bullet.hpp"
#include "Level.hpp"

mesh Bullet_template{{{0,0.5},
                        {-0.5,0.5},
                        {0,0},
                        {0,1},
                        {0.5,0.5},
                        {0.25,0.5},
                        {-0.25,0.5},
                        {0,0.25},
                        {0,0.75}}};
int Bullet::bullet_count_{0};

Bullet::Bullet(int lane_id, float depth, bool direction,const Level& terrain) : 
    Object(lane_id, depth, Bullet_template),
    direction_{direction}{
    bullet_count_++;
    vertices_ = get_pos(terrain);
}

Bullet::Bullet(const Bullet& bullet) :
    Object(bullet.get_lane_id(), bullet.get_depth(), Bullet_template),
    direction_{bullet.get_direction()}{
    bullet_count_++;
}

Bullet::~Bullet(){
    bullet_count_--;
}

void Bullet::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    for(auto& vertex : vertices_)
        SDL_RenderDrawPoint(renderer, vertex.first, vertex.second);
}

void Bullet::update(const Level& level){
    if (direction_) depth_ -= 0.01;
    else depth_ += 0.01;
    vertices_ = get_pos(level);
}
