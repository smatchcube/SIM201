#include "point.hpp"
#include "liste_points.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    
    point p {4, 5, 6};
    liste_points l;
    init(l, 1);
    print_state(l);
    add(l, {4, 5, 6});
    add(l, p);
    add(l, {0, 0, 7});
    print_state(l);
    std::cout << "Le point p est en position " << position(l, p) << "\n";
    std::cout << "L'element en position 3 est ";
    print(elt(l, 3));
    std::cout << "\n";
    return EXIT_SUCCESS;
}
