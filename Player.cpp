#include "Player.hpp"
static int i = 0;
Player::Player(): Character(3, 0, 0) {
    i++;
    std::cout << "New Player " << i << std::endl;
}

void Player::move_right(const Terrain& terrain)
{
    //How can I know what lane is next? Player has to know his position on the terrain? (ie int)
    if (terrain.is_circular()) lane_id_ = (lane_id_++)%terrain.get_nb_lanes();
    else if (lane_id_ < terrain.get_nb_lanes()-1) lane_id_++;
}

void Player::move_left(const Terrain& terrain)
{
    if (terrain.is_circular()) lane_id_ = (lane_id_--)%terrain.get_nb_lanes();
    else if (lane_id_ > 0) lane_id_--;
}

void Player::render(SDL_Renderer* renderer)
{
    //The player has to know which lane he's on so that he can render itself
}
