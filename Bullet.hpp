#ifndef BULLET_HPP
#define BULLET_HPP
#include "Object.hpp"

class Bullet : public Object {
    private:
        static int bullet_count_;
    public:
        Bullet(int lane_id, const Level& level);
        virtual ~Bullet();

        static int get_bullet_count() { return bullet_count_; }
        void render(SDL_Renderer* renderer) override;
        void update() override;
        void clean() override {};
};

#endif