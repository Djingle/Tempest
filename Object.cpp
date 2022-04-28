#include "Object.hpp"
#include <iostream>
#include "utils.hpp"

Object::Object(int lane_id, float depth, mesh vertices) :
    lane_id_{lane_id},
    depth_{depth},
    vertices_{vertices}
{
    // std::cout << "New Object" << std::endl;   
}

mesh Object::get_pos(const Level& terrain) const
{
    std::cout << "1" << std::endl;
    mesh res = vertices_;
    std::cout << "2" << std::endl;
    // We scale the template to map the coordinates to the lane width
    res = m_scale0(res, terrain.get_lane(lane_id_).get_width()/2);
    std::cout << "3" << std::endl;
    // We rotate the template so that it is oriented to the center
    res = m_rotate0(res, get_angle(terrain));
    std::cout << "4" << std::endl;
    // We translate the template to the begining of the lane
    res = m_translate(res, terrain.get_lane(lane_id_).get_mid().first, terrain.get_lane(lane_id_).get_mid().second);
    std::cout << "5" << std::endl;
    // Homothety to the depth
    res = m_homothety(res, terrain.get_center(), depth_);
    std::cout << "6" << std::endl;
    return res;
}

float Object::get_angle(const Level& terrain) const
{
    std::cout << "oui\n";
    return terrain.get_lane(lane_id_).get_angle();
    std::cout << "oui\n";
}

void Object::render(SDL_Renderer* renderer)
{
    vertex v1, v2;
    v1 = *vertices_.begin();
    v2 = *(vertices_.end()-1);
    for (mesh::const_iterator v = vertices_.begin(); v!= vertices_.end()-1; v++)
    {
        SDL_RenderDrawLineF(renderer, v1.first, v1.second, v2.first, v2.second);
        v1 = *v;
        v2 = *(v+1);
    }
    SDL_RenderDrawLineF(renderer, v1.first, v1.second, v2.first, v2.second);
}
