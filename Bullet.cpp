#include "Bullet.hpp"
#include "Level.hpp"

int Bullet::bullet_count_ = 0;

Bullet::Bullet(int lane_id, const Level& level) : Object(lane_id, 1.0, level)
{
    bullet_count_++;
}

Bullet::~Bullet()
{
    bullet_count_--;
}

void Bullet::render(SDL_Renderer* renderer)
{
    vertex pos = m_homothety(get_base_coordinates(), level_.get_center(), depth_);
    SDL_RenderDrawPointF(renderer, pos.first, pos.second);
}

void Bullet::update()
{
    std::cout << "depth : " << depth_ << std::endl;
    depth_ -= 0.01;
}