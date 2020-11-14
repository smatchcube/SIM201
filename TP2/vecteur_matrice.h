/* vecteur_matrice.h */

#ifndef VECTEUR_MATRICE_H
#define VECTEUR_MATRICE_H

#include <cstddef>

struct vecteur {
	size_t dim;
	double * val;

	void init(size_t d, double v = 0);
	void init(const vecteur&);
	void clear();
	void print();
};

struct matrice {
	size_t dim;
	double ** lignes;

	void init(size_t d, double v = 0);
	void init(const matrice&);
	void clear();
	void print();
};

matrice hilbert(size_t d);
vecteur produit(matrice& A, vecteur& X);
double ps(const vecteur& X, const vecteur& Y);
double norme(const vecteur& X);
double normesup(const vecteur& X);
vecteur cl(const vecteur& X, double a, const vecteur& Y, double b);
vecteur gauss(const matrice& A, const vecteur& B, double eps);

#endif
