#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SDL.h>
#include "Level.hpp"

class Object
{
    protected :
        int lane_id_;
        float depth_;
        const Level& level_;
    
    public :
        Object(int lane_id, float depth, const Level& level);
        //virtual ~Object();
        virtual void render(SDL_Renderer* renderer) = 0;
        virtual void update() = 0;
        virtual void clean() = 0;

        inline int get_lane_id() const { return lane_id_; }
        inline float get_depth() const { return depth_; }
        inline vertex get_base_coordinates() const { return level_.get_lane(lane_id_).get_mid(); }
};

#endif