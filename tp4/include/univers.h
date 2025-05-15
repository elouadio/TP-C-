#ifndef UNIVERS_H
#define UNIVERS_H

#include <vector>
#include "vecteur.h"
#include "particule.h"

struct Cellule {
    std::vector<Particule*> particules;
};

class Univers {
public:
    Univers(int dim, const std::vector<double>& Ld, double r_cut, double eps, double sig);

    void initialiserCube(int n);
    void initialiserMaillage();
    void afficher() const;

    // 🔹 Nouvelle méthode pour mettre à jour le maillage
    void mettreAJourMaillage();

    // Accesseurs
    const std::vector<Particule>& getParticules() const;
    std::vector<Particule>& getParticules();
    int getDimension() const;
    double getRcut() const;
    const std::vector<double>& getLongueurs() const;
    double getEpsilon() const;
    double getSigma() const;
    const std::vector<std::vector<std::vector<Cellule>>>& getGrille() const;

    int getNcdX() const;
    int getNcdY() const;
    int getNcdZ() const;
    double getLongueur(int index) const;

private:
    int dimension;
    std::vector<double> longueurs;
    double rcut, epsilon, sigma;
    std::vector<Particule> particules;
    std::vector<std::vector<std::vector<Cellule>>> grille;
    int ncd_x, ncd_y, ncd_z;
};

#endif // UNIVERS_H
