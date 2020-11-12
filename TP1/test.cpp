/* test.cpp */
// Realise les tests pour verifier que tout va bien

#include "point.hpp"
#include "liste_points.hpp"
#include <cstdlib>
#include <cassert>

void test_point() {
    point p = {3, 6, 7};
    assert(equal(p, {3, 6, 7}));
    assert(!equal(p, {0, 6, 7}));
    assert(!equal(p, {3, 0, 7}));
    assert(!equal(p, {3, 6, 0}));
}

void test_liste_points() {
    liste_points l;
    init(l, 2);
    assert(l.nb_points == 0);
    assert(l.max_points == 2);
    point p1 = {3, 6, 7};
    point p2 = {1, 7, 2};
    point p3 = {9, 8, 5};
    assert(position(l, p1) == -1);
    add(l, p1);
    assert(equal(elt(l, 1), p1));
    add(l, p2);
    add(l, p3);
    assert(l.nb_points == 3);
    assert(l.max_points == 3);
    assert(equal(elt(l, 2), p2));
    assert(position(l, p3) == 3);
    remove(l, 2);
    assert(l.nb_points == 2);
    assert(equal(elt(l, 1), p1));
    assert(equal(elt(l, 2), p3));
    add(l, p1);
    add(l, p1);
    remove(l, p1);
    assert(l.nb_points == 1);
    assert(equal(elt(l, 1), p3));
}

int main() {
    test_point();
    test_liste_points();
    return EXIT_SUCCESS;
}
