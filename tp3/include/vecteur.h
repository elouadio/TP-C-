#ifndef VECTEUR_H
#define VECTEUR_H

class Vecteur {
private:
    double x, y, z;

public:
    // Constructeurs
    Vecteur();                                // par défaut
    Vecteur(double x_, double y_, double z_); // avec paramètres

    // Accesseurs
    double getX() const;
    double getY() const;
    double getZ() const;

    // Mutateurs
    void setX(double val);
    void setY(double val);
    void setZ(double val);

    // Méthode d'affichage
    void afficher() const;

    // Opérateurs
    Vecteur operator-(const Vecteur& other) const;  // Soustraction
    double norme2() const;
    Vecteur operator*(double scalaire) const;  // Vecteur * scalaire
    Vecteur operator+(const Vecteur& autre) const;
};

#endif
