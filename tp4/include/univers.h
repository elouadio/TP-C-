#ifndef UNIVERS_H
#define UNIVERS_H

#include <vector>
#include "particule.h"

class Univers {
private:
    int dimension;                      // 1, 2 ou 3
    std::vector<double> longueurs;     // Longueurs caractéristiques (Lx, Ly, Lz)
    double rcut;                        // Rayon de coupure
    double epsilon;                    // Profondeur du potentiel de Lennard-Jones
    double sigma;                      // Distance caractéristique

    std::vector<Particule> particules; // Particules dans l'univers

public:
    // Constructeur
    Univers(int dim, const std::vector<double>& Ld, double r_cut, double eps, double sig);

    // Initialisation régulière des particules
    void initialiserCube(int n);

    // Simulation
    void avancer(double dt, double Tmax);

    // Accès
    std::vector<Particule>& getParticules();
    int getDimension() const;
    double getRcut() const;
    const std::vector<double>& getLongueurs() const;
    double getEpsilon() const;
    double getSigma() const;

    // Affichage
    void afficher() const;
};

#endif
