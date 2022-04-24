#ifndef BULLET_HPP
#define BULLET_HPP

class Bullet : public Object {
    private:
    public:
        void render(SDL_Renderer* renderer, const Lane& lane);
        void update();
        void clean();
};

#endif