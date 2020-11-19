/* vecteur_matrice.cpp */

#include "vecteur_matrice.h"
#include <cmath>
#include <cstddef>
#include <iostream>

void vecteur::init(size_t d, double v) {
    dim = d;
    val = new double[d];
    for (size_t i = 0; i < dim; ++i)
	val[i] = v;
}

void vecteur::init(const vecteur& X) {
    dim = X.dim;
    val = new double[X.dim];
    for (size_t i = 0; i < dim; ++i)
	val[i] = X.val[i];
}

void vecteur::clear() {
    delete [] val;
}

void vecteur::print() {
    for (size_t i = 0; i < dim - 1; ++i)
	std::cout << val[i] << ", ";
    std::cout << val[dim - 1];
}

void matrice::init(size_t d, double v) {
    dim = d;
    lignes = new double*[d];
    for (size_t i = 0; i < dim; ++i) {
	lignes[i] = new double[dim];
	for (size_t j = 0; j < dim; ++j)
	    lignes[i][j] = v;
    }
}

void matrice::init(const matrice& M) {
    dim = M.dim;
    lignes = new double*[dim];
    for (size_t i = 0; i < dim; ++i) {
	lignes[i] = new double[dim];
	for (size_t j = 0; j < dim; ++j)
	    lignes[i][j] = M.lignes[i][j];
    }
}
    
void matrice::clear() {
    for (size_t i = 0; i < dim; ++i)
	delete [] lignes[i];
    delete [] lignes;
}

void matrice::print() {
    for (size_t i = 0; i < dim; ++i) {
	for (size_t j = 0; j < dim - 1; ++j)
	    std::cout << lignes[i][j] << " ";
	std::cout << lignes[i][dim - 1] << "\n";
    }
}

matrice hilbert(size_t d) {
    matrice M;
    M.init(d);
    for (size_t i = 0; i < d; ++i) {
	for (size_t j = 0; j < i; ++j)
	    M.lignes[i][j] = M.lignes[j][i] = 1. / (i + j + 1);
	M.lignes[i][i] = 1. / (i + i + 1);
    }
    return M;
}

vecteur produit(matrice& A, vecteur& X) {
    vecteur B;
    size_t d = X.dim;
    B.init(d);
    for (size_t i = 0; i < d; ++i) {
	for (size_t j = 0; j < d; ++j)
	    B.val[i] += A.lignes[i][j] * X.val[j];
    }
    return B;
}

double ps(const vecteur& X, const vecteur& Y) {
    double sum = 0;
    for (size_t i = 0; i < X.dim; ++i)
	sum += X.val[i] * Y.val[i];
    return sum;
}

double norme(const vecteur& X) {
    double sum = 0;
    for (size_t i = 0; i < X.dim; ++i)
	sum += pow(X.val[i], 2);
    return sqrt(sum);
}

double normesup(const vecteur& X) {
    double m = X.val[0];
    for (size_t i = 0; i < X.dim; ++i)
	m = std::max(m, X.val[i]);
    return m;
}

vecteur cl(const vecteur& X, double a, const vecteur& Y, double b) {
    vecteur Z;
    size_t d = X.dim;
    Z.init(X.dim);
    for (size_t i = 0; i < d; ++i)
	Z.val[i] = a * X.val[i] + b * Y.val[i];
    return Z;
}

vecteur gauss(const matrice& A, const vecteur& B, double eps) {
    matrice M;
    vecteur Y;
    
    M.init(A);
    Y.init(B);
    
    size_t r = 0;
    size_t c = 0;
    size_t p;
    double v;
    
    while (r < M.dim && c < M.dim) {
    	p = r;
    	v = M.lignes[p][c];
    	for (size_t i = r; i < M.dim; ++i) {
    	     if (abs(M.lignes[i][r]) > v) {
    	         p = i;
    	         v = abs(M.lignes[i][r]);
    	     }
    	}
        if (abs(M.lignes[p][c]) < eps)
            ++c;
        else {
            // on echange les colonnes de M
            for (size_t j = 0; j < M.dim; ++j) {
                v = M.lignes[r][j];
                M.lignes[r][j] = M.lignes[p][j];
                M.lignes[p][j] = v;
            }
            // on echange aussi dans le vecteur colonne Y
            v = Y.val[r];
            Y.val[r] = Y.val[p];
            Y.val[p] = v;
            
            // On elimine sur les lignes en dessous du pivot
            for (size_t i = r + 1; i < M.dim; ++i) {
                v = M.lignes[i][c] / M.lignes[r][c];
                M.lignes[i][c] = 0;
                for (size_t j = c + 1; j < M.dim; ++j)
                    M.lignes[i][j] -= v * M.lignes[r][j];
                Y.val[i] -= v * Y.val[r];
            }
            ++r;
            ++c;
        }
    }
    return Y;
}






