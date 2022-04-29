#include "HUD.hpp"
HUD::HUD(){
    // Initialize the texture
    texture_ = nullptr;
    // Initialize the destination rectangle
}

void HUD::init(SDL_Renderer* renderer) {
    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);
    texture_ = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w, h/6);
    if (texture_ == NULL) {
        std::cout << "Failed to create texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    SDL_SetTextureBlendMode(texture_, SDL_BLENDMODE_BLEND);
    dst_.x = 0;
    dst_.y = 0;
    dst_.w = w;
    dst_.h = h/6;
}
void HUD::render(SDL_Renderer* renderer,int score,int nb_lives,int lvl) {
    SDL_SetRenderTarget(renderer, texture_);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    m_write(renderer,"SCORE : " + std::to_string(score),dst_.w/1.5,dst_.h/2,0,255,0,255);
    m_write(renderer,"LIVES : " + std::to_string(nb_lives),dst_.w/8,dst_.h/2,255,255,0,255);
    m_write(renderer,"LEVEL "+std::to_string(lvl),dst_.w/2-dst_.w/10,dst_.h/2,0,0,255,255);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, texture_, NULL, &dst_);
}

HUD::~HUD(){
    if(texture_ != NULL)
        SDL_DestroyTexture(texture_);
}