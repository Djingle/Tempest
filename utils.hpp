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
 * @brief transform x in [min_x, max_x] to [0,width] and y in [min_y, max_y] to [0,height]
 * 
 * @param x 
 * @param min_x 
 * @param max_x 
 * @param y 
 * @param min_y 
 * @param max_y 
 * @param width 
 * @param height 
 * @return vertex with x between 0 and width and y between 0 and height
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
 * @brief calculate the distance between two points
 * 
 * @param v1 first vertex
 * @param v2 second vertex
 * @return distance in float between v1 and v2
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

void m_print(mesh m);

/**
 * @brief write text using hershey font on the screen at position (x,y) with color (r,g,b,a)
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
 * @brief calculate the angle in radians between three points a,b,c
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return angle in float between -pi and pi
 */
float v_angle(vertex a, vertex b, vertex c);
float vv_angle(vertex v1, vertex v2, vertex v3);


#endif
