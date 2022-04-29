#include "Player.hpp"
#include "Bullet.hpp"

mesh Player_template  {{{-1, 0},
                        {-0.5, -0.5},
                        {1,0}}};

Player::Player() :
    Object(0, 1.0, Player_template),
    nb_lives_{3},
    score_{0},
    is_shooting_{false}
{
    std::cout << "New Player p" << std::endl;
}

Player::Player(const Level& terrain) :
    Object(0, 1.0, Player_template),
    nb_lives_{3},
    score_{0},
    is_shooting_{false}
{
    vertices_ = get_pos(terrain);
    std::cout << "New Player t" << std::endl;
}

Player::Player(const Player& player) :
    Object(player.lane_id_, player.depth_, Player_template),
    nb_lives_{player.nb_lives_},
    score_{player.score_},
    is_shooting_{player.is_shooting_}
{
    std::cout << "New Player" << std::endl;
}

void Player::update(const Level& terrain)
{
    if (direction_ != 0) {
        vertices_ = get_pos(terrain);
        std::cout << "l" << lane_id_ << std::endl;
        direction_ = 0;
    }
}

void Player::move_right(const Level& terrain)
{
    direction_ = 1;
    if (lane_id_ < terrain.get_nb_lanes()-1) lane_id_++;
    else if (terrain.is_circular()) lane_id_ = 0;
}

void Player::move_left(const Level& terrain)
{
    direction_ = -1;
    if (lane_id_ > 0) lane_id_--;
    else if (terrain.is_circular()) lane_id_ = terrain.get_nb_lanes()-1;
}
