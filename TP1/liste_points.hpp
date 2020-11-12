/* liste_points.hpp */

#ifndef LISTE_POINTS_HPP
#define LISTE_POINTS_HPP

#include "point.hpp"

struct liste_points {
    point *points;
    int nb_points, max_points;
};

void init(liste_points &, int);
void reset(liste_points &);
void resize(liste_points &, int);
void print(const liste_points &);
void add(liste_points &, const point &);
point& elt(const liste_points &, int);
int position(const liste_points &, const point &);
void remove(liste_points &, int);
void remove(liste_points &, const point &);
void print_state(const liste_points &);

#endif
