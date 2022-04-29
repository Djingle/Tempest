#ifndef Game_hpp
#define Game_hpp
#include <SDL.h>
#include "Player.hpp"
#include "Bullet.hpp"
#include "HUD.hpp"
#include "Flipper.hpp"
#include "Spiker.hpp"
#include <vector>
#include <random>

class Game {
    private:
        bool is_running_;
        SDL_Window* window_;
        SDL_Renderer* renderer_;
        Player player_;
        std::vector<Bullet> bullets_;
        HUD hud_;
        Level level_;
        std::vector<Enemy*> enemies_;
        SDL_Texture* texture_;
        SDL_Rect dst_;
    public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game();
        /**
         * @brief Destroy the Game object
         * 
         */
        ~Game();
        /**
         * @brief init the game with the window and the renderer
         * 
         * @param title
         * @param xpos
         * @param ypos 
         * @param width
         * @param height 
         * @param fullscreen 
         */
        void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
        /**
         * @brief handle the events 
         * 
         */
        void handleEvents();
        /**
         * @brief update all the game's elements
         * 
         */
        void update();
        /**
         * @brief render all the game's elements
         * 
         */
        void render();
        /**
         * @brief clean properly the game before closing
         * 
         */
        void clean();
        /**
         * @brief verify if there is a collision between two elements
         * 
         */
        void test_collisions();
        /**
         * @brief randomly generate enemies
         * 
         */
        void generate_enemies();
        /**
         * @brief update the enemies' positions
         * 
         */
        void update_enemies();  
        /**
         * @brief Get the renderer object
         * 
         * @return SDL_Renderer* 
         */
        inline SDL_Renderer* get_renderer() const {return renderer_;};
        /**
         * @brief Get the level object
         * 
         * @return const Level& 
         */
        const Level& get_level() const {return level_;};
        /**
         * @brief get if the game is running
         * 
         * @return true 
         * @return false 
         */
        inline bool running() const {return is_running_;};
};
#endif
