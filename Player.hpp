#ifndef Player_hpp
#define Player_hpp
#include "Object.hpp"
#include "Level.hpp"


class Player: public Object {
    private:
        int nb_lives_;
        int score_;
    public:
        Player();
        void render(SDL_Renderer* renderer, const Lane& lane);
        void update() {};
        void clean() {};
        void move_right(const Level& terrain);
        void move_left(const Level& terrain);
        void shoot();
};

#endif