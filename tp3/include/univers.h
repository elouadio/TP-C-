#ifndef UNIVERS_H
#define UNIVERS_H

#include <vector>
#include "particule.h"

class Univers {
private:
    int dimension;              // ex: 3
    int nb_particules;          // nombre total
    std::vector<Particule> particules;

public:
    Univers(int dim);  // constructeur

    void initialiserCube(int n);            // Crée (n^3) particules dans le cube [0,1]^3
    void avancer(double dt, double tmax);                // Mise à jour position : pos += vit * dt
    void afficher() const;                  // Affiche les particules

    std::vector<Particule>& getParticules(); // Accès aux particules (optionnel)
};

#endif
