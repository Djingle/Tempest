#ifndef OBJECT_HPP
#define OBJECT_HPP
#include <SDL.h>
#include "Level.hpp"

class Object
{
    protected :
        int lane_id_;
        float depth_;
    
    public :
        Object(int lane_id, float depth);
        virtual ~Object() = default;

        virtual void render(SDL_Renderer* renderer, const Level& level) = 0;
        virtual void update() = 0;
        virtual void clean() = 0;

        inline int get_lane_id() const { return lane_id_; }
        inline float get_depth() const { return depth_; }
        virtual mesh get_vertices() const = 0;
};

#endif