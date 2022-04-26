#include "HUD.hpp"
HUD::HUD(){
    // Initialize the renderer
    renderer_ = nullptr;
    // Initialize the texture
    texture_ = nullptr;
    // Initialize the destination rectangle
}

void HUD::init(SDL_Renderer* renderer) {
    renderer_ = renderer;
    int w, h;
    SDL_GetRendererOutputSize(renderer_, &w, &h);
    texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h);
    if (texture_ == NULL) {
        std::cout << "Failed to create texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    dst_.x = 0;
    dst_.y = 0;
    dst_.w = w;
    dst_.h = h/6;
}
void HUD::render(int score,int nb_lives,int lvl) {
    SDL_SetRenderTarget(renderer_, texture_);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
    m_write(renderer_,std::to_string(score),dst_.w/4,dst_.h/2,0,255,0,255);
    m_write(renderer_,std::to_string(nb_lives),dst_.w/8,dst_.h-10,255,255,0,255);
    m_write(renderer_,std::to_string(lvl),dst_.w/2,dst_.h/2,0,0,255,255);
    SDL_SetRenderDrawColor(renderer_, 0, 255, 0, 255);
    SDL_RenderClear(renderer_);
    SDL_SetRenderTarget(renderer_, NULL);
    SDL_RenderCopy(renderer_, texture_, NULL, &dst_);
}

HUD::~HUD(){
    if(texture_ != NULL)
        SDL_DestroyTexture(texture_);
}