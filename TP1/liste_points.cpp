/* liste_points.cpp */

#include "point.hpp"
#include "liste_points.hpp"
#include <iostream>
#include <cstdlib>

void init(liste_points &l, int n = 10) {
    l.points = (point*) malloc(n * sizeof(point));
    if (l.points == nullptr) {
	std::cerr << "Failure allocating memory for a liste_points\n";
	exit(EXIT_FAILURE);
    }
    l.nb_points = 0;
    l.max_points = n;
}

void reset(liste_points & l) {
    free(l.points);
}

void resize(liste_points &l, int n) {
    l.points = (point*) realloc(l.points, n * sizeof(point));
    if (l.points == nullptr) {
	std::cerr << "Failure reallocating memory for a liste_points\n";
	exit(EXIT_FAILURE);
    }
    l.nb_points = std::min(n, l.nb_points);
    l.max_points = n;
}

void print(const liste_points &l) {
    for (int i = 0; i < l.nb_points - 1; ++i) {
	print(l.points[i]);
	std::cout << ", ";
    }
    if (l.nb_points != 0)
	print(l.points[l.nb_points - 1]);
}

void add(liste_points &l, const point &p) {
    if (l.nb_points == l.max_points)
	resize(l, l.max_points + 1);
    l.points[l.nb_points] = p;
    l.nb_points++;
}

point& elt(const liste_points &l, int n) {
    return l.points[n-1];
}

int position(const liste_points &l, const point &p) {
    for (int i = 0; i < l.nb_points; ++i) {
	if (equal(l.points[i], p))
	    return i + 1;
    }
    return -1;
}

void remove(liste_points &l, int n) {
    for (int i = n; i < l.nb_points; ++i) {
	l.points[i-1] = l.points[i];
    }
    l.nb_points--;
}

void remove(liste_points &l, const point &p) {
    point *pread = l.points;
    point *pwrite = l.points;
    point *up = l.points + l.nb_points;
    while (pread != up) {
	if (equal(*pread, p)) {
	    l.nb_points--;
	} else {
	    *pwrite = *pread;
	    ++pwrite;
	}
	++pread;
    }
}

void print_state(const liste_points &l) {
    std::cout << "points: ";
    print(l);
    std::cout << "\nnb_points = "
	      << l.nb_points
	      << ", max_points = "
	      << l.max_points << "\n";
}
