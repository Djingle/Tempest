#ifndef Player_hpp
#define Player_hpp
#include "Character.hpp"
#include "Terrain.hpp"


class Player: public Character {
    public:
        Player();
        void render(SDL_Renderer* renderer, vertex left, vertex right);
        void move_right(const Terrain& terrain);
        void move_left(const Terrain& terrain);
};

#endif