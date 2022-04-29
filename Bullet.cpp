#include "Bullet.hpp"
#include "Level.hpp"

mesh Bullet_template{{{0.5,0.5},
                        {0.5,1},
                        {0.5,0},
                        {-1,0.5},
                        {1,0.5}}};

int Bullet::bullet_count_{0};

Bullet::Bullet(int lane_id, float depth, bool direction,const Level& terrain) : 
    Object(lane_id, depth, Bullet_template),
    direction_{direction}
{
    bullet_count_++;
    vertices_ = get_pos(terrain);
}


Bullet::Bullet(const Bullet& bullet) :
    Object(bullet.get_lane_id(), bullet.get_depth(), Bullet_template),
    direction_{bullet.get_direction()}
{
    bullet_count_++;
}

Bullet::~Bullet()
{
    bullet_count_--;
}


void Bullet::update(const Level& level)
{
    if (direction_) depth_ -= 0.01;
    else depth_ += 0.01;
    vertices_ = get_pos(level);
}
