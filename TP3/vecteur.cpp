#include <iostream>
#include "vecteur.h"

vecteur::vecteur() {
    dim_ = 0;
    val_ = nullptr;
}


vecteur::vecteur(int d, float x) {
    dim_ = d;
    val_ = new float[d];
    for (int i = 0; i < d; ++i)
	val_[i] = x;
}

vecteur::vecteur(const vecteur & v) {
    dim_ = v.dim_;
    val_ = new float[dim_];
    for (int i = 0; i < dim_; ++i)
	val_[i] = v.val_[i];
}

void vecteur::operator=(const vecteur & v) {
    dim_ = v.dim_;
    delete [] val_;
    val_ = new float [dim_];
    for (int i = 0; i < dim_; ++i)
	val_[i] = v.val_[i];
}

vecteur::~vecteur() {
    delete val_;
}

int vecteur::dim() const {
    return dim_;
}

bool vecteur::check_dim(const vecteur & v) {
    return dim_ == v.dim_;
}

float & vecteur::val(int i) {
    return val_[i-1];
}

void vecteur::print(const vecteur & v) const {
    for (int i = 0; i < v.dim() - 1; ++i)
	std::cout << v.val_[i] << ", ";
    std::cout << v.val_[v.dim() - 1];
}


vecteur somme(const vecteur & u, const vecteur & v) {
    vecteur w = u;
    for (int i = 0; i < w.dim(); ++i)
	w.val(i) += v.val(i);
    return w;
}

vecteur diff(const vecteur & u, const vecteur & v) {
    vecteur w = u;
    for (int i = 1; i <= w.dim(); ++i)
	w.val(i) -= v.val(i);
    return w;
}

vecteur produit(float a, const vecteur & u) {
    vecteur v = u;
    for (int i = 1; i <= v.dim(); ++i)
	v.val(i) *= a;
    return v;
}

float produit_scalaire(const vecteur &, const  vecteur &);
float norme(const vecteur &);
