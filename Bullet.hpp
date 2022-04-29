#ifndef BULLET_HPP
#define BULLET_HPP
#include "Object.hpp"

class Bullet : public Object {
    private:
        static int bullet_count_;
        bool direction_; // true = fired by player, false = fired by enemy
    public:
        Bullet(int lane_id, float depth, bool direction,const Level& terrain);
        Bullet(const Bullet& bullet);
        virtual ~Bullet();

        void update(const Level& level);

        static const int& get_bullet_count() { return bullet_count_; }
        const bool& get_direction() const { return direction_; }
        static void print_bullet_count() { std::cout << "Bullet count : " << bullet_count_ << std::endl; }
};

#endif
