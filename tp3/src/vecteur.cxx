// Vecteur.cpp
#include <iostream>
#include "vecteur.h"
using namespace std;

// Constructeur par défaut
Vecteur::Vecteur() : x(0), y(0), z(0) {}

// Constructeur avec paramètres
Vecteur::Vecteur(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

// Accesseurs
double Vecteur::getX() const { return x; }
double Vecteur::getY() const { return y; }
double Vecteur::getZ() const { return z; }

// Mutateurs
void Vecteur::setX(double val) { x = val; }
void Vecteur::setY(double val) { y = val; }
void Vecteur::setZ(double val) { z = val; }

// Méthode d'affichage
void Vecteur::afficher() const {
    cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

// Surcharge de l'opérateur -
Vecteur Vecteur::operator-(const Vecteur& other) const {
    return Vecteur(x - other.x, y - other.y, z - other.z);
}
double Vecteur::norme2() const {
    return x * x + y * y + z * z;
}
// Méthode membre : Vecteur * scalaire
Vecteur Vecteur::operator*(double scalaire) const {
    return Vecteur(x * scalaire, y * scalaire, z * scalaire);
}
Vecteur Vecteur::operator+(const Vecteur& autre) const {
    return Vecteur(x + autre.x, y + autre.y, z + autre.z);
}
