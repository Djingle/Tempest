#include "Bullet.hpp"
#include "Level.hpp"

int Bullet::bullet_count_{0};

Bullet::Bullet(int lane_id, const Level& level) : Object(lane_id, 1.0)
{
    bullet_count_++;
    std::cout << "New bullet : " << bullet_count_ << std::endl;
}

Bullet::~Bullet()
{
    bullet_count_--;
}

void Bullet::render(SDL_Renderer* renderer, const Level& level)
{
    vertex pos = m_homothety(level.get_lane(lane_id_).get_mid(), level.get_center(), depth_);
    SDL_RenderDrawPointF(renderer, pos.first, pos.second);
}

void Bullet::update()
{
    std::cout << "depth : " << depth_ << std::endl;
    depth_ -= 0.01;
}