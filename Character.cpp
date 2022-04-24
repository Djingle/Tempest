#include "Character.hpp"

Character::Character(unsigned int nb_lives, unsigned int score, int lane_id, float depth) :
    Object{lane_id, depth},
    nb_lives_{nb_lives},
    score_{score}
{
    std::cout << "New Character" << std::endl;
}