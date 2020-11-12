/* point.hpp */

#ifndef POINTS_HPP
#define POINTS_HPP

#include <iostream>

struct point {
    double x, y, z;
};

void print(const point &);
bool equal(const point &p1, const point &p2);

#endif
