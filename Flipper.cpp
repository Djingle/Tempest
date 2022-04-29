#include "Flipper.hpp"
#include <math.h>
mesh Flipper_template {{{-1  ,-0.5},
                        {-0.5,   0},
                        {-1  , 0.5},
                        {1   ,-0.5},
                        {0.5 ,   0},
                        {1   ,0.5}}};


Flipper::Flipper(int lane_id, float depth,const Level& terrain) :
    Enemy{lane_id, depth, Flipper_template},
    is_shooting_{false},
    destination_{lane_id_},
    direction_{0},
    angle_{}
{
    vertices_ = get_pos(terrain);
}
Flipper::~Flipper(){};

void Flipper::move_right(const Level& terrain)
{
    if (direction_ == 0) {
        direction_++;
        if (lane_id_ < terrain.get_nb_lanes()-1) destination_ = lane_id_+1;
        else if (terrain.is_circular()) destination_ = 0;
        angle_ = abs(terrain.get_angle_diff(lane_id_, destination_, direction_))/2;
    }
}

void Flipper::move_left(const Level& terrain)
{   
    if (direction_ == 0) {
        direction_--;
        if (lane_id_ > 0) destination_ = lane_id_-1;
        else if (terrain.is_circular()) destination_ = terrain.get_nb_lanes()-1;
        angle_ = abs(terrain.get_angle_diff(lane_id_, destination_, direction_))/2;
    }
}

void Flipper::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    Object::render(renderer);
}


void Flipper::update(const Level& terrain)
{
    if (depth_ < 0.92 && depth_ > 0.9) move_right(terrain);
    (depth_<1.0) ? depth_ += 0.004 : depth_ = 1.0;
    if (destination_ != lane_id_) {
        std::cout << "Flipper is moving" << std::endl;
        std::cout << "angle_ : " << angle_ << std::endl;
        if (angle_ > 0.1) {
            v_template_ = m_rotate(v_template_, {0, direction_}, direction_*0.1);
            angle_ -= 0.1;
            std::cout << "oui" << std::endl;
        }
        else {
            v_template_ = Flipper_template;
            lane_id_ = destination_;
            angle_ = 0;
            std::cout << "non" << std::endl;
        }
    }
    vertices_ = get_pos(terrain);
}
