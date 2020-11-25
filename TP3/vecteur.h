#ifndef VECTEUR_H
#define VECTEUR_H

class vecteur {
private:
	int dim_;
	float * val_;
public:
	vecteur();
	vecteur(int, float x=0);
	vecteur(const vecteur &);
	void operator=(const vecteur &);
	~vecteur();
	int dim() const;
	bool check_dim(const vecteur &);
	float & val(int);
	void print(const vecteur &) const;
};

vecteur somme(const vecteur &, const vecteur &);
vecteur diff(const vecteur &, const vecteur &);
vecteur produit(float, const vecteur &);
float produit_scalaire(const vecteur &, const  vecteur &);
float norme(const vecteur &);

#endif
