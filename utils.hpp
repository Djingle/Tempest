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
using mesh   = std::vector<vertex>;

vertex v_normalize(float x,float min_x,float max_x,float y, float min_y, float max_y);
vertex v_homothety(vertex obj, vertex center, float scale);

mesh m_homothety(mesh obj, vertex center, float scale);
mesh m_rotate(mesh obj, vertex center, float angle);

float get_angle(vertex a, vertex b, vertex c);

void m_write(SDL_Renderer* renderer, const char* text, int x, int y, int r, int g, int b, int a);
void m_write(SDL_Renderer* renderer, const char* text, int x, int y);


#endif