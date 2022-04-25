#include "Player.hpp"

Player::Player(const Level& level) :
    Object{0, 1.0, level},
    nb_lives_{3},
    score_{0}
{
    std::cout << "New Player" << std::endl;
}

void Player::move_right(const Level& terrain)
{
    if (lane_id_ < terrain.get_nb_lanes()-1) lane_id_++;
    else if (terrain.is_circular()) lane_id_ = 0;
}

void Player::move_left(const Level& terrain)
{
    if (lane_id_ > 0) lane_id_--;
    else if (terrain.is_circular()) lane_id_ = terrain.get_nb_lanes()-1;
}

void Player::shoot()
{
    
}

void Player::render(SDL_Renderer* renderer)
{
    const Lane& lane = level_.get_lane(lane_id_);
    vertex l, r, b, f, m;
    l = lane.get_f_left();
    r = lane.get_f_right();
    l.first -= 100*lane.get_u().first;
    l.second -= 100*lane.get_u().second;
    r.first += 100*lane.get_u().first;
    r.second += 100*lane.get_u().second;
    m = {(l.first + r.first)/2, (l.second + r.second)/2};
    b = {m.first + 100*lane.get_v().first, m.second + 100*lane.get_v().second};
    f = {m.first - 200*lane.get_v().first, m.second - 200*lane.get_v().second};

    SDL_SetRenderDrawColor(renderer, 245, 236, 66, 0);
    SDL_RenderDrawLineF(renderer, l.first, l.second, b.first, b.second);
    SDL_RenderDrawLineF(renderer, r.first, r.second, b.first, b.second);
    SDL_RenderDrawLineF(renderer, l.first, l.second, f.first, f.second);
    SDL_RenderDrawLineF(renderer, r.first, r.second, f.first, f.second);
    // SDL_RenderDrawPointF(renderer, l.first, l.second);
    // SDL_RenderDrawPointF(renderer, r.first, r.second);
    // SDL_RenderDrawPointF(renderer, b.first, b.second);
    // SDL_RenderDrawPointF(renderer, f.first, f.second);
    // SDL_RenderDrawPointF(renderer, m.first, m.second);
}