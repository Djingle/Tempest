#include "Object.hpp"
#include "Level.hpp"
#include <iostream>

Object::Object(int lane_id, float depth, const Level& level) :
    lane_id_{lane_id},
    depth_{depth},
    level_{level}
{
    std::cout << "New Object" << std::endl;
}

