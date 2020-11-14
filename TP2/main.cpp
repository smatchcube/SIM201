/* main.cpp */

#include "vecteur_matrice.h"
#include <cstdlib>


int main() {
    matrice H = hilbert(4);
    H.print();
    return EXIT_SUCCESS;
}
