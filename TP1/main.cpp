#include "point.hpp"
#include "liste_points.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    point p {1, 2, 3};
    liste_points l;
    init(l, 1);
    add(l, p);
    print_state(l);
    add(l, p);
    add(l, {4, 5, 6});
    add(l, {0, 0, 7});
    print_state(l);
    return EXIT_SUCCESS;
}
