/* point.cpp */

#include "point.hpp"
#include <iostream>

void print(const point &p) {
    std::cout << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

bool equal(const point &p1, const point &p2) {
    return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
}

