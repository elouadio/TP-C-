#include "simulate.h"
#include <iostream>
#include <cmath>
#include <vector>

const double dt = 0.01;

using namespace std;

// Force de Lennard-Jones avec coupure
Vecteur compute_LJ_force(const Particule& p1, const Particule& p2, double rcut, double epsilon, double sigma) {
    Vecteur force(0, 0, 0);
    Vecteur r_ij = p2.getPosition() - p1.getPosition();
    double r2 = r_ij.norme2();

    if (r2 == 0.0) return force;

    double r = sqrt(r2);
    if (r > rcut) return force; // Coupure

    double sr6 = pow(sigma / r, 6);
    double coeff = (24 * epsilon / r2) * sr6 * (1 - 2 * sr6);
    force = r_ij * coeff;

    return force;
}

// Calcul de toutes les forces
std::vector<Vecteur> compute_forces(const std::vector<Particule>& particules, double rcut, double epsilon, double sigma) {
    size_t n = particules.size();
    std::vector<Vecteur> forces(n, Vecteur(0, 0, 0));

    for (size_t i = 0; i < n; ++i) {
    for (size_t j = i + 1; j < n; ++j) {
        Vecteur f = compute_LJ_force(particules[i], particules[j], rcut, epsilon, sigma);
        forces[i] = forces[i] + f;
        forces[j] = forces[j] - f; // Action-réaction
        }
    }
    return forces;
}

// Simulation avec Störmer-Verlet
void simulate(std::vector<Particule>& particules, double tmax, double rcut, double epsilon, double sigma) {
    double t = 0.0;
    std::vector<Vecteur> forces = compute_forces(particules, rcut, epsilon, sigma);

    while (t < tmax) {
        t += dt;

        // Étape 1 : mise à jour des positions
        for (size_t i = 0; i < particules.size(); ++i) {
            Vecteur pos = particules[i].getPosition();
            Vecteur vit = particules[i].getVitesse();
            Vecteur f = forces[i];
            double m = particules[i].getMasse();

            pos = pos + vit * dt + (f * (0.5 * dt * dt / m));
            particules[i].setPosition(pos);
        }

        // Étape 2 : recalcul des forces
        std::vector<Vecteur> new_forces = compute_forces(particules, rcut, epsilon, sigma);

        // Étape 3 : mise à jour des vitesses
        for (size_t i = 0; i < particules.size(); ++i) {
            Vecteur vit = particules[i].getVitesse();
            double m = particules[i].getMasse();
            Vecteur avg_force = (forces[i] + new_forces[i]) * 0.5;
            vit = vit + avg_force * (dt / m);
            particules[i].setVitesse(vit);
        }

        // Mise à jour des forces pour la prochaine itération
        forces = new_forces;

        // Affichage de l’état
        std::cout << "Temps: " << t << " s\n";
        for (const auto& p : particules) {
            p.print_particule();
        }
        std::cout << "-----------------------------\n";
    }
}
