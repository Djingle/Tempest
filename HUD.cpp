#include "HUD.hpp"
HUD::HUD(){
    // Initialize the renderer
    renderer_ = nullptr;
    // Initialize the texture
    texture_ = nullptr;
}

void HUD::init(SDL_Renderer* renderer,int width, int height) {
    renderer_ = renderer;
    texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);
    if (texture_ == NULL) {
        std::cout << "Failed to create texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    dst_.x = 0;
    dst_.y = 0;
    dst_.w = width;
    dst_.h = height;
}
void HUD::render(){
    std::cout << "Rendering HUD" << std::endl;
    SDL_SetRenderTarget(renderer_, texture_);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    m_write(renderer_,"Score: ", dst_.w/2,dst_.h/2);
    SDL_SetRenderTarget(renderer_, NULL);
    SDL_RenderCopy(renderer_, texture_, NULL, &dst_);
}

HUD::~HUD(){
    if(texture_ != NULL)
        SDL_DestroyTexture(texture_);
}