#include "Player.hpp"

void Player::move_right()
{
    //How can I know what lane is next? Player has to know his position on the terrain? (ie int)
    terrain_pos_++;
}

void Player::render(SDL_Renderer* renderer)
{
    //The player has to know which lane he's on so that he can render itself
}