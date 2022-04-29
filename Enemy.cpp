#include "Enemy.hpp"

Enemy::Enemy(int lane_id, float depth, mesh vertices, int value) :
    Object(lane_id, depth, vertices){
    value_ = value;
}

Enemy::~Enemy(){}

void Enemy::update(){}