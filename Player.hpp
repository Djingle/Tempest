#ifndef Player_hpp
#define Player_hpp
#include "Character.hpp"
#include "Terrain.hpp"

class Player: public Character {
    private:
        int terrain_pos_;
    public:
        void render(SDL_Renderer* renderer);
        void move_right(const Terrain& terrain);
        void move_left(const Terrain& terrain);
};

#endif