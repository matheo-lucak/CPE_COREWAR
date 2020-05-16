/*
** EPITECH PROJECT, 2019
** Vector_engine
** File description:
** defender header file
*/

#ifndef VECTOR_H
#define VECTOR_H

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Rect.h>

#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define ABS(x) ((x > 0) ? (x) : (-x))
#define MAX(a, b) ((a > b) ? (a) : (b))
#define MIN(a, b) ((a < b) ? (a) : (b))

#define RAD(degree) (degree * M_PI / 180)
#define DEG(radian) (radian * 180 / M_PI)

#define VEC2I(x, y) (sfVector2i) {x, y}
#define VEC2F(x, y) (sfVector2f) {x, y}
#define IRECT(a, b, x, y) (sfIntRect) {a, b, x, y}
#define FRECT(a, b, x, y) (sfFloatRect) {a, b, x, y}

//Returns the sum of vec1 and vec2.
sfVector2f vec_add(sfVector2f vec1, sfVector2f vec2);

//Returns the left of vec1 minus vec2.
sfVector2f vec_sub(sfVector2f vec1, sfVector2f vec2);

//Returns the product of vec1 by scalar coeff.
sfVector2f vec_mult(sfVector2f vec1, float coeff);

//Returns the quotient of vec1 by scalar coeff.
sfVector2f vec_div(sfVector2f vec1, float coeff);

sfVector2f vec_comb(sfVector2f vec1, sfVector2f vec2);

//Returns the magnitude of vec1.
float vec_mag(sfVector2f vec1);

//Returns the normalised vector of vec1.
sfVector2f vec_norm(sfVector2f vec1);

//Returns vec1 given as parameter with limited values in x and y.
sfVector2f vec_lim(sfVector2f vec1, sfVector2f top_lim, sfVector2f bottom_lim);

//Returns the right-handed normal of the given vector.
sfVector2f vec_normal(sfVector2f vec1);

//Returns the dot product of 2 vectors
float vec_dot(sfVector2f vec1, sfVector2f vec2);

//Returns the cross product of 2 vectors
float vec_cross(sfVector2f vec1, sfVector2f vec2);

//Returns the angle between 2 given vectors
float vec_angle(sfVector2f vec1, sfVector2f vec2);

#endif
