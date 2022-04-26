#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "Object.hpp"


class Enemy : public Object
{
    private :
        static int enemy_count_;
        int value_;
    public :
        Enemy(int lane_id, float depth);
        virtual ~Enemy();

        void render(SDL_Renderer* renderer, const Level& level) override;
        void update() override;
        void clean() override;

        static const int& get_enemy_count() { return enemy_count_; }
        const int& get_value() const { return value_; }
};


#endif