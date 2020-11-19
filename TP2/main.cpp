/* main.cpp */

#include "vecteur_matrice.h"
#include <cstdlib>


int main() {
    matrice A = hilbert(5);
    vecteur B;
    B.init(5, 2);
    double eps = 10e-6; // a changer plus tard pour une valeur adaptee
    vecteur X = gauss(A, B, eps);
    vecteur Y = produit(A, X);
    Y.print();
    return EXIT_SUCCESS;
}
