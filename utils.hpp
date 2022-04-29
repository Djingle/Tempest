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

/**
 * @brief 
 * 
 * @param x 
 * @param min_x 
 * @param max_x 
 * @param y 
 * @param min_y 
 * @param max_y 
 * @param width 
 * @param height 
 * @return vertex 
 */
vertex v_normalize(float x,float min_x,float max_x,float y, float min_y, float max_y,int width, int height);
/**
 * @brief 
 * 
 * @param obj 
 * @param center 
 * @param scale 
 * @return vertex 
 */
vertex v_homothety(vertex obj, vertex center, float scale);
/**
 * @brief 
 * 
 * @param obj 
 * @param angle 
 * @return vertex 
 */
vertex v_rotate0(vertex obj, float angle);
/**
 * @brief 
 * 
 * @param obj 
 * @param scale 
 * @return vertex 
 */
vertex v_scale0(vertex obj, float scale);
/**
 * @brief 
 * 
 * @param obj 
 * @param center 
 * @param angle 
 * @return vertex 
 */
vertex v_rotate(vertex obj, vertex center, float angle);
/**
 * @brief 
 * 
 * @param obj 
 * @param x 
 * @param y 
 * @return vertex 
 */
vertex v_translate(vertex obj, float x, float y);
/**
 * @brief 
 * 
 * @param v1 
 * @param v2 
 * @return float 
 */
float v_distance(vertex v1, vertex v2);
/**
 * @brief 
 * 
 * @param obj 
 * @param center 
 * @param scale 
 * @return mesh 
 */
mesh m_homothety(mesh obj, vertex center, float scale);
/**
 * @brief 
 * 
 * @param obj 
 * @param angle 
 * @return mesh 
 */
mesh m_rotate0(mesh obj, float angle);
/**
 * @brief 
 * 
 * @param obj 
 * @param center 
 * @param angle 
 * @return mesh 
 */
mesh m_rotate(mesh obj, vertex center, float angle);
/**
 * @brief 
 * 
 * @param obj 
 * @param scale 
 * @return mesh 
 */
mesh m_scale0(mesh obj, float scale);
/**
 * @brief 
 * 
 * @param m 
 * @param x 
 * @param y 
 * @return mesh 
 */
mesh m_translate(mesh m, float x, float y);
/**
 * @brief 
 * 
 * @param m 
 */
void m_print(mesh m);


/**
 * @brief 
 * 
 * @param renderer 
 * @param text 
 * @param x 
 * @param y 
 * @param r 
 * @param g 
 * @param b 
 * @param a 
 */
void m_write(SDL_Renderer* renderer, std::string text, int x, int y, int r, int g, int b, int a);
/**
 * @brief 
 * 
 * @param renderer 
 * @param text 
 * @param x 
 * @param y 
 */
void m_write(SDL_Renderer* renderer, std::string text, int x, int y);
/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return float 
 */
float v_angle(vertex a, vertex b, vertex c);
float vv_angle(vertex v1, vertex v2, vertex v3);


#endif
