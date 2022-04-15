#include "Player.hpp"

Player::Player(): Character(3, 0, 0) {
}

void Player::move_right(const Terrain& terrain)
{
    if (lane_id_ < terrain.get_nb_lanes()-1) lane_id_++;
    else if (terrain.is_circular()) lane_id_ = 0;
}

void Player::move_left(const Terrain& terrain)
{
    if (lane_id_ > 0) lane_id_--;
    else if (terrain.is_circular()) lane_id_ = terrain.get_nb_lanes()-1;
}

void Player::shoot()
{
    
}

void Player::render(SDL_Renderer* renderer, const vertex& left, const vertex& right)
{
    vertex f, b, m, tmp;
    float pente = ( left.first - right.first ) / ( left.second - right.second );
    float ord_orig = right.second - pente * right.first;

    m.first = ( left.first - right.first ) / 2;
    m.second = ( left.second - right.second ) / 2;

    
}