#include "univers.h"
#include "simulate.h"
#include <iostream>

using namespace std;

Univers::Univers(int dim, const std::vector<double>& Ld, double r_cut, double eps, double sig)
    : dimension(dim), longueurs(Ld), rcut(r_cut), epsilon(eps), sigma(sig) {}

void Univers::initialiserCube(int n) {
    particules.clear();
    double masse = 1.0;
    Vecteur vitesse(0.01, 0.01, 0.01);
    Vecteur force(0.0, 0.0, 0.0);
    int id = 0;

    double step_x = (dimension >= 1) ? longueurs[0] / (n - 1) : 0.0;
    double step_y = (dimension >= 2) ? longueurs[1] / (n - 1) : 0.0;
    double step_z = (dimension == 3) ? longueurs[2] / (n - 1) : 0.0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (dimension >= 2 ? n : 1); ++j) {
            for (int k = 0; k < (dimension == 3 ? n : 1); ++k) {
                Vecteur pos(i * step_x, j * step_y, k * step_z);
                particules.emplace_back(id++, "particule", masse, pos, vitesse, force);
            }
        }
    }
}

void Univers::avancer(double dt, double Tmax) {
    cout << "Simulation : Tmax = " << Tmax << ", dt = " << dt
         << ", rcut = " << rcut << ", epsilon = " << epsilon << ", sigma = " << sigma << "\n";
    simulate(particules, Tmax, rcut, epsilon, sigma);
}

void Univers::afficher() const {
    for (const auto& p : particules) {
        p.print_particule();
    }
}

std::vector<Particule>& Univers::getParticules() {
    return particules;
}

int Univers::getDimension() const {
    return dimension;
}

double Univers::getRcut() const {
    return rcut;
}

const std::vector<double>& Univers::getLongueurs() const {
    return longueurs;
}

double Univers::getEpsilon() const {
    return epsilon;
}

double Univers::getSigma() const {
    return sigma;
}
