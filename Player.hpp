#ifndef Player_hpp
#define Player_hpp
#include "Character.hpp"

class Player: public Character {
    private:
    
    public:
        void render(SDL_Renderer* renderer);
        void move_right();
        void move_left();
};

#endif