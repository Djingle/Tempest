#include "Enemy.hpp"

Enemy::Enemy(int lane_id, float depth) :
    Object(lane_id, depth)
{
    std::cout << "New Enemy" << std::endl;
}

Enemy::~Enemy(){};

void Enemy::render(SDL_Renderer* renderer, const Level& level)
{
    
}

void Enemy::update()
{

}

void Enemy::clean()
{

}