#ifndef PARTICULE_H
#define PARTICULE_H

#include <string>
#include "vecteur.h"  // ⚠️ Inclure la classe Vecteur

class Particule {
private:
    int id;
    std::string categorie;
    double masse;
    Vecteur position;
    Vecteur vitesse;
    Vecteur force;

public:
    // Constructeur
    Particule(int identifiant,
              const std::string& cat,
              double m,
              const Vecteur& pos,
              const Vecteur& vit,
              const Vecteur& frc);

    // Accesseurs
    int getId() const;
    std::string getCategorie() const;
    double getMasse() const;
    Vecteur getPosition() const;
    Vecteur getVitesse() const;
    Vecteur getForce() const;

    // Mutateurs
    void setPosition(const Vecteur& pos);
    void setVitesse(const Vecteur& vit);
    void setForce(const Vecteur& frc);
    void setId(int newId);

    void print_particule() const;
};

#endif
