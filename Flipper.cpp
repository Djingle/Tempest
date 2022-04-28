#include "Flipper.hpp"
mesh Flipper_template {{{-1  ,-0.5},
                        {-0.5,   0},
                        {-1  , 0.5},
                        {1   ,-0.5},
                        {0.5 ,   0},
                        {1   ,0.5}}};

Flipper::Flipper(int lane_id, float depth) :
    Enemy{lane_id, depth, Flipper_template},
    is_shooting_{false},
    is_moving_{false}
{

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
    if (depth_<1.0) depth_ += 0.004;

}
