#include "Flipper.hpp"

mesh Flipper::vertices_{{{-1  , -0.5},
                         {-0.5 , 0},
                         {-1  , 0.5},
                         {1   ,   -0.5},
                         {0.5 , 0},
                         {1 , 0.5}}};

Flipper::Flipper(int lane_id, float depth) :
    Enemy(lane_id, depth),
    is_shooting_{false},
    is_moving_{0}
{
    std::cout << "New Flipper" << std::endl;
}

Flipper::~Flipper(){};

void Flipper::move_right(const Level& terrain)
{
    if (lane_id_ < terrain.get_nb_lanes()-1) lane_id_++;
    else if (terrain.is_circular()) lane_id_ = 0;
}

void Flipper::move_left(const Level& terrain)
{
    if (lane_id_ > 0) lane_id_--;
    else if (terrain.is_circular()) lane_id_ = terrain.get_nb_lanes()-1;
}


void Flipper::update()
{

}

void Flipper::render(SDL_Renderer* renderer, const Level& level)
{
    vertex center = level.get_center();
    vertex pos = v_homothety(level.get_lane(lane_id_).get_mid(), center, depth_);
    float angle = get_angle(level.get_lane(lane_id_).get_mid(), center, {center.first, center.second+1});
    mesh res = m_rotate(vertices_, {0,0}, angle);
    res = m_homothety(res, center, depth_);
    // choose red color
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    for (vertex v : res)
    {
        SDL_RenderDrawPointF(renderer, v.first, v.second);
    }
}

void Flipper::clean()
{}