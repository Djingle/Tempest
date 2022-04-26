#ifndef BULLET_HPP
#define BULLET_HPP
#include "Object.hpp"

class Bullet : public Object {
    private:
        static int bullet_count_;
        bool direction_; // true = fired by player, false = fired by enemy
        static mesh vertices_;
    public:
        Bullet(int lane_id, float depth, bool direction);
        Bullet(const Bullet& bullet);
        virtual ~Bullet();

        static const int& get_bullet_count() { return bullet_count_; }
        const bool& get_direction() const { return direction_; }
        static void print_bullet_count() { std::cout << "Bullet count : " << bullet_count_ << std::endl; }
        mesh get_vertices() const override;

        void render(SDL_Renderer* renderer, const Level& level) override;
        void update() override;
        void clean() override {};

};

#endif