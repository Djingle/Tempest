#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <SDL.h>

using vertex = std::pair<float, float>;


vertex m_normalize(float x,float min_x,float max_x,float y, float min_y, float max_y,int width, int height);

vertex m_homothety(vertex obj, vertex center, float scale);
void m_write(SDL_Renderer* renderer, std::string text, int x, int y, int r, int g, int b, int a);
void m_write(SDL_Renderer* renderer, std::string text, int x, int y);


#endif