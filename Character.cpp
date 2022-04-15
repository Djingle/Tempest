#include "Character.hpp"

Character::Character(unsigned int nb_lives, unsigned int score, int lane_id) :
    nb_lives_{nb_lives},
    score_{score},
    lane_id_{lane_id}
{
    std::cout << "New Character" << std::endl;
}