#include "Object.hpp"
#include <iostream>

Object::Object(int lane_id, float depth) :
    lane_id_{lane_id},
    depth_{depth}
{
    std::cout << "New Object" << std::endl;
}

