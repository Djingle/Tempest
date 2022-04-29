#ifndef FLIPPER_HPP
#define FLIPPER_HPP
#include "Enemy.hpp"

class Flipper : public Enemy
{
    private :
        bool is_shooting_;
        int is_moving_; // 0 = not moving, 1 = moving right, 2 = moving left
    public : 
        Flipper(int lane_id, float depth,const Level& terrain);
        virtual ~Flipper();
        void move_right(const Level& terrain);
        void move_left(const Level& terrain);

        void update(const Level& terrain);

        void set_is_shooting(bool is_shooting) { is_shooting_ = is_shooting; }
        const bool& get_is_shooting() const { return is_shooting_; }
        void set_is_moving(int is_moving) { is_moving_ = is_moving; }
        const int& get_is_moving() const { return is_moving_; }
        mesh get_vertices() const override { return vertices_; }
};

#endif
