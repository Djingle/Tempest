#ifndef Game_hpp
#define Game_hpp
#include <SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "HUD.hpp"
#include <vector>
/**
 * @brief 
 * 
 */
class Game {
    private:
        bool is_running_;
        SDL_Window* window_;
        SDL_Renderer* renderer_;
        Player player_;
        std::vector<Bullet> bullets_;
        HUD hud_;
    public:
        Game();
        ~Game();
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        void handleEvents();
        void update();
        void render();
        void clean();
        inline SDL_Renderer* get_renderer() const {return renderer_;};
        inline bool running() const {return is_running_;};
};
#endif
