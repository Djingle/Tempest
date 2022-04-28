#include "Enemy.hpp"

Enemy::Enemy(int lane_id, float depth, mesh vertices) :
    Object(lane_id, depth, vertices)
{
    std::cout << "New Enemy" << std::endl;
}

Enemy::~Enemy(){};
