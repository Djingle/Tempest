#include "Enemy.hpp"

Enemy::Enemy(int lane_id, float depth, mesh vertices) :
    Object(lane_id, depth, vertices)
{
}

Enemy::~Enemy(){}

void Enemy::update(){}