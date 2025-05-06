#include "univers.h"
#include <iostream>
#include "simulate.h"
using namespace std;

Univers::Univers(int dim) : dimension(dim), nb_particules(0) {}

void Univers::initialiserCube(int n) {
    particules.clear();
    double step = 1.0 / (n - 1); // espacement régulier
    Vecteur vitesse_uniforme(0.01, 0.01, 0.01);  // même vitesse pour tous
    Vecteur force_nulle(0.0, 0.0, 0.0);
    double masse = 1.0;

    int id = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                Vecteur position(i * step, j * step, k * step);
                particules.emplace_back(id++, "particule", masse, position, vitesse_uniforme, force_nulle);
            }
        }
    }

    nb_particules = particules.size();
}

void Univers::avancer(double dt, double Tmax) {
    std::cout << "Début de la simulation pour t = " << Tmax << " avec dt = " << dt << "\n";
    simulate(particules, Tmax);  // simulation gravitationnelle avec verlet
}

void Univers::afficher() const {
    for (const auto& p : particules) {
        p.print_particule();
    }
}

std::vector<Particule>& Univers::getParticules() {
    return particules;
}
