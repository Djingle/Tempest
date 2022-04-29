#ifndef FLIPPER_HPP
#define FLIPPER_HPP
#include "Enemy.hpp"

class Flipper : public Enemy
{
    private :
        bool is_shooting_;
        int destination_; // lane to the right or left where the Flipper is going
        int direction_; // 0 if not moving, 1 if moving right, -1 if moving left
        float angle_;
    public : 
        Flipper(int lane_id, float depth,const Level& terrain);
        virtual ~Flipper();
        void move_right(const Level& terrain);
        void move_left(const Level& terrain);

        void update(const Level& terrain);
        void render(SDL_Renderer* renderer);

        void set_is_shooting(bool is_shooting) { is_shooting_ = is_shooting; }
        const bool& get_is_shooting() const { return is_shooting_; }
        mesh get_vertices() const override { return vertices_; }
};

#endif
