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
    if (depth_<1.0) depth_ += 0.004;
}

void Flipper::render(SDL_Renderer* renderer, const Level& level)
{
    // Center of homothety
    vertex level_center = level.get_center();
    vertex lane_center = level.get_lane(lane_id_).get_mid();
    vertex left = level.get_lane(lane_id_).get_f_left();
    vertex right = level.get_lane(lane_id_).get_f_right();
    // Position of the center of the object
    vertex pos = v_homothety(level.get_lane(lane_id_).get_mid(), level_center, depth_);
    // Used to calculate the size of the object
    float lane_size = v_distance(left, right);
    // Angle of rotation
    float angle = get_angle(left, right, {right.first+1, right.second});
    
    mesh res = m_translate(m_rotate(m_scale0(vertices_, lane_size/2.0), {0,0}, angle), lane_center.first, lane_center.second);
    res = m_homothety(res, level_center, depth_);
    // choose red color
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    vertex v1, v2;
    v1 = *res.begin();
    v2 = *(res.end()-1);
    SDL_RenderDrawLineF(renderer, v1.first, v1.second, v2.first, v2.second);
    for (mesh::iterator v = res.begin(); v != res.end()-1; v++) {
        v1 = *v;
        v2 = *(v+1);
        SDL_RenderDrawLineF(renderer, v1.first, v1.second, v2.first, v2.second);
    }
}

void Flipper::clean()
{}