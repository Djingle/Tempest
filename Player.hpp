#ifndef Player_hpp
#define Player_hpp
#include "Character.hpp"
#include "Terrain.hpp"


class Player: public Character {
    public:
        Player();
        void render(SDL_Renderer* renderer, const vertex& left, const vertex& right);
        void move_right(const Terrain& terrain);
        void move_left(const Terrain& terrain);
        void shoot();
};

#endif