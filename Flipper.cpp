#include "Flipper.hpp"
mesh Flipper_template {{{-1  ,-0.5},
                        {-0.5,   0},
                        {-1  , 0.5},
                        {1   ,-0.5},
                        {0.5 ,   0},
                        {1   ,0.5}}};


Flipper::Flipper(int lane_id, float depth,const Level& terrain) :
    Enemy{lane_id, depth, Flipper_template},
    is_shooting_{false},
    is_moving_{false}
{
    vertices_ = get_pos(terrain);
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
    if (depth_<1.0) depth_ += 0.04;
    std::cout << depth_ << std::endl;
}
