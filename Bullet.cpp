#include "Bullet.hpp"
#include "Level.hpp"

mesh Bullet::vertices_{{{0.5,0.5},
                        {0.5,1},
                        {0.5,0},
                        {-1,0.5},
                        {1,0.5}}};

int Bullet::bullet_count_{0};

Bullet::Bullet(int lane_id, float depth, bool direction) : 
    Object(lane_id, depth),
    direction_{direction}
{
    bullet_count_++;
}


Bullet::Bullet(const Bullet& bullet) :
    Object(bullet.get_lane_id(), bullet.get_depth()),
    direction_{bullet.get_direction()}
{
    bullet_count_++;
}

Bullet::~Bullet()
{
    bullet_count_--;
}

mesh Bullet::get_vertices() const {return vertices_;}

void Bullet::render(SDL_Renderer* renderer, const Level& level)
{
    vertex pos = v_homothety(level.get_lane(lane_id_).get_mid(), level.get_center(), depth_);
    SDL_RenderDrawPointF(renderer, pos.first, pos.second);
}

void Bullet::update()
{
    if (direction_) depth_ -= 0.01;
    else depth_ += 0.01;
}