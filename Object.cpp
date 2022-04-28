#include "Object.hpp"
#include <iostream>
#include "utils.hpp"

Object::Object(int lane_id, float depth, const Level& terrain) :
    lane_id_{lane_id},
    depth_{depth},
    level_{terrain}
{
    //std::cout << "New Object" << std::endl;
}

vertex Object::get_pos() const
{
    return v_homothety(level_.get_lane(lane_id_).get_mid(), level_.get_center(), depth_);
}

float Object::get_angle() const
{
    return level_.get_lane(lane_id_).get_angle();
}

void Object::render(SDL_Renderer* renderer, const Level& level)
{
    // TODO
    vertex pos = v_homothety(level.get_lane(lane_id_).get_mid(), level.get_center(), depth_);
    SDL_RenderDrawPointF(renderer, pos.first, pos.second);
}