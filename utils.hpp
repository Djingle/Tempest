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

vertex v_normalize(float x,float min_x,float max_x,float y, float min_y, float max_y,int width, int height);
vertex v_homothety(vertex obj, vertex center, float scale);
vertex v_rotate0(vertex obj, float angle);
vertex v_scale0(vertex obj, float scale);
vertex v_rotate(vertex obj, vertex center, float angle);
vertex v_translate(vertex obj, float x, float y);
float v_distance(vertex v1, vertex v2);

mesh m_homothety(mesh obj, vertex center, float scale);
mesh m_rotate0(mesh obj, float angle);
mesh m_rotate(mesh obj, vertex center, float angle);
mesh m_scale0(mesh obj, float scale);
mesh m_translate(mesh m, float x, float y);
void m_print(mesh m);



void m_write(SDL_Renderer* renderer, std::string text, int x, int y, int r, int g, int b, int a);
void m_write(SDL_Renderer* renderer, std::string text, int x, int y);
float v_angle(vertex a, vertex b, vertex c);


#endif
